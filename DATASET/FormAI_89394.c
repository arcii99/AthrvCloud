//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <math.h>

#define SIZE 10

int main()
{
    int nums[SIZE] = {8, 4, 2, 6, 10, 12, 14, 16, 18, 20};
    int sum = 0;
    double mean, std_dev;

    // Calculate the mean
    for (int i = 0; i < SIZE; i++) {
        sum += nums[i];
    }
    mean = (double)sum / SIZE;

    // Calculate the standard deviation
    double sum_sq = 0;
    for (int i = 0; i < SIZE; i++) {
        sum_sq += pow(nums[i] - mean, 2);
    }
    std_dev = sqrt(sum_sq / SIZE);

    // Print the results
    printf("The array is: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("The mean is: %.2f\n", mean);
    printf("The standard deviation is: %.2f\n", std_dev);
    
    return 0;
}