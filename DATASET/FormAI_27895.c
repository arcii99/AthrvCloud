//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int numArray[SIZE];
    int i, sum=0;

    // Generating random numbers and filling array
    srand(time(NULL));
    for (i=0; i<SIZE; i++) {
        numArray[i] = rand() % 101; // Generating random numbers between 0-100
    }

    // Printing the array
    printf("Generated numbers: ");
    for (i=0; i<SIZE; i++) {
        printf("%d ", numArray[i]);
    }
    printf("\n");

    // Calculating and printing the sum of the array
    for (i=0; i<SIZE; i++) {
        sum += numArray[i];
    }
    printf("The sum of the numbers is: %d \n", sum);

    // Calculating and printing the average of the array
    float avg = (float)sum / SIZE;
    printf("The average of the numbers is: %.2f \n", avg);

    // Calculating and printing the standard deviation of the array
    float variance = 0.0;
    for (i=0; i<SIZE; i++) {
        variance += ((float)numArray[i]-avg)*((float)numArray[i]-avg);
    }
    float std_dev = sqrt(variance/SIZE);
    printf("The standard deviation of the numbers is: %.2f \n", std_dev);

    return 0;
}