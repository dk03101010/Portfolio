#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int spawn (int in, int out, char * argv[]){
  pid_t pid;

  if((pid = fork()) == 0){

      if (in != 0){
        dup2(in,0);
        close(in);
      }

      if(out != 1){
        dup2(out, 1);
        close(out);
      }


      return execvp(argv[0], argv);
    }
  wait(NULL);
  return pid;
}

int forkP (int n, char * argv[])
{
  int i, j = 0, k = 0, l = 0;
  pid_t pid;
  int in, fd [2];
  char *newArgv[20];
  int savedOut = dup(1);
  int savedIn = dup(0);
  int readP = 0, writeP = 0;
  char * readPtr;
  char * writePtr;
  int fileD[2];

  in = 0;

  //Child processes
  for (i = 0; i < n; ++i)
    {
      //Copy next command to newArgv
      while ( strcmp(argv[j],"|")){
        newArgv[k] = argv[j];

        //If newArgv != NULL
        if(newArgv[k])	
          //Output redir
	  if ( !strcmp(newArgv[k],">") ){
	    writeP = 1;
	    newArgv[k] = NULL;
	    writePtr = argv[j+1];
	  }
          //Input redir
	  else if ( !strcmp(newArgv[k],"<")){
	    readP = 1;
	    newArgv[k] = NULL;
	    readPtr = argv[j+1];
	  }
        ++k;
        ++j;
      }

      //Null terminate
      newArgv[k] = (char *)NULL;

      pipe (fd);

      //If I and O redir
      if(writeP && readP){
        fileD[0] = open(readPtr, O_RDWR);
        fileD[1] = open(writePtr, O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);
        spawn(fileD[0], fileD[1], newArgv);
      }
      //If O redir
      else if(writeP){
        fileD[1] = open(writePtr, O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);
        spawn(in, fileD[1], newArgv);
      }
      //If I redir
      else if(readP){
        fileD[0] = open(readPtr, O_RDWR);
        spawn(fileD[0], fd[1], newArgv);
      }
      //No redir
      else spawn(in, fd [1], newArgv);

      //Close write end of pipe
      close (fd [1]);

      //Keep read end of pipe
      in = fd [0];

      ++j;
      k = 0;
      readP = 0;
      writeP = 0;
    }

    //Final process
    if (in != 0)
      dup2(in, 0);
    
    k = 0;

    //Copy last argument to newArgv
    do{
      newArgv[k] = argv[j];

      //Look for IO redir
      if(newArgv[k]){
        if ( !strcmp(newArgv[k],">") ){
          writeP = 1;
          newArgv[k] = NULL;
          writePtr = argv[j+1];
        }
        else if ( !strcmp(newArgv[k],"<")){
          readP = 1;
          newArgv[k] = NULL;
          readPtr = argv[j-1];
        }
      }
      ++j;
      ++k;
    }while( newArgv[k-1] != NULL);

  if (in != 0)
    dup2 (in, 0);

  if(writeP){
    fileD[1] = open(writePtr, O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);
    dup2(fileD[1], 1);

  }
  if(readP){
    fileD[0] = open(readPtr, O_RDWR);
    dup2(fileD[0], 0);
  }
  // Last process
  if(fork() == 0){

      execvp( newArgv[0], newArgv );
      printf("Didn't exec newArgv[0]: %s\n", newArgv[0]);

  }

  wait(NULL);

  close(fileD[0]);
  close(fileD[1]);

  //Reset stdin and stdout
  dup2(savedOut, 1);
  close(savedOut);
  dup2(savedIn, 0);
  close(savedIn);

  return 1;
}

int main(){
  int k = 0;
  pid_t pid;
  int in, fd[2];
  in = 0;
  char *path, *argv[20], buf[80], n, *p;
  int m, status, inword, continu, numPipes;

  while(1) {

    inword = 0;
    p = buf;
    m = 0;
    continu=0;
    numPipes = 0;

    printf( "\nshhh> ");

    while ( ( n = getchar() ) != '\n'  || continu ) {
      if (n == '|') numPipes++;
      if ( n ==  ' ' ) { 
	if ( inword ) {
	  inword = 0;
	  *p++ = 0;
	} 
      }
      else if ( n == '\n' ) continu = 0;
      else if ( n == '\\' && !inword ) continu = 1;
      else {
	if ( !inword ) {
	  inword = 1;
	  argv[m++] = p;
	  *p++ = n;
	}
	else 
	  *p++ = n;
      }

    }	
    
    *p++ = 0;
    argv[m] = 0;

    if ( strcmp(argv[0],"exit") == 0 ) exit(0);

    //Process argv
    forkP(numPipes, argv);
  }
  return 0;
}

