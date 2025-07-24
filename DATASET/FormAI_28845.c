//FormAI DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <time.h>

#define SIZE 1000000 // Define the size of the array

int main() {
    int array[SIZE]; // Create an array of integers
    
    // Fill the array with random values
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }
    
    // Method 1: Iterate through the array and calculate the sum
    clock_t start1, end1; // Start and end time for method 1
    double cpu_time_used1; // CPU time used for method 1
    int sum1 = 0; // Sum calculated using method 1
    
    start1 = clock(); // Record the start time
    for(int i = 0; i < SIZE; i++) {
        sum1 += array[i];
    }
    end1 = clock(); // Record the end time
    
    cpu_time_used1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC; // Calculate CPU time used
    
    printf("Method 1:\n");
    printf("Sum: %d\n", sum1);
    printf("Time: %f seconds\n\n", cpu_time_used1);
    
    // Method 2: Change the order of iteration for better caching
    clock_t start2, end2; // Start and end time for method 2
    double cpu_time_used2; // CPU time used for method 2
    int sum2 = 0; // Sum calculated using method 2
    
    start2 = clock(); // Record the start time
    for(int i = 0; i < SIZE; i += 16) {
        sum2 += array[i] + array[i+1] + array[i+2] + array[i+3] 
              + array[i+4] + array[i+5] + array[i+6] + array[i+7]
              + array[i+8] + array[i+9] + array[i+10] + array[i+11] 
              + array[i+12] + array[i+13] + array[i+14] + array[i+15];
    }
    end2 = clock(); // Record the end time
    
    cpu_time_used2 = ((double)(end2 - start2)) / CLOCKS_PER_SEC; // Calculate CPU time used
    
    printf("Method 2:\n");
    printf("Sum: %d\n", sum2);
    printf("Time: %f seconds\n\n", cpu_time_used2);
    
    // Compare the two methods
    if(cpu_time_used1 > cpu_time_used2) {
        printf("Method 2 is faster\n");
    } else {
        printf("Method 1 is faster\n");
    }
    
    return 0;
}