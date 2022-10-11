#include<errno.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// for finding roots
void find_solutions(double, double, double);


// double input and convertion
void enter_nums(void );
double read_double(char* );
int str_to_double(char buf[], double *a);

// error sections
void print_error(char* );
void check_err(int );

int main(int argc, char** argv) 
{
	int err;
	double a, b, c;

	check_err(str_to_double(argv[1], &a));
	check_err(str_to_double(argv[2], &b));
	check_err(str_to_double(argv[3], &c));

	printf("Your equation: \n");
	printf("%.2lf*x^2 + %.2lf*x + %.2lf = 0\n\n", a, b, c);	
	find_solutions(a, b, c);


	// for debugging input
	// find_discriminant();

	return 0;
}

void enter_nums(void )
{	

	printf("Find equation:\n");
	printf("a*x^2 + b * x + 4 * c\n");

	// reading safely double values
	double a = read_double("\nEnter a:\n> "); 
	double b = read_double("\nEnter b:\n> ");
	double c = read_double("\nEnter c:\n> ");

	find_solutions(a, b, c);
}

void find_solutions(double a, double b, double c) 
{

	double sol1, sol2;
	double real, imag;
	
	// calculating  discriminant
	double discriminant = b * b - 4 * a * c;
	
	printf("\nThe roots of your equation:\n");
	if (discriminant < 0)
	{
		real = -b / (2 * a);
	        imag = sqrt(-discriminant) / (2 * a);
		 printf("Solution1 = %.2lf+%.2lfi. Solution2 = %.2f-%.2fi.", real, imag, real, imag);
	}
	else if (discriminant == 0) 
	{
		sol1 = sol2 = -b / (2 * a);
		printf("The only one solution is %.2lf.", sol1);
	}
	else
	{
		sol1 = (-b + sqrt(discriminant)) / (2 * a);
	        sol2 = (-b - sqrt(discriminant)) / (2 * a);
	        printf("Solution1 = %.2lf. Solution2 = %.2lf.", sol1, sol2);
	}
	printf("\n");
}

double read_double(char* msg) 
{
	char buf[1024];
	double a;
	int success = 0;
	do
	{
		printf("%s", msg);

		if (!fgets(buf, 1024, stdin)) 
		{
			print_error("Reading input failed.");
			continue;
		}
		buf[strcspn(buf, "\n")] = 0;

		if (str_to_double(buf, &a) == 1) {
			continue;
		}

		success = 1;

	} while (success == 0);

	return a;
}

void print_error(char* msg){
	printf("[ERROR] %s Try again.\n", msg);
}

int str_to_double(char buf[], double *a) {
	int success = 0;
	do{
		char* err;
		*a = strtod(buf, &err);
		if (*err != '\0')
		{
			print_error("That's not a double num. Check input.");
			return 1;
		}
		success = 1;
	} while (success == 0);

	return 0;	
}

void check_err(int err) {
	if (err == 1) {
		print_error("Something gone wrong. You've enterred somehow wrong arguments");
		exit(1);
	}
}
