//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*This program demonstrates an example of data mining through a mathematical approach.*/

int main()
{
    //Defining required variables
    float x[10], y[10], sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    int i;

    //Accepting input from user
    printf("Enter the values for x and y:\n");
    for (i = 0; i < 10; i++)
    {
        printf("\nEnter value of x[%d]: ", i + 1);
        scanf("%f", &x[i]);
        printf("Enter value of y[%d]: ", i + 1);
        scanf("%f", &y[i]);
    }

    //Calculating the required values
    for (i = 0; i < 10; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += pow(x[i], 2);
    }

    float numerator = 10 * sum_xy - (sum_x * sum_y);
    float denominator = 10 * sum_x2 - pow(sum_x, 2);
    float slope = numerator / denominator;

    printf("\nThe regression line is y = %0.2fx", slope);

    return 0;
}