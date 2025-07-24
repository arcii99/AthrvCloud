//FormAI DATASET v1.0 Category: Scientific ; Style: sophisticated
#include <stdio.h>

/* This is a program that receives a list of integers and determines 
   if they are odd or even. It also calculates their sum and average.*/

void main() {
    int num, sum = 0, count = 0, odd = 0, even = 0; 
    float avg;

    printf("Please enter a list of integers (separated by spaces): \n");
    
    /* Repeatedly scan integers until the user inputs a non-integer value
       such as a letter. */
    while (scanf("%d", &num) == 1) {
        count++; // Increment the count of total integers

        // Check if the number is odd or even
        if (num % 2 == 0) {
            even++;
        } else {
            odd++;
        }

        sum += num; // Add the number to the running total

    }

    // Determine the average of the numbers using floating point division
    avg = (float) sum / (float) count;
   
    // Output the results
    printf("Total integers: %d\n", count);
    printf("Number of odd integers: %d\n", odd);
    printf("Number of even integers: %d\n", even);
    printf("Sum of all integers: %d\n", sum);
    printf("Average of all integers: %f\n", avg);
}