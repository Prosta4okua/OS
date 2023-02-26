#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "race.h"


int main(void) {
    long num, res;
    int i = 10;

    printf("Task 1. New Race Program\n");
    printf("Max long value: %ld\n", LONG_MAX);
    do {
        printf("Input n (n > 0): ");
        scanf("%ld", &num);
    } while(num <= 0);

    printf("\n");
    for(i = 0; i < 10; i++) {
        res = race_result(num);
        printf("%d). After %ld pair operations (+,-) the result is: %ld\n", i, num, res);
    }

    return EXIT_SUCCESS;
}