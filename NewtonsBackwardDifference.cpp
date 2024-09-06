#include <stdio.h>

// Function to calculate the backward difference table
void backward_difference_table(double x[], double y[], double diff[][10], int n)
{
  // Copy y values to the first column of the difference table
  for (int i = 0; i < n; i++)
  {
    diff[i][0] = y[i];
  }

  // Calculate the backward difference table
  for (int j = 1; j < n; j++)
  {
    for (int i = n - 1; i >= j; i--)
    {
      diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
    }
  }
}

// Function to print the backward difference table
void print_difference_table(double x[], double diff[][10], int n)
{
  printf("Backward Difference Table:\n");
  printf("   x   |");
  for (int j = 0; j < n; j++)
  {
    printf("  Δ^%d y  ", j);
  }
  printf("\n");
  printf("-------|");
  for (int j = 0; j < n; j++)
  {
    printf("-----------");
  }
  printf("\n");

  for (int i = 0; i < n; i++)
  {
    printf(" %4.2f |", x[i]);
    for (int j = 0; j < n - i; j++)
    {
      printf(" %10.4f ", diff[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n;
  printf("Enter the number of data points: ");
  scanf("%d", &n);

  double x[n], y[n];
  double diff[10][10]; // Adjust size according to the maximum number of data points

  // Input x and y values
  printf("Enter the values of x:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &x[i]);
  }
  printf("Enter the values of y:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &y[i]);
  }

  // Calculate backward difference table
  backward_difference_table(x, y, diff, n);

  // Print the backward difference table
  print_difference_table(x, diff, n);

  return 0;
}
