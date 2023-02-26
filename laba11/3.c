#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <wait.h>




void check_if_error(int result, char *err);

int main (void) {

}

void check_if_error(int result, char *err) {
    if (result != 0) {
        perror("Something is wrong. Maybe your life?\t");
        perror("Error occurred during");
        perror(err);
        exit(EXIT_FAILURE);
    }
}
//

//
//void* child_func(void* args) {
//    int ppid = getppid();
//    sigset_t   set;
//    while(1) {
//        printf("Очікування...");
//        if(sigwait(&set) != SIGUSR1) {
//            perror("Sigwait error");
//            pthread_exit((void *)2);
//        }
//        kill(ppid, SIGUSR1);
//        sleep(1);
//    }
//}
//
//// Usage:   ./3
//int main(void ) {
//
//
//    pthread_t thread;
//    int result = pthread_create(&thread, NULL, &child_func, NULL);
//    if (result != 0) {
//        fprintf(stderr, "Error\n");
//        return 1;
//    }
//
//    while (1) {
//        sigset_t   set;
//        printf("батьківський процес");
//        sleep(1);
//        kill(thread, SIGUSR1);
//        if(sigwait(&set) != SIGUSR1) {
//            perror("Sigwait error");
//            pthread_exit((void *)2);
//        }
//    }
//
//    if (pthread_join(thread, NULL) != 0) {
//        fprintf(stderr, "Join error\n");
//        return 1;
//    }
//
//    return 0;
//}


char* message1 = "ХЕХЕ";
char* message2 = "НОТ ХЕХЕ";

void handle_sigusr1 (int sig) {
    printf("Hehe");
}
int main (void) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        // child process
        while(1) {
            sleep(5);
            printf("%s", message1);
            kill(getppid(), SIGUSR1);
        }
    } else {
        // Parent process
        while(1) {
            struct sigaction sa = {0};
//        sa.sa_flags = SA_RESTART;
            sa.sa_handler = &handle_sigusr1;
            printf("%s", message2);
            sigaction(SIGUSR1, &sa, NULL);

            wait(NULL);
        }
    }
}