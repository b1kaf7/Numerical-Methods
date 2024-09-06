#include <stdio.h>
#include <math.h>
#define EPS 0.000001
#define F(x) 2.0 - (x) * (x)
int main()
{
	int MAXIT, i;
	float x0, x, error;

	printf("\n Solution by Fixed-Point Method \n");
	printf("\n");
	printf("Input initial estimate of a root: ");
	scanf("%f", &x0);
	printf("Maximum iterations allowed: ");
	scanf("%d", &MAXIT);

	printf("\nIteration \t Value of X \t ERROR \n");

	// fixed point method
	for (i = 1; i <= MAXIT; i++)
	{
		x = F(x0);
		error = fabs((x - x0) / x);
		printf(" %d \t %0.7f \t %0.7f \n", i, x, error);
		if (error < EPS)
			goto end;
		else
			x0 = x;
	}

	printf("\n Process doesnot converge to a root.\n");
	printf("Exit from iteration loop.\n");
end:;
}
