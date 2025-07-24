//FormAI DATASET v1.0 Category: Random ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num, odd_count = 0, even_count = 0;
    float mean, variance = 0, stdev;
    int arr[100]; 
    
    srand(time(0)); // seed the random number generator with current time 

    printf("Generating 100 Random Numbers between 1 to 100:\n");
    for (i = 0; i < 100; i++) {
        num = rand() % 100 + 1; // generate a random number between 1 and 100 
        arr[i] = num;
        printf("%d ", num);
    }

    printf("\n\nCalculating Statistics on Generated Numbers...\n");
    for (i = 0; i < 100; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
        mean += arr[i];
    }
    
    mean /= 100; // calculate the mean 
    for (i = 0; i < 100; i++) {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }

    variance /= 100; // calculate the variance 
    stdev = sqrt(variance); // calculate the standard deviation 

    printf("Total Numbers: 100\n");
    printf("Odd Numbers: %d\n", odd_count);
    printf("Even Numbers: %d\n", even_count);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stdev);

    return 0;
}