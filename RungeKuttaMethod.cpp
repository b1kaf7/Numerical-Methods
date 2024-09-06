#include<stdio.h>
#include<math.h>
#define f(x,y) x + y 

int main() {
    printf("\nRunge-Kutta Method\n");
    
    float x0, y0, m1, m2, m3, m4, y, x, h;
    
    printf("\nEnter the value for x0 and y0 respectively: ");
    scanf("%f %f", &x0, &y0);
    
    printf("\nEnter the value for h: ");
    scanf("%f", &h);
    
    x=x0;
    y=y0;
    
    while(x < x0 + h) {
        m1 = f(x0,y0);
        m2 = f((x0+h/2.0),(y0+m1*h/2.0));
        m3 = f((x0+h/2.0),(y0+m2*h/2.0));
        m4 = f((x0+h),(y0+m3*h));
        
        y = y0+(h/6)*(m1+2*m2+2*m3+m4);
        
        x = x0+h;
        
        printf("\nAt x=%f\t y=%f\n\n",x,y);
    }
    return 0;
}

