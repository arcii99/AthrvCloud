//FormAI DATASET v1.0 Category: Funny ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int nums[10] = {0};
    int num;

    for(int i = 0; i < 100; i++) {
        num = rand() % 10;
        nums[num]++;
    }

    printf("Number Frequency\n");

    for(int i = 0; i < 10; i++) {
        printf("%d %d\n", i, nums[i]);
    }

    printf("Statistics:\n");
    float sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += nums[i];
    }
    float mean = sum/10;
    printf("Mean: %.2f\n", mean);

    float variance = 0;
    for(int i = 0; i < 10; i++) {
        variance += (nums[i] - mean) * (nums[i] - mean);
    }
    variance /= 10;
    printf("Variance: %.2f\n", variance);

    float std_deviation = sqrt(variance);
    printf("Standard deviation: %.2f\n", std_deviation);

    return 0;
}