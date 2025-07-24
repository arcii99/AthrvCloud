//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    int output = 0;

    printf("Enter a number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);  // Read input from user

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {  // Check if character is a digit
            output = output * 10 + (input[i] - '0');  // Convert character to integer and add to output
        } else {
            printf("Invalid input!\n");
            exit(1);
        }
    }

    printf("The number you entered is: %d\n", output);

    return 0;
}