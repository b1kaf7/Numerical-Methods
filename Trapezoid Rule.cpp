#include <stdio.h>
#include <math.h>

#define F(x) ((x) * (x) * (x) + 2)

int main()
{
	float a, b, h;

	// Input initial and final values of x
	printf("\nGive initial value of x: ");
	scanf("%f", &a);
	printf("\nGive final value of x: ");
	scanf("%f", &b);

	// Calculate step size
	h = b - a;

	// Calculate integration using trapezoidal rule
	double integration = (h / 2) * (F(a) + F(b));

	// Output the result
	printf("\n");
	printf("INTEGRATION BY TRAPEZOID RULE");
	printf("\n \n");
	printf("Integration between %.2f and %.2f \n", a, b);
	printf("When h=%.2f is %f \n", h, integration);
	printf("\n");

	return 0;
}
