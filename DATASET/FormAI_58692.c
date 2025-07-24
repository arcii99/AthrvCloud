//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, n;
    double mean = 0, sum = 0, var = 0, sd = 0;

    // Seed the random number generator
    srand(time(0));

    // Generate an array of 10 random numbers between 1 and 100
    int nums[10];
    printf("Numbers Generated:\n");
    for (i = 0; i < 10; i++) {
        nums[i] = rand() % 100 + 1;
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Calculate Mean
    for (i = 0; i < 10; i++) {
        sum += nums[i];
    }
    mean = sum / 10;
    printf("Mean: %.2f\n", mean);

    // Calculate Variance
    for (i = 0; i < 10; i++) {
        var += pow(nums[i] - mean, 2);
    }
    var /= 9;
    printf("Variance: %.2f\n", var);

    // Calculate Standard Deviation
    sd = sqrt(var);
    printf("Standard Deviation: %.2f\n", sd);

    // Generate a new array of n random numbers between 1 and 100,
    // and compare their mean and standard deviation to the original.
    printf("\nEnter a value for n: ");
    scanf("%d", &n);

    int newNums[n];
    sum = 0;
    printf("\nNew Numbers Generated:\n");
    for (i = 0; i < n; i++) {
        newNums[i] = rand() % 100 + 1;
        printf("%d ", newNums[i]);
        sum += newNums[i];
    }
    printf("\n");

    mean = sum / n;
    printf("New Mean: %.2f\n", mean);

    var = 0;
    for (i = 0; i < n; i++) {
        var += pow(newNums[i] - mean, 2);
    }
    var /= n - 1;
    printf("New Variance: %.2f\n", var);

    sd = sqrt(var);
    printf("New Standard Deviation: %.2f\n", sd);

    // Calculate the probability that a new number is within
    // 1, 2, and 3 standard deviations of the mean.
    int count1 = 0, count2 = 0, count3 = 0;
    double threshold1 = mean + sd;
    double threshold2 = mean + 2 * sd;
    double threshold3 = mean + 3 * sd;

    for (i = 0; i < n; i++) {
        if (newNums[i] >= mean - sd && newNums[i] <= threshold1) {
            count1++;
        }
        if (newNums[i] >= mean - 2 * sd && newNums[i] <= threshold2) {
            count2++;
        }
        if (newNums[i] >= mean - 3 * sd && newNums[i] <= threshold3) {
            count3++;
        }
    }

    double prob1 = (double) count1 / n * 100;
    double prob2 = (double) count2 / n * 100;
    double prob3 = (double) count3 / n * 100;

    printf("\nProbability of a new number being within:\n");
    printf("1 standard deviation: %.2f%%\n", prob1);
    printf("2 standard deviation: %.2f%%\n", prob2);
    printf("3 standard deviation: %.2f%%\n", prob3);

    return 0;
}