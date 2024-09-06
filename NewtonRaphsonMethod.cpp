#include <stdio.h>
#include <math.h>

#define EPS 0.00001
#define MAXIT 20

// Function definition
float F(float x)
{
	return x * x - 3 * x + 2;
}

// Derivative of the function
float FD(float x)
{
	return 2 * x - 3;
}

int main()
{
	float x0, xn, fx, fdx;
	int count = 1;

	printf("Input initial value of x: ");
	scanf("%f", &x0);

	printf("\nSOLUTION BY NEWTON-RAPHSON METHOD\n\n");

	// Newton Raphson method loop
	while (count <= MAXIT)
	{
		fx = F(x0);
		fdx = FD(x0);

		if (fabs(fdx) < EPS)
		{
			printf("Derivative is zero. Newton-Raphson method cannot converge.\n");
			return 1;
		}

		xn = x0 - fx / fdx;

		printf("Iteration %d: x = %f, f(x) = %f\n", count, xn, F(xn));

		if (fabs(xn - x0) < EPS)
		{
			printf("\nRoot found at x = %f\n", xn);
			printf("Function value at root = %f\n", F(xn));
			printf("Number of iterations = %d\n", count);
			return 0;
		}

		x0 = xn;
		count++;
	}

	printf("\nSolution did not converge in %d iterations.\n", MAXIT);
	return 1;
}
