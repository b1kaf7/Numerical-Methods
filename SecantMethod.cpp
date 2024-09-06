#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 50
#define F(x) (x)*(x)-4*(x)-10

//function for secant method
void sec(float *a, float *b, float *x1, float *x2, float *root, int *count, int *status) {
	float x3, f1, f2, error;
	
	*x1 = *a;
	*x2 = *b;
	f1 = F(*a);
	f2 = F(*b);
	
	*count = 1;
	
	begin:
		if(fabs(f1-f2) <= 1.E-10) {
			*status = 1;
			return;
		}
		x3 = *x2 - f2*(*x2-*x1)/(f2-f1);
		error = fabs((x3-*x2)/x3);
		
		if(error > EPS) {
			if(*count == MAXIT) {
				*status = 2;
				return;
			}
			else {
				*x1 = *x2;
			}
			
			*x2 = x3;
			f1 = f2;
			f2 = F(x3);
			*count += 1;
			goto begin;
		}
		else {
			*root = x3;
			*status = 3;
			return;
		}
}

int main(){
	float a, b, root, x1, x2;
	int count, status;
	
	printf("\n");
	printf("SOLUTION BY SECANT METHOD \n");
	printf("\n");
	printf("Input two starting points: ");
	scanf("%f %f", &a, &b);
	
	sec(&a, &b, &x1, &x2, &root, &count, &status);
	
	if(status == 1) {
		printf("\n");
		printf("DIVISON BY ZERO \n");
		printf("\n Last x1 = %f \n",x1);
		printf("\n Last x2 = %f \n",x2);
		printf("\n NO. OF ITERATIONS = %d", count);
		printf("\n");
	}
	else if(status == 2) {
		printf("\n");
		printf("NO CONVERGENCE IN %d ITERATIONS \n", MAXIT);
		printf("\n");
	}
	else {
		printf("\n");
		printf("Root = %f \n",root);
		printf("Function value at root = %f \n", F(root));
		printf("\n");
		printf("\n NO. OF ITERATIONS = %d", count);
		printf("\n");	
	}
	return 0;
}

