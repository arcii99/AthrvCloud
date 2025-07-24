//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate three random numbers between 1 and 10
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int num3 = rand() % 10 + 1;
    
    // Display the numbers to the user
    printf("Your first number is %d!\n", num1);
    printf("Your second number is %d!\n", num2);
    printf("And finally, your third number is %d!\n", num3);
    
    // Calculate the average of the three numbers
    double average = (num1 + num2 + num3) / 3.0;
    
    // Round the average to two decimal places
    average = ((int)(average * 100 + 0.5)) / 100.0;
    
    // Display the average to the user
    printf("\nThe average of your three numbers is %.2f!\n", average);
    
    // Calculate the standard deviation of the three numbers
    double deviation = sqrt(((num1 - average) * (num1 - average) + (num2 - average) * (num2 - average) + (num3 - average) * (num3 - average)) / 3.0);
    
    // Round the deviation to two decimal places
    deviation = ((int)(deviation * 100 + 0.5)) / 100.0;
    
    // Display the standard deviation to the user
    printf("\nThe standard deviation of your three numbers is %.2f!\n", deviation);

    return 0;
}