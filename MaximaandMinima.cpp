#include <stdio.h>
#include <stdlib.h>

//maximum value of the function
double find_max(double x[], double y[], int n, double a, double b) {
  double max = y[0];
  for (int i = 1; i < n; i++) {
    if (y[i] > max && x[i] >= a && x[i] <= b) {
      max = y[i];
    }
  }
  return max;
}

//minimum value of the function 
double find_min(double x[], double y[], int n, double a, double b) {
  double min = y[0];
  for (int i = 1; i < n; i++) {
    if (y[i] < min && x[i] >= a && x[i] <= b) {
      min = y[i];
    }
  }
  return min;
}

int main() {
  double x[] = {1, 2, 3, 4, 5};
  double y[] = {1, 4, 9, 16, 25};

  int n = sizeof(x) / sizeof(x[0]);

  double max = find_max(x, y, n, 1, 3);

  double min = find_min(x, y, n, 1, 3);

  printf("The maximum value of the function is %lf.\n", max);
  printf("The minimum value of the function is %lf.\n", min);

  return 0;
}
