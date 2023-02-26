#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

typedef struct toThread {
    int seconds;
    char* msg;
}ThreadData;

ThreadData data;

void sign_alarm(int signum) {
    printf("Your Message: %s\n", data.msg);
}

void* child_func(void* args) {
    signal(SIGALRM, sign_alarm);
    printf("I will start alarm in %d seconds\n", data.seconds);
    alarm(data.seconds);
    return 0;

}

// Usage:   ./2 num_of_sec string_message_in_quotes
// Example: ./2 10 "WOW is World of Warcraft"
int main(int argc, char *argv[]) {

//    ThreadData data;
    if (argc == 1) {
        data.seconds = 2;
        data.msg = "Так, це повний хехе!";
        printf("1 arg detected\n");
    } else if (argc != 3) {
        printf("Вам необхідно ввести 2 аргументи!");
    } else {
        data.seconds = atoi(argv[1]);
        data.msg = argv[2];
    }

    pthread_t thread;
    int result = pthread_create(&thread, NULL, &child_func, NULL);
    if (result != 0) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    sleep(data.seconds + 2);

    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Join error\n");
        return 1;
    }
    return 0;
}