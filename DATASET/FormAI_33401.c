//FormAI DATASET v1.0 Category: Educational ; Style: systematic
/*
 This program calculates the average of 5 numbers entered by the user using arrays and loops.
*/

#include <stdio.h>

int main() {

    float numbers[5];
    float sum = 0;
    float average = 0;

    // Ask user to input 5 numbers
    printf("Enter 5 numbers: ");

    // Read the 5 numbers and store them in the array
    for (int i = 0; i < 5; i++) {
        scanf("%f", &numbers[i]);
    }

    // Calculate the sum of the 5 numbers
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    // Calculate the average of the 5 numbers
    average = sum / 5;

    // Display the average to the user
    printf("The average of the 5 numbers is %f", average);

    return 0;
}