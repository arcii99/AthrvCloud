//FormAI DATASET v1.0 Category: Data validation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function prototypes
int validate_number(char input[]);
int validate_string(char input[]);

int main() {
    char num_input[MAX_LEN];
    char str_input[MAX_LEN];

    // Validate number input
    printf("Enter a number: ");
    fgets(num_input, MAX_LEN, stdin);
    num_input[strcspn(num_input, "\n")] = '\0';
    while (!validate_number(num_input)) {
        printf("Invalid input. Please enter a number: ");
        fgets(num_input, MAX_LEN, stdin);
        num_input[strcspn(num_input, "\n")] = '\0';
    }

    // Validate string input
    printf("Enter a string: ");
    fgets(str_input, MAX_LEN, stdin);
    str_input[strcspn(str_input, "\n")] = '\0';
    while (!validate_string(str_input)) {
        printf("Invalid input. Please enter a string: ");
        fgets(str_input, MAX_LEN, stdin);
        str_input[strcspn(str_input, "\n")] = '\0';
    }

    printf("Valid input!\n");

    return 0;
}

// Function to validate number input
int validate_number(char input[]) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to validate string input
int validate_string(char input[]) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (!isalpha(input[i])) {
            return 0;
        }
    }

    return 1;
}