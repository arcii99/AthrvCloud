//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// This program demonstrates how to sanitize user input in C

// A function to clear the input buffer
void clearInputBuffer() {
    int c = 0;
    while((c = getchar()) != EOF && c != '\n');
}

// A function to sanitize user input
void sanitizeInput(char* input) {
    // Replace all non-alphanumeric characters with a space
    for(int i = 0; i < strlen(input); i++) {
        if(!isalnum(input[i])) {
            input[i] = ' ';
        }
    }
    // Remove leading and trailing spaces
    char* start = input;
    while(*start == ' ') {
        start++;
    }
    char* end = input + strlen(input) - 1;
    while(end > start && *end == ' ') {
        end--;
    }
    *(end+1) = '\0';
    strcpy(input, start);
}

int main() {
    char input[100];
    printf("Welcome to the User Input Sanitizer program!\n");
    printf("Please enter a string containing non-alphanumeric characters: ");
    fgets(input, sizeof(input), stdin);
    sanitizeInput(input);
    printf("Your sanitized input is: %s", input);
    return 0;
}