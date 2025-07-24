//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, n;
    float weight, height, bmi, sum = 0.0, avg, max = -99999.0, min = 99999.0;
    
    printf("Welcome to the Fitness Tracker Program!\n\n");
    printf("Enter the number of persons you want to track: ");
    scanf("%d", &n);
    
    // loop for n persons
    for (i = 1; i <= n; i++) {
        printf("\nPerson %d:\n", i);
        printf("Enter weight (in kg): ");
        scanf("%f", &weight);
        printf("Enter height (in m): ");
        scanf("%f", &height);
        
        // calculate the BMI of the person
        bmi = weight / pow(height, 2);
        printf("BMI: %.2f\n", bmi);
        
        // calculate the sum of BMIs for average
        sum += bmi;
        
        // check for maximum BMI and minimum BMI
        if (bmi > max) {
            max = bmi;
        }
        if (bmi < min) {
            min = bmi;
        }
    }
    
    // calculate the average BMI
    avg = sum / n;
    printf("\nAverage BMI: %.2f\n", avg);
    
    // print the maximum and minimum BMIs
    printf("Maximum BMI: %.2f\n", max);
    printf("Minimum BMI: %.2f\n", min);
    
    return 0;
}