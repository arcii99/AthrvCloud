//FormAI DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void reverseString(char* str);
void removeChar(char* str, char c);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string (maximum length of %d): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    char option;
    printf("\nWhat would you like to do with the string?\n1. Reverse the string\n2. Remove a character\nEnter your option (1/2): ");
    scanf(" %c", &option);

    switch(option) {
        case '1':
            printf("\nReversed string: ");
            reverseString(input);
            break;

        case '2':
            char c;
            printf("\nEnter the character you want to remove: ");
            scanf(" %c", &c);
            removeChar(input, c);
            printf("\nModified string: %s", input);
            break;

        default:
            printf("\nInvalid option!");
    }

    return 0;
}

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* temp = (char*)malloc(length * sizeof(char));

    for(int i = 0; i < length; i++) {
        temp[i] = str[length-i-1];
    }

    printf("%s", temp);

    free(temp);
}

// Function to remove a character from a string
void removeChar(char* str, char c) {
    int length = strlen(str);
    int j = 0;

    for(int i = 0; i < length; i++) {
        if(str[i] != c) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}