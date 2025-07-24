//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 10

// Function declaration
double calculate_mean(int data[], int size);
double calculate_standard_deviation(int data[], int size);

int main()
{
    // Initialize the random number generator and array of data
    srand(time(0));
    int data[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        data[i] = rand() % 100;
    }

    // Calculate the mean and standard deviation of the data
    double mean = calculate_mean(data, ARRAY_SIZE);
    double standard_deviation = calculate_standard_deviation(data, ARRAY_SIZE);

    // Print the results
    printf("Data: ");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\nMean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", standard_deviation);

    return 0;
}

/**
 * Calculates the mean of an array of integers.
 *
 * @param data The array of data.
 * @param size The size of the array.
 * @return The mean.
 */
double calculate_mean(int data[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum / size;
}

/**
 * Calculates the standard deviation of an array of integers.
 *
 * @param data The array of data.
 * @param size The size of the array.
 * @return The standard deviation.
 */
double calculate_standard_deviation(int data[], int size)
{
    double mean = calculate_mean(data, size);
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / size);
}