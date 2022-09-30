#include<math.h>
#include<stdio.h>
#include<time.h>

void task1(float [], int );
void task2(float [], int );


int main() {
	int n;
	
	printf("Enter the size of array:\t");
	scanf("%d", &n);

	if (n < 1)
		return 1;

	srand(time(NULL));

	float a[n];

	printf("Array: ");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 - 50;
		printf("%.2f ", a[i]);
	}
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	task1(a, n);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	task2(a, n);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void task1(float a[], int n) {
	float sum;
	float avg;
	for (int i = 0; i < n; i++) {
		sum += a[i];

	}
	printf("\nSum: %f\n", sum);
	avg = sum / ((float) n);
	
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > avg)
			counter++;
	}

	printf("Average %.5f\n", avg);
	printf("The amount of numbers bigger than average: %d\n\n", counter);

}


void task2(float a[], int n) {
	int index_neg = -1;
	float sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			index_neg = i;
		}
		if (index_neg != 0) {
			sum += fabs(a[i]);
		}

	}	

	if (index_neg == -1) {
		printf("\n\nArray doesn't have negative numbers");
		return;
	}

	printf("Index of the first negative number: %d\n", index_neg);
	printf("The first negative number: %.2f\n", a[index_neg]);
	printf("The sum after first negative number: %f\n\n", sum);
}
