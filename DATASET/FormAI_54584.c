//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter input string: ");
    fgets(input, 100, stdin); // read user input

    // sanitize the input string
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) { // check if not alphanumeric
            if(input[i] == '\n') { // check if newline character
                input[i] = '\0'; // replace with null character
                break; // exit loop
            } else {
                input[i] = ' '; // replace with space
            }
        } else {
            input[i] = tolower(input[i]); // convert to lowercase
        }
    }

    printf("Sanitized input: %s\n", input);
    return 0;
}