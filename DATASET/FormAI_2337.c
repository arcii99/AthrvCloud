//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL));  // initialize random seed

    int n = 5 + rand() % 6;  // generate random number between 5 and 10
    float nums[n];  // declare an array of n floats

    // populate array with random numbers between -10 and 10
    for (int i = 0; i < n; i++) {
        nums[i] = (rand() % 21) - 10;
    }

    float average = 0;
    // calculate average of array
    for (int i = 0; i < n; i++) {
        average += nums[i];
    }
    average /= n;

    printf("The average of the %d numbers is %.2f\n\n", n, average);

    float sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        float diff = nums[i] - average;
        sum_of_squares += diff * diff;
    }

    float variance = sum_of_squares / n;
    float stdev = sqrt(variance);

    printf("The standard deviation of the %d numbers is %.2f\n\n", n, stdev);

    float min_diff = fabs(nums[0] - average);  // initialize minimum difference as difference between first number and average
    float closest_num = nums[0];  // initialize closest number as first number in array

    for (int i = 1; i < n; i++) {
        float diff = fabs(nums[i] - average);
        if (diff < min_diff) {
            min_diff = diff;
            closest_num = nums[i];
        }
    }

    printf("The number closest to the average is %.2f with a difference of %.2f\n\n", closest_num, min_diff);

    int max_index = 0;  // initialize maximum index as first index of array

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[max_index]) {
            max_index = i;
        }
    }

    printf("The maximum number in the array is %.2f at index %d\n\n", nums[max_index], max_index);

    int min_index = 0;  // initialize minimum index as first index of array

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[min_index]) {
            min_index = i;
        }
    }

    printf("The minimum number in the array is %.2f at index %d\n\n", nums[min_index], min_index);

    return 0;
}