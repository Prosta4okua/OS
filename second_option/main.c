#include "func_f.h"
#include "func_g.h"
#include<stdio.h>

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
