//FormAI DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
This program generates a random list of numbers and
calculates their mean and standard deviation using the 
formulae: Mean = (sum of numbers)/total number of numbers
and Standard Deviation = sqrt((sum(x - mean)^2)/N)

*/

int main()
{
    int i, n;
    float *ptr, sum = 0.0, mean, std_deviation = 0.0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    ptr = (float *)malloc(n * sizeof(float)); // Dynamic memory allocation for the list of numbers

    // Generate n random numbers between 0 and 100 and store them in the array
    srand(time(NULL)); // Setting seed for random number generation
    printf("The random list of numbers is:\n");
    for (i = 0; i < n; i++)
    {
        *(ptr + i) = rand() % 101;
        printf("%.2f ", *(ptr + i));
        sum += *(ptr + i); // Calculating the sum of the numbers
    }
    printf("\n");

    // Calculating the mean of the numbers
    mean = sum / n;
    printf("The mean of the numbers is: %.2f\n", mean);

    // Calculating the standard deviation of the numbers
    for (i = 0; i < n; i++)
        std_deviation += powf(*(ptr + i) - mean, 2);
    std_deviation = sqrt(std_deviation / n);
    printf("The standard deviation of the numbers is: %.2f\n", std_deviation);

    free(ptr); // Freeing the dynamically allocated memory

    return 0;
}