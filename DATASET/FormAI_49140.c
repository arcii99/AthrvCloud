//FormAI DATASET v1.0 Category: Data validation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[256];
    int validInput = 0;
    
    printf("Please enter a valid integer: ");

    while (!validInput) {
        fgets(input, sizeof(input), stdin);

        // Check if input is too long.
        if (input[strlen(input) - 1] != '\n') {
            printf("Input is too long. Please enter a valid integer: ");
            // Clear the input buffer.
            while (getchar() != '\n');
        } else {
            // Remove the newline character.
            input[strlen(input) - 1] = '\0';
            
            // Check if input is an integer.
            for (int i = 0; i < strlen(input); i++) {
                // Check if the current character is a digit.
                if (isdigit(input[i])) {
                    validInput = 1;
                } else {
                    validInput = 0;
                    printf("Invalid input. Please enter a valid integer: ");
                    break;
                }
            }
        }
    }

    int num = atoi(input);
    printf("The valid input is %d\n", num);

    return 0;
}