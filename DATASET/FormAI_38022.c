//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[50];
    int index = 0;

    printf("Hello! Please enter some input:\n");
    fgets(input, 50, stdin);

    // Iterate through input and sanitize 
    while (input[index] != '\n') {
        if (isalpha(input[index])) {
            putchar(tolower(input[index]));  // convert to lowercase
        } else if (isdigit(input[index])) {
            putchar(input[index]);  // leave digits unchanged
        } else {
            // ignore non-alphanumeric characters
        }
        index++;
    }

    printf("\nYour input has been sanitized. Thank you!");
    return 0;
}