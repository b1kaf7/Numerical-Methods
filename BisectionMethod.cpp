#include <stdio.h>
#include <math.h>
#define EPS 0.00001
#define F(x) (x) * (x) * (x) - 4 * (x) - 9

// fuction for bisection method
int bim(float *a, float *b, float *root, int *s, int *count)
{
	float x1, x2, x0, f0, f1, f2;

	x1 = *a;
	x2 = *b;
	f1 = F(x1);
	f2 = F(x2);

	if (f1 * f2 > 0)
	{
		*s = 0;
		return 0;
	}
	else
	{
		*count = 0;

	begin:
		x0 = (x1 + x2) / 2.0;
		f0 = F(x0);
		if (f0 == 0)
		{
			*s = 1;
			*root = x0;
			return 0;
		}
		if (f1 * f0 < 0)
		{
			x2 = x0;
		}
		else
		{
			x1 = x0;
			f1 = f0;
		}

		if (fabs((x2 - x1) / x2) < EPS)
		{
			*s = 1;
			*root = (x1 + x2) / 2.0;
			return 0;
		}
		else
		{
			*count = *count + 1;
			goto begin;
		}
	}
}

int main()
{
	int s, count;
	float a, b, root;

	printf("\n");
	printf("Solution By Bisection Method \n");
	printf("\n");
	printf("Input starting values: ");
	scanf("%f %f", &a, &b);

	bim(&a, &b, &root, &s, &count);

	if (s == 0)
	{
		printf("\n");
		printf("Starting points do not bracket any root \n");
		printf("Check whether they bracket EVEN roots \n");
		printf("\n");
	}
	else
	{
		printf("\n Root = %f \n", root);
		printf("F(root) = %f \n", F(root));
		printf("\n");
		printf("Iterations = %d \n", count);
		printf("\n");
	}
}
