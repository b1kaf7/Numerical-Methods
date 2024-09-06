#include<stdio.h>
#include<math.h>
#define F(x) sqrt(1 - (x) * (x))
int main() {
	int i;
	float a, b, h, n, sum, ict;
	
	printf("\nGive initial value of x: ");
	scanf("%f", &a);
	printf("\nGive final value of x: ");
	scanf("%f", &b);
	printf("\nWhat is the segment width? : ");
	scanf("%f", &n);
	
	h = (b-a)/n;
	
	sum = (F(a) + F(b));
	for(i=1; i<=n-1; i++) {
		if(i%2==0)
			sum = sum + 2 * F(a+i*h);
		else
			sum = sum + 4 * F(a+i*h);
	}
	
	ict = sum * h / 3;
	
	printf("\n");
	printf("INTEGRATION BY COMPOSITE 1/3 SIMPSON'S RULE");
	printf("\n \n");
	printf("Integration between %f and %f \n", a, b);
	printf("When h=%f is %f \n", h, ict);
	printf("\n");
	
	return 0;
}
