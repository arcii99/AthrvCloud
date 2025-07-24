//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include<stdio.h>

/* A scientific example of C syntax parsing using a Gaussian quadrature algorithm */

int main()
{
    int n = 5; /* Number of nodes */

    /* Define the weights and nodes of the Gaussian quadrature */
    double w[] = {0.2369, 0.4786, 0.5688, 0.4786, 0.2369};
    double x[] = {-0.9062, -0.5385, 0, 0.5385, 0.9062};

    double sum = 0; /* Initialize the sum of the function values */

    for(int i = 0; i < n; i++)
    {
        /* Evaluate the function f(x) = x^2 - 3x + 4 at each node */
        double fx = x[i] * x[i] - 3 * x[i] + 4;

        /* Add the weighted function value to the sum */
        sum += w[i] * fx;
    }

    printf("The integral of f(x) from -1 to 1 is approximately %f\n", sum);

    return 0;
}