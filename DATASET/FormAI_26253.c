//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, i, j;
    float x[10], y[10], sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    float a, b, r;

    printf("Enter the number of data points (maximum 10): ");
    scanf("%d", &n);

    printf("Enter the x-values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
        sum_x += x[i];
    }

    printf("Enter the y-values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
        sum_y += y[i];
    }

    for(i = 0; i < n; i++)
    {
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    for(i = 0; i < n; i++)
    {
        r += (y[i] - a - b * x[i]) * (y[i] - a - b * x[i]);
    }

    r = sqrt(r / (n - 2));

    printf("\nThe equation of the regression line is: y = %.2fx + %.2f", b, a);
    printf("\nThe correlation coefficient is: %.2f", r);

    return 0;
}