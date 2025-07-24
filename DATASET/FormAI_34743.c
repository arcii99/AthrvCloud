//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize(char *input) {
    char *temp = input; // create a copy of input string
    while(*temp) {
        if(!isalnum(*temp)) {//if character is not alphanumeric
            memmove(temp, temp+1, strlen(temp)); //move the next character to current
        } 
        else {
            temp++; // move to the next character
        }
    }
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, 100, stdin);
    sanitize(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}