//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

int main()
{
    char input_string[MAX_LENGTH];
    printf("Enter your input string: ");
    fgets(input_string, MAX_LENGTH, stdin);
    printf("Original Input String: %s", input_string);

    for (int i = 0; i < strlen(input_string); i++) {
        if (isupper(input_string[i])) {
            input_string[i] = tolower(input_string[i]); // convert uppercase to lowercase
        }
        if(ispunct(input_string[i]) || isspace(input_string[i])) {
            input_string[i] = '_'; // replace punctuations and spaces with an underscore
        }
    }

    printf("Sanitized Input String: %s", input_string);
    return 0;
}