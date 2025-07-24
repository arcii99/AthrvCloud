//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program generates 10,000 random numbers and calculates their average
// It then times how long it takes to perform the calculation
// Finally, it compares the time taken with the time taken for a simple loop

int main() {
    
    printf("Hi there! Let's test some benchmarks!\n\n");
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate 10,000 random numbers
    int numbers[10000];
    for (int i = 0; i < 10000; i++) {
        numbers[i] = rand() % 100;
    }
    
    // Calculate the average of the 10,000 numbers
    int sum = 0;
    clock_t start = clock();
    for (int i = 0; i < 10000; i++) {
        sum += numbers[i];
    }
    double average = (double) sum / 10000;
    printf("The average of the random numbers is %.2f\n", average);
    clock_t end = clock();
    printf("It took %ld clocks, which is %.4f seconds\n", (long) (end - start), ((double) (end - start) / CLOCKS_PER_SEC));
    
    // Compare the time taken with a simple loop
    sum = 0;
    start = clock();
    for (int i = 0; i < 10000; i++) {
        sum += i;
    }
    printf("The sum of the numbers 0 to 9999 is %d\n", sum);
    end = clock();
    printf("It took %ld clocks, which is %.4f seconds\n", (long) (end - start), ((double) (end - start) / CLOCKS_PER_SEC));
    
    printf("\nThat was fun! Let's benchmark more programs next time :)");
    
    return 0;
}