#include<stdio.h>
#define F(x) (x) * (x)

int main() {
	float h, x;
	
	printf("Enter the value of x:");
	scanf("%f", &x);
	
	printf("\nEnter the value for h: ");
	scanf("%f", &h);
	
	double forward = (F(x+h)-F(x)) / h;
	
	double central = (F(x+h) - F(x-h)) / (2*h);
	
	double backward = (F(x) - F(x-h)) / h;
	
	printf("\nThe derivative of the function at x = %.2f using forward difference formula is: %.4f\n", x, forward);
	printf("\nThe derivative of the function at x = %.2f using central difference formula is: %.4f\n", x, central);
	printf("\nThe derivative of the function at x = %.2f using backward difference formula is: %.4f\n", x, backward);
	
	return 0;
}
