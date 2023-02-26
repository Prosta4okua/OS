#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "race.h"

typedef struct {
	long res;
	long num;
} ARG;

static void * incr(void * arg) {
	long i, num = ((ARG*)arg)->num;
#ifdef DEBUG
	printf("\tIncrement thread created: %ld + operations\n", num);
#endif
	for (i = 0; i < num; i++) ((ARG*)arg)->res += 1;
	return NULL;
}

static void * decr(void * arg) {
	long i, num = ((ARG*)arg)->num;
#ifdef DEBUG
	printf("\tDecrement thread created: %ld - operations\n", num);
#endif
	for (i = 0; i < num; i++) ((ARG*)arg)->res -= 1;
	return NULL;
}

long race_result(long num) {
	ARG arg = {0, num};
	pthread_t id1, id2;
	
	if (pthread_create(&id1, NULL, incr, (void*)&arg)) {
		fprintf(stderr, "ERROR!!! %s\n", "Cannot create working thread");
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&id2, NULL, decr, (void*)&arg)) {
		fprintf(stderr, "ERROR!!! %s\n", "Cannot create working thread");
		exit(EXIT_FAILURE);
	}
	
	if (pthread_join(id1, NULL)) {
		fprintf(stderr, "ERROR!!! %s\n", "Cannot join to working thread");
		exit(EXIT_FAILURE);
	}
	if (pthread_join(id2, NULL)) {
		fprintf(stderr, "ERROR!!! %s\n", "Cannot join to working thread");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("\tIncrement and decrement threads are finished!\n");
#endif
	
	return arg.res;
}