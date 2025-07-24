//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
//This program calculates the standard deviation of a set of ten numbers using the formula:
//sqrt((sum((X - mean)^2))/N)

#include <stdio.h>
#include <math.h>

int main() {
    int numbers[10]; //array to hold ten numbers
    int i, sum = 0;
    double mean, stdDev; //variables to hold the mean and standard deviation
    
    printf("Enter ten numbers:\n");
    
    for(i=0; i<10; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    
    mean = sum/10.0; //calculating mean
    
    double sumOfSquares = 0;
    
    for(i=0; i<10; i++) {
        sumOfSquares += pow(numbers[i]-mean, 2);
    }
    
    stdDev = sqrt(sumOfSquares/10); //calculating standard deviation
    
    printf("The standard deviation of the ten numbers is: %lf", stdDev);
    
    return 0;
}