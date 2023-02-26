#ifndef MY_THREADS_
#define MY_THREADS_

typedef struct arg_str {
	int n;
	double a, b, eps;
	double (*f)(double);
} TARG;

double Thread_NIntegrate(const TARG * arg);

#endif