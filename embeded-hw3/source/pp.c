#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*Direct polynomial evaluation*/
double poly(double a[], double x, int degree)
{
	long int i;
	double result = a[0];
	double xpwr = x;
	for (i = 1; i <= degree; i++)
	{
		result += a[i] * xpwr;
		xpwr = x * xpwr;
	}
	return result;
}

/*Direct polynomial evaluation*/
double op_poly(double a[], double x, int degree)
{
	int i;
	int limit = degree - 1;
	double result1 = a[0];
	double result2 = 0;
	double xpwr1 = x;
	double xpwr2 = x * x;
	for (i = 1; i <= limit; i += 2)
	{
		result1 += a[i] * xpwr1;
		xpwr1 = x * x * xpwr1;

		result2 += a[i + 1] * xpwr2;
		xpwr2 = x * x * xpwr2;
	}

	for (; i <= degree; i++)
	{
		result1 += a[i] * xpwr1;
		xpwr1 = x * x * xpwr1;
	}
	return result1 + result2;
}

/*Horner's method for polynomial evaluation*/
double horner_poly(double a[], double x, int degree)
{
	long int i;
	double result = a[degree];
	for (i = degree - 1; i >= 0; i--)
		result = a[i] + (x * result);
	return result;
}

/*Horner's method for polynomial evaluation*/
double op_horner_poly(double a[], double x, int degree)
{
	int i = degree - 1;
	double result = a[degree];
	for (; i >= 2; i -= 2)
	{
		result = a[i] + (x * result);
		result = a[i - 1] + (x * result);
	}
	for (; i >= 0; i--)
	{
		result = a[i] + (x * result);
	}
	return result;
}

/*Combined for polynomial evaluation*/
double combined(double a[], double x, int degree)
{
	long int i;
	double result = a[0];
	double xpwr = x;
	for (i = 1; i <= degree - 1; i += 2)
	{
		result += xpwr * (a[i] + (a[i + 1] * x));
		xpwr = x * x * xpwr;
	}
	for (; i <= degree; i++)
	{
		result += xpwr * (a[i]);
		xpwr = x * xpwr;
	}
	return result;
}

/*Combined for polynomial evaluation*/
double op_combined(double a[], double x, int degree)
{
	int i;
	int limit = degree - 1;
	double result = a[0];
	double xpwr = x;
	for (i = 1; i <= limit; i += 2)
	{
		result += xpwr * (a[i] + (a[i + 1] * x));
		xpwr = x * x * xpwr;
	}
	for (; i <= degree; i++)
	{
		result += xpwr * (a[i]);
		xpwr = x * xpwr;
	}
	return result;
}

void main()
{
	int size = 1000;
	double a[1000] = {0.0};
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 1000; i++)
	{
		a[i] = ((double)rand() / (double)(RAND_MAX));
		//printf("%f\n", a[i]);
	}

	int deg = 10;
	printf("%f\n", combined(a, 2, deg));
	printf("%f\n", op_combined(a, 2, deg));
	printf("%f\n", poly(a, 2, deg));
	printf("%f\n", op_poly(a, 2, deg));
	printf("%f\n", horner_poly(a, 2, deg));
	printf("%f\n", op_horner_poly(a, 2, deg));

	clock_t time;

	time = clock();					  //starts time
	for (int i = 0; i < 1000000; i++) //call multiple times to get significant values
		//poly(a,2,999);
		combined(a, 2, 999);
	time = clock() - time; //ends time
	printf("combined: %f\n", (double)time / CLOCKS_PER_SEC);

	time = clock();					  //starts time
	for (int i = 0; i < 1000000; i++) //call multiple times to get significant values
		//poly(a,2,999);
		op_combined(a, 2, 999);
	time = clock() - time; //ends time
	printf("combined op: %f\n", (double)time / CLOCKS_PER_SEC);

	time = clock();					  //starts time
	for (int i = 0; i < 1000000; i++) //call multiple times to get significant values
		//poly(a,2,999);
		poly(a, 2, 999);
	time = clock() - time; //ends time
	printf("poly: %f\n", (double)time / CLOCKS_PER_SEC);

	time = clock();					  //starts time
	for (int i = 0; i < 1000000; i++) //call multiple times to get significant values
		//poly(a,2,999);
		op_poly(a, 2, 999);
	time = clock() - time; //ends time
	printf("poly op: %f\n", (double)time / CLOCKS_PER_SEC);

	time = clock();					  //starts time
	for (int i = 0; i < 1000000; i++) //call multiple times to get significant values
		//poly(a,2,999);
		horner_poly(a, 2, 999);
	time = clock() - time; //ends time
	printf("horner: %f\n", (double)time / CLOCKS_PER_SEC);

	time = clock();					  //starts time
	for (int i = 0; i < 1000000; i++) //call multiple times to get significant values
		//poly(a,2,999);
		op_horner_poly(a, 2, 999);
	time = clock() - time; //ends time
	printf("horner op: %f\n", (double)time / CLOCKS_PER_SEC);
}
