//FormAI DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to future-proof style
char* convertToLower(char* str) {
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') {
           str[i] += 32;    // converting uppercase to lowercase using ASCII codes
        }
    }
    return str;
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);    // read input from user
    inputString[strcspn(inputString, "\n")] = '\0';    // remove newline character

    char* lowerString = convertToLower(inputString);    // converting string to lowercase

    printf("Lowercase string: %s\n", lowerString);

    return 0;
}