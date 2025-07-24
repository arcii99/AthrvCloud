//FormAI DATASET v1.0 Category: Text processing ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter some text: ");
    fgets(input, 100, stdin); // Read input from user
    printf("\nOriginal Text: %s", input);
    char output[100] = "";

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') { // Replace spaces with underscores
            output[i] = '_';
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') { // Convert uppercase letters to lowercase
            output[i] = input[i] + 32;
        }
        else if (input[i] >= 'a' && input[i] <= 'z') { // Convert lowercase letters to uppercase
            output[i] = input[i] - 32;
        }
        else { // Copy non-space and non-alphabet characters to output as is
            output[i] = input[i];
        }
    }
    printf("\nProcessed Text: %s", output);
    return 0;
}