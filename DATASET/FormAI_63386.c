//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

void santitize(char *input);

int main() {
    char input[MAX_STRING_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    santitize(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}

void santitize(char *input) {
    int i = 0, j = 0;
    char temp[MAX_STRING_LENGTH];
    while(input[i] != '\0') {
        if(isalnum(input[i])) {
            temp[j] = input[i];
            j++;
        }
        i++;
    }
    temp[j] = '\0';
    if(strcmp(input, temp) != 0) {
        strcpy(input, temp);
        santitize(input);
    }
}

/*
example:
Enter your input: He!@llo Wo@rld
Sanitized input: HelloWorld
*/