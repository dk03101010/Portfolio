/**
NAME: Dillon Kern
Serial Number: 16
CS 4350 – 251 -‐- Unix Systems Programming
Assignment Number: 5
Due Date: 4/20/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/utsname.h>

//helper function to accesstime format date
char* formatdate(char* str, time_t val)
{
    strftime(str, 36, "%m.%d.%Y %H:%M:%S", localtime(&val));
    return str;
}
//helper function to get current time.
void getTime(){
    char buffer[30];
    struct timeval tv;
    time_t curTime;

    gettimeofday(&tv, NULL);
    curTime=tv.tv_sec;
    strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curTime));
    printf("%s%ld\n",buffer,tv.tv_usec);
}
int main() {
    FILE *fp;
    pid_t process_id;
    pid_t p_process_id;
    char hostBuf[256], date[36], newName[] = "zp5in-2.txt";
    char filename[12] = "zp5in.txt";
    struct timeval tv;
    struct stat stat_result,sb,dev, fi, hardLk,
            group, user, blk, fileStat,attr;
    struct utsname unameData;
    int which = PRIO_PROCESS;
    int ret, locHostname,c, status;
    id_t pid;

    //create zp5in.txt
    system("touch zp5in.txt");

    //check if file was created
    if( access(filename, F_OK ) != -1 )
        printf("1. File is created.\n");
    else
        printf("1. File was not created.\n");

    //append contents to output  file
    fp = fopen(filename, "w+");
    fputs("Texas State University, Spring 2020, Unix Programming", fp);
        printf("2. Text is appended to the file.\n");
        //close file
        fclose(fp);
        printf( "3. File is closed.\n" );

    printf("4. Current date is : ");
    getTime();

    //file accessed last
    stat(filename, &attr);
    printf("5. Time of last file access : %s", ctime(&attr.st_mtime));

    //displaying contents of zp5in.txt
    fp = fopen(filename, "r");
    printf("6. The content of the file is : \n");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
    //change file mode for user and groups
    chmod(filename, S_IRWXU| S_IRWXG |S_IRWXO);
    printf("\n7. File mode is changed\n");

    printf("8. File information is : \n");
    fflush(stdout);
    system("stat zp5in.txt");

    //get system name
    uname(&unameData);
    printf("9. System name: ");
    printf("%s\n", unameData.sysname);

    locHostname = gethostname(hostBuf, sizeof(hostBuf));
    if (locHostname == -1) {
        perror("gethostname error");
        exit(1);
    }
    printf("10.\tLocal host name : %s\n", hostBuf);

    printf("11.\tHost name: %s\n", hostBuf);

    process_id = getpid();
    p_process_id = getppid();
    printf("12.\tThe process id : %d\n", process_id);
    printf("13.\tThe parent process id is: %d\n", p_process_id);

    pid = getpid();
    ret = getpriority(which, pid);
    printf("14.\t Priority level of the process :  %d\n", ret);

    //Getting all of the .txt file information below.
    printf("15.\tThe file name is : %s\n", filename);
    stat(filename, &dev);
    printf("16.\tThe Device is : %u\n", dev.st_dev);
    if (stat(filename, &sb) == -1)
        return 1;
    printf("17.\tThe inode:  %lu\n", sb.st_ino);

    //print file permissions in ls -l format
    if(stat(filename,&fileStat) < 0)
        return 1;
    printf("18.\tThe file protection: ");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    //number of hardlinks
    stat(filename,&hardLk);
    printf("19.\tNumber of hard links : %hu\n", hardLk.st_nlink);
    stat(filename,&user);
    printf("20.\tOwner's user ID : %u\n", user.st_uid);
    stat(filename,&group);
    printf("21.\tOwner's group ID : %u\n", group.st_uid);
    printf("22.\tOwner's effective user ID : %d\n", (int) geteuid());
    if (stat(filename, &stat_result) == -1)
        return 1;
    printf("23.\tSize of %s file : %ld bytes\n", filename, stat_result.st_size);
    if(stat(filename, &fi))
        return 1;
    printf("24.\tBlock Size of %s file : %d block(s)\n", filename, fi.st_blksize);
    if(stat(filename, &blk))
        return 1;
    printf("25.\tNumber of blocks allocated to %s file: %lu block(s)\n", filename, blk.st_blocks);
    fflush(stdout);
    //append again
    fp = fopen(filename, "a+");
    fputs("\nFinal Step.", fp);
    fclose(fp);
    printf("26.\tNew text is appended to zp5in.txt file.\n");
    //Display txt file again using system.
    printf("27.\tRedisplaying the content of %s file:\n", filename);
    system("cat zp5in.txt");

    //display last file access
    stat(filename, &attr);
    printf("\n28.\tThe time of last access of %s file : %s",filename, ctime(&attr.st_mtime));

    //rename file
    ret = rename(filename, newName);
    if(ret == 0)
        printf("29.\tRenamed The file to be zp5in-2.txt .\n");
    else
        printf("29.\tError: unable to rename the file\n");

    printf("30.\tThe content of the new zp5in-2.txt file :\n");
    system("cat zp5in-2.txt");

    printf("\n31.\tCurrent date and time : ");
    getTime();

    //Delete the File from current directory
    status = remove(newName);
    if(status==0)
        printf("32.\tRemoved %s  files from current Directory.\n", newName);
    else{
        printf("32.\tUnable to remove %s", newName);
    }
    //Display after deletion
    printf("33.\tDisplaying the content of zp5in-2.txt  file.\n");
    fflush(stdout);
    system("cat zp5in-2.txt");

    printf("\nImplemented by Dillon Kern\n");
    printf("April - 2020\n");

    return 0;
}
