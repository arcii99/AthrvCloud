//FormAI DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>

int main() {
    printf("Welcome to the ephemeral C program!\n");

    // Declare an array that will hold 5 integers
    int numbers[5];

    // Create a loop to prompt the user for values to store in the array
    for (int i = 0; i < 5; i++) {
        printf("Enter value %d: ", i+1);

        // Use scanf to read in the user's input
        scanf("%d", &numbers[i]);
    }

    // Print out the values stored in the array
    printf("The values you entered are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Calculate the sum of the values in the array
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    // Calculate the average of the values in the array
    float average = (float)sum / 5.0;

    printf("The sum of the values is %d\n", sum);
    printf("The average of the values is %.2f\n", average);

    printf("Thank you for using the ephemeral C program!\n");

    return 0;
}