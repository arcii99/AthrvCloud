//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random numbers
int rand_num() {
    int num;
    num = rand() % 101; //generate a random number between 0 and 100
    return num;
}

int main() {
    srand(time(NULL)); //initialize the random seed
    
    int num1, num2, num3, num4, num5; //declare variables for 5 random numbers
    float mean, variance, std_deviation; //declare variables for mean, variance, and standard deviation
    
    //generate 5 random numbers and calculate their sum
    num1 = rand_num();
    num2 = rand_num();
    num3 = rand_num();
    num4 = rand_num();
    num5 = rand_num();
    int sum = num1 + num2 + num3 + num4 + num5;
    
    //calculate the mean
    mean = (float)sum / 5;
    
    //calculate the variance
    variance = ((float)num1 - mean) * ((float)num1 - mean) +
               ((float)num2 - mean) * ((float)num2 - mean) +
               ((float)num3 - mean) * ((float)num3 - mean) +
               ((float)num4 - mean) * ((float)num4 - mean) +
               ((float)num5 - mean) * ((float)num5 - mean);
    variance /= 5;
    
    //calculate the standard deviation
    std_deviation = sqrt(variance);
    
    //print the results
    printf("Five random numbers: %d %d %d %d %d\n", num1, num2, num3, num4, num5);
    printf("Sum of numbers: %d\n", sum);
    printf("Mean of numbers: %f\n", mean);
    printf("Variance of numbers: %f\n", variance);
    printf("Standard deviation of numbers: %f", std_deviation);
    
    return 0;
}