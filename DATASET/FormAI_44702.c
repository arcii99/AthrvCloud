//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    // Initialize variables
    char input[1000];
    int len, i, flag = 0;

    // Accept input from user
    printf("Enter a message: ");
    fgets(input, 1000, stdin);

    // Determine length of input string
    len = strlen(input);

    // Iterate through each character in the input string
    for (i = 0; i < len; i++) {
        // Check if current character is a number or a special character
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == '!' || input[i] == '@' ||
            input[i] == '#' || input[i] == '$' || input[i] == '%' || input[i] == '^' ||
            input[i] == '&' || input[i] == '*' || input[i] == '(' || input[i] == ')' ||
            input[i] == '{' || input[i] == '}' || input[i] == '[' || input[i] == ']' ||
            input[i] == ':' || input[i] == ';' || input[i] == '<' || input[i] == '>' ||
            input[i] == '.' || input[i] == '?' || input[i] == '/') {
            // Set flag to indicate presence of spam
            flag = 1;
            break;
        }
    }

    // If spam is detected, print message and exit program
    if (flag == 1) {
        printf("Spam detected! Message cannot be sent.\n");
        return 0;
    }

    // Otherwise, print confirmation message and exit program
    printf("Message sent successfully.\n");
    return 0;
}