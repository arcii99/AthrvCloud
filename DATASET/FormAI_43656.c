//FormAI DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>

int main() {

    printf("Welcome to the exciting world of C programming!\n");
    printf("This program will demonstrate the use of arrays to calculate the sum and average of 10 integers.\n\n");

    int numbers[10];
    int sum = 0;
    float average;

    printf("Please enter 10 integers:\n");

    for(int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum/10;

    printf("\nThe sum of the integers is: %d\n", sum);
    printf("The average of the integers is: %.2f\n", average);

    printf("\nThank you for using this program to enhance your C programming skills!!\n");

    return 0;
}