#include<stdio.h>
#define MAX 10
int main() {
	int n, i, j;
	float x[MAX], f[MAX], fp, lf, sum, xp;
	
	printf("\nInput number of data points, n: ");
	scanf("%d", &n);
	
	printf("\nInput data points x(i) and values f(i) \n");
	printf("(one set in each line) \n");
	for(i=0; i<n; i++) {
		scanf("%f %f", &x[i], &f[i]);
	}
	
	printf("\nInput x at which interpolation is required: ");
	scanf("%f", &xp);
	
	//lagrange interpolation
	sum = 0.0;
	for(i=0; i<n; i++) {
		lf = 1.0;
		for(j=0; j<n; j++) {
			if(i != j) 
				lf = lf*(xp-x[j])/(x[i]-x[j]);
		}
		sum = sum + lf * f[i];
	}
	
	fp = sum;
	printf("\nLAGRANGIAN INTERPOLATION \n\n");
	printf("\nInterpolated function value at x=%f is %f \n", xp, fp);
}
