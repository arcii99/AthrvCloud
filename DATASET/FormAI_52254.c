//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Prompt user to enter the number of integers
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    //Allocate memory for the integers
    int *arr = (int*) malloc(n*sizeof(int));

    //Prompt user to enter the integers
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //Compute the sum of the integers
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    //Compute the mean of the integers
    float mean = (float) sum / n;

    //Compute the standard deviation of the integers
    float deviation = 0.0;
    for(int i = 0; i < n; i++)
    {
        deviation += (arr[i] - mean) * (arr[i] - mean);
    }
    deviation = sqrt(deviation/n);

    //Print the results
    printf("\nThe sum of the integers is: %d\n", sum);
    printf("The mean of the integers is: %.2f\n", mean);
    printf("The standard deviation of the integers is: %.2f\n", deviation);

    //Free the allocated memory
    free(arr);

    return 0;
}