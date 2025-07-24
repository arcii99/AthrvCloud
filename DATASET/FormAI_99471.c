//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void validate_input(int num);
void parse_input(char* str_num, int* num);

int main() {
    char str_num[20];

    printf("Enter a number: ");
    fgets(str_num, 20, stdin);

    int num;
    parse_input(str_num, &num);

    validate_input(num);
    
    // Rest of program logic goes here

    return 0;
}

// Validates user input
void validate_input(int num) {
    if(num <= 0) {
        fprintf(stderr, "Error: Invalid input! Number must be greater than 0.\n");
        exit(EXIT_FAILURE);
    }
}

// Parses string input and converts to integer
void parse_input(char* str_num, int* num) {
    char* end;
    
    *num = strtol(str_num, &end, 10);

    // If no conversion error occurred but the entire string was not used
    if(*end != '\0') {
        fprintf(stderr, "Error: Invalid input! Please enter a valid integer.\n");
        exit(EXIT_FAILURE);
    }
}