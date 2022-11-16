#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

static char *sub_process_name = "./test";

int main(int argc, char *argv[])
{
    pid_t process;
    process = fork();

    if (process < 0)
    {
        // fork() failed.
        perror("fork");
        return 2;
    }

    if (process == 0)
    {
        // sub-process
        argv[0] = sub_process_name; // Just need to change where argv[0] points to.
        execv(argv[0], argv);
        perror("execv"); // Ne need to check execv() return value. If it returns, you know it failed.
        return 2;
    }

    int status;
    pid_t wait_result;

    while ((wait_result = wait(&status)) != -1)
    {
        printf("Process %lu returned result: %d\n", (unsigned long) wait_result, status);
    }

    printf("All children have finished.\n");
    return 0;
}