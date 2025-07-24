//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include <stdio.h>

int main() {
    printf("Hello, I am a chatbot!\n");

    int x, y, z;

    // Prompt user to input three integers
    printf("Please enter three integer values: \n");
    scanf("%d%d%d", &x, &y, &z);

    // Determine the maximum and minimum values
    int max = x;
    int min = x;

    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    if (y < min) {
        min = y;
    }
    if (z < min) {
        min = z;
    }

    // Calculate the sum, average, and product of the three integers
    int sum = x + y + z;
    float avg = ((float) sum) / 3;
    int product = x * y * z;

    // Output the results to the user
    printf("The maximum value is: %d\n", max);
    printf("The minimum value is: %d\n", min);
    printf("The sum of the three integers is: %d\n", sum);
    printf("The average of the three integers is: %.2f\n", avg);
    printf("The product of the three integers is: %d\n", product);

    return 0;
}