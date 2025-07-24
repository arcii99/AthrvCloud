//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input_string[1000];
    printf("Enter your surreal input: ");
    fgets(input_string, 1000, stdin);

    printf("\nYour sanitized output: ");
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == 'e' || input_string[i] == 'E') {
            input_string[i] = '3'; //We will replace 'e' or 'E' with '3'

        } else if (input_string[i] == ':') {
            input_string[i] = '+'; //We will replace ':' with '+'

        } else if (input_string[i] == ')') {
            input_string[i] = 'D'; //We will replace ')' with 'D'

        } else if (input_string[i] == '/') {
            input_string[i] = '^'; //We will replace '/' with '^'

        } else if (input_string[i] == 's' || input_string[i] == 'S') {
            input_string[i] = '$'; //We will replace 's' or 'S' with '$'

        } else if (input_string[i] == 'r' || input_string[i] == 'R') {
            input_string[i] = '4'; //We will replace 'r' or 'R' with '4'
        }
    }

    printf("%s\n", input_string);
    return 0;
}