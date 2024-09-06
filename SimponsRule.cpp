#include<stdio.h>
#include<math.h>
#define F(x) sqrt(1 - (x) * (x))
int main() {
	int i;
	float x0, xn, x1, h;
	
	printf("\nGive initial value of x: ");
	scanf("%f", &x0);
	printf("\nGive final value of x: ");
	scanf("%f", &xn);
	
	h = (xn-x0) / 2;
	
	x1 = x0 + h;

	double integration = (h/3) * (F(x0) + 4 * F(x1) + F(xn));
	
	printf("\n");
	printf("INTEGRATION BY 1/3 SIMPSON'S RULE");
	printf("\n \n");
	printf("Integration between %.2f and %.2f \n", x0, xn);
	printf("When h=%.2f is %f \n", h, integration);
	printf("\n");
	
	return 0;
}
