//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[10] = {10, 23, 56, 7, 42, -5, 89, 0, 17, 33};
    int n = sizeof(data) / sizeof(int);

    // Find the largest number in the data set
    int max = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }

    // Find the smallest number in the data set
    int min = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }

    // Calculate the mean of the data set
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }
    float mean = (float)sum / n;

    // Calculate the standard deviation
    float std_deviation = 0;
    for (int i = 0; i < n; i++)
    {
        std_deviation += (data[i] - mean) * (data[i] - mean);
    }
    std_deviation = sqrt(std_deviation / n);

    // Print the results
    printf("The largest number in the data set is %d\n", max);
    printf("The smallest number in the data set is %d\n", min);
    printf("The mean of the data set is %.2f\n", mean);
    printf("The standard deviation of the data set is %.2f\n", std_deviation);

    return 0;
}