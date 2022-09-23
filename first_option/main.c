#include<math.h>
#include<stdio.h>
#include<stdlib.h>

double f(double x) {
        return exp(-1 * fabs(x)) * sin(x);
}

double g(double x) {
	return exp(-1 * fabs(x)) * cos(x);
}

int main(){
        // Отримайте від користувача значення змінної x
        // Обчисліть значення таких функцій:
                // 1. f(x)=exp(−∣x∣)sin(x)
                // 2. g(x)=exp(−∣x∣)cos(x)
        double x;

        printf("Enter the number: ");
        scanf("%lf", &x);

	printf("f(%lf) = %.5lf\n", x, f(x));
	printf("g(%lf) = %.5lf\n\n", x, g(x));

        return 0;
}
