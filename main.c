#define _GNU_SOURCE

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>

extern char **environ;

int main(int argc, char *argv[], char *envp[]) {
    /* task4
    for (int i = 0; envp[i] != NULL; i++)
    {
        printf("\n%s", envp[i]);
    }
    getchar();
    */

    /* task5
    if (getenv(argv[1]) != NULL)
    {
        printf("%s : %s", argv[1], getenv(argv[1]));
    }
    else
        printf("This env var doesn't exist\n");
        */
// task 6
//    char *arg1 = malloc(1024), *arg2 = malloc(1024);
//
//    if (argc < 3 || argc > 3) {
//        printf("Usage: ./main ENV_VAR ENV_VAR_VALUE");
//        return 0;
//    }
//    printf("test");
//    strcpy(arg1, argv[1]);
//    printf("test");
//    strcpy(arg2, argv[2]);
//    printf("test");
//    setenv(arg1, arg2, 1);
//    printf("\nADDED NEW ENV VAR. %s %s\n\n", arg1, getenv(arg1));


    // task7
//    for (int i = 0; environ[i]; i++)
//        printf("  environ[%d]: %p (%s)\n", i, environ[i], environ[i]);
//    if (unsetenv(argv[1]) == 0)
//        printf("You've deleted %s ", argv[1]);
//    else
//        printf("Error");

    // task9
    printf("\nInfo about computer:\n");
    int id = gethostid();
    printf("\t\tID: %d\n", id);
    struct utsname utsbuf;

    if (uname(&utsbuf) != 0) {
        printf("Error. Something is wrong");
        return 1;
    }
    printf("\t\tSystem name: %s\n", utsbuf.sysname);
    printf("\t\tComputer name: %s\n", utsbuf.nodename);
    printf("\t\tRelease version: %s\n", utsbuf.release);
    printf("\t\tSystem version: %s\n", utsbuf.version);
    printf("\t\tMachine: %s\n\n", utsbuf.machine);

    return 0;
}
