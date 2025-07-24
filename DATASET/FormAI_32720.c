//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include<stdio.h>
#include<math.h>

int main()
{
  float p, r, t, emi, tmp;
  int n;

  printf("Enter the principal amount: ");
  scanf("%f", &p);

  printf("Enter the rate of interest: ");
  scanf("%f", &r);

  printf("Enter the time period (in years): ");
  scanf("%f", &t);

  printf("Enter the number of payments per year: ");
  scanf("%d", &n);

  r = r / (12 * n * 100); /*monthly rate of interest*/
  t = t * 12 * n; /*total number of payments*/

  tmp = pow((1+r), t);

  emi = (p * r * tmp) / (tmp - 1);

  printf("\nEMI = Rs.%.2f\n", emi);

  return 0;
}