//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

//function to sanitize user input string
char* sanitize(char* string) {
    int i, j = 0;
    char temp[MAX_LENGTH];

    //loop through each character of input string
    for (i = 0; string[i] != '\0'; i++) {
        //if character is alphanumeric or in allowed symbols
        if (isalnum(string[i]) || string[i] == ',' || string[i] == '.' || string[i] == '!' || string[i] == '?') {
            //copy character to temp array and increment index
            temp[j] = string[i];
            j++;
        }
    }
    //add null terminator to temp array and copy back to input string
    temp[j] = '\0';
    strcpy(string, temp);
    return string;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    //remove newline character from input
    input[strcspn(input, "\n")] = '\0';
    //sanitize input and print sanitized string
    printf("Sanitized input: %s", sanitize(input));
    return 0;
}