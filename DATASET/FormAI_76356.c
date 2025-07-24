//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main(void) {

    // Declare Variables
    char input[100], output[100];
    int i, j, flag = 0;

    // Print welcome message
    printf("Welcome to the Surrealist User Input Sanitizer Program! \n");
    printf("Please enter your input below: \n\n");

    // Take input from user
    fgets(input, 100, stdin);

    // Loop through input string
    for (i = 0, j = 0; i < strlen(input); i++, j++) {

        // Check for non-alphabetic characters
        if ((input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z')) {

            // Set flag to indicate non-alphabetic character found
            flag = 1;

            // Replace non-alphabetic character with random surrealistic image generator
            switch(rand()%5) {
                case 0:
                    output[j] = '!';
                    break;
                case 1:
                    output[j] = '♪';
                    break;
                case 2:
                    output[j] = '☀';
                    break;
                case 3:
                    output[j] = '♫';
                    break;
                case 4:
                    output[j] = '⌘';
                    break;
            }
        }

        // If no non-alphabetic character found, copy character to output string
        else {
            output[j] = input[i];
        }
    }

    // If no non-alphabetic character found, print message and exit
    if (flag == 0) {
        printf("\nYour input contained no non-alphabetic characters. No Sanitization needed! \n");
        return 0;
    }

    // Add null character to end of output string
    output[j] = '\0';

    // Print output string
    printf("\nYour input has been sanitized: \n");
    printf("%s", output);

    return 0;
}