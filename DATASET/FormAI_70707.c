//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <time.h>

int main() {
  
    int num1 = 0, num2 = 0;
    time_t start_time, end_time;
    double time_taken;
    
    printf("Enter two numbers to find the sum: ");
    scanf("%d%d", &num1, &num2);
    
    printf("\n---------------\n");
    printf("Benchmarking results: \n");
    
    start_time = clock(); //start timer
    
    int sum = num1 + num2; //add two numbers
    
    end_time = clock(); //end timer
    
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; //calculate time taken
    
    printf("Sum of %d and %d: %d\n", num1, num2, sum);
    
    printf("Time taken: %f seconds\n", time_taken);
    
    printf("---------------\n");
    
    return 0;
}