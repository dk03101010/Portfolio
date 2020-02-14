
/*
* Program 2:
* Author: Dillon Kern
*
* Professor: Dr. Xiao Chen
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    int pipe_fd[2];
    pid_t pid;


    if (pipe(pipe_fd) == -1)
    {
        perror("\nError with pipe");
        exit(1);
    }pid = fork();
    if (pid == 0)
    {
        close(1);
        dup(pipe_fd[1]);
        close(pipe_fd[1]);
        close(pipe_fd[0]);
        execl("./pre", "pre", NULL);
    }
    else if (pid > 0)
    {
        close(0);
        dup(pipe_fd[0]);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        execl("./sort", "sort", NULL);
    }
    else
    {
        perror("\n Fork failed: check README");
        exit(2);
    }
    return (0);
}
