#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf( stderr, "You need 2 arguments!\n");
        exit(1);
    }

    int thread_amount = atoi(argv[0]);


}