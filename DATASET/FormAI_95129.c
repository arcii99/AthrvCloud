//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100], output[100];
    int i, j;

    printf("Enter a string: ");
    fgets(input, 100, stdin); // get user input

    // sanitize input by removing special characters and converting to lowercase
    for(i = 0, j = 0; i < strlen(input); i++) {
        if(isalpha(input[i])) {
            output[j] = tolower(input[i]);
            j++;
        }
    }
    output[j] = '\0';

    printf("Sanitized string: %s\n", output); // print sanitized input

    return 0;
}