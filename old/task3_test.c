#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>

#include <unistd.h>
#include <sched.h>

#include <sys/wait.h>

pid_t parent_pid;
char msg[256];

void sigquit_handler (int sig) {
    // якщо assert(щось) тру, то нічого, якщо фолз, то виводить помилку
    assert(sig == SIGQUIT);
    // отримуємо айді процесу, що не виконується
    pid_t self = getpid();
    if (parent_pid != self) {
        write(1, msg, strlen(msg));
        _exit(0);
    }
}

int main ()
{
    // індекс
    int i;
    // масив для зберігання айдішників процесів
    pid_t child_pid[5];

    // SIGQUIT - Сигнал для виходу з процесу
    // sigquit_handler - функція
    signal(SIGQUIT, sigquit_handler);
    // зберігаємо айді бАтьківскього процесу
    parent_pid = getpid();


    puts("launching children");
    fflush(stdout);

    for (i = 0; i < 5; ++i) {
        pid_t p = fork();
        switch (p) {
            case 0:
                snprintf(msg, sizeof(msg), "%d exiting\n", (int)getpid());
                printf("child running: %d\n", (int)getpid());
                fflush(stdout);
                sleep(30);
                abort();
            case -1:
                perror("fork");
                abort();
            default:
                child_pid[i] = p;
                break;
        }
    }

    puts("sleeping 1 second");
    sleep(1);

    puts("killing children");
    kill(0, SIGQUIT);
    for (i = 0; i < 5; ++i) {
        int status;
        for (;;) {
            pid_t child = wait(&status);
            if (child > 0 && WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                printf("child %d succesully quit\n", (int)child);
            } else if (child < 0 && errno == EINTR) {
                continue;
            } else {
                perror("wait");
                abort();
            }
            break;
        }
    }

    puts("sleeping 5 seconds");
    sleep(5);

    puts("done");
    return 0;
}