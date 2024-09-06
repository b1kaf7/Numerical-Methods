#include<stdio.h>
int main() {
	int i, j, n;
	float xp, fp, sum, pi, x[10], f[10], a[10], d[10][10];
	
	printf("\nInput number of data points: ");
	scanf("%d", &n);
	
	printf("\nInput values of x and f(x), (one set on each line) \n");
	for(i=1; i<=n; i++)
		scanf("%f %f", &x[i], &f[i]);
		
	//construct difference table
	for(i=1; i<=n; i++) 
		d[i][1] = f[i];
	
	for(j=2; j<=n; j++)	{
		for(i=1; i<=n-j+1; i++) {
			d[i][j] = (d[i+1][j-1]-d[i][j-1])/(x[i+j-1]-x[i]);
		}
	}
	
	//set coefficient
	for(j=1; j<=n; j++)
		a[j] = d[1][j];
	
	
	//compute interpolation value
	printf("\nInter xp where interpolation is required: ");
	scanf("%f", &xp);
	sum = a[1];
	for(i=2; i<=n; i++) {
		pi = 1.0;
		for(j=1; j<=i-1; j++) {
			pi = pi*(xp-x[j]);
		}
		sum = sum + a[i] * pi;
	}
	
	fp = sum;
	
	//write result
	printf("\n");
	printf("NEWTON INTERPOLATION \n");
	printf("\n");
	printf("Interpolated value at x=%f is %f", xp, fp);
}
