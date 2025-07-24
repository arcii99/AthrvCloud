//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to check whether input is a valid integer
int is_valid_integer(char* input) {
    int length = strlen(input);

    // check if input is negative
    if (input[0] == '-') {
        // check if length is 1 (should not be negative sign on its own)
        if (length == 1) {
            return 0;
        }
        // check if every other character is a digit
        for (int i = 1; i < length; i++) {
            if (!isdigit(input[i])) {
                return 0;
            }
        }
        return 1;
    }
    // else check if every character is a digit
    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// function to check whether input is a valid double
int is_valid_double(char* input) {
    int length = strlen(input);
    int decimal_count = 0;

    // check if input is negative
    if (input[0] == '-') {
        // check if length is 1 (should not be negative sign on its own)
        if (length == 1) {
            return 0;
        }
        // check if every other character is a digit or decimal
        for (int i = 1; i < length; i++) {
            if (input[i] == '.') {
                decimal_count++;
            } else if (!isdigit(input[i])) {
                return 0;
            }
        }
        // check if there is only one decimal point
        if (decimal_count != 1) {
            return 0;
        }
        return 1;
    }
    // else check if every character is a digit or decimal
    for (int i = 0; i < length; i++) {
        if (input[i] == '.') {
            decimal_count++;
        } else if (!isdigit(input[i])) {
            return 0;
        }
    }
    // check if there is only one decimal point
    if (decimal_count != 1) {
        return 0;
    }
    return 1;
}

// function to check whether input is a valid name (only letters and spaces)
int is_valid_name(char* input) {
    int length = strlen(input);

    // check that input is not empty
    if (length == 0) {
        return 0;
    }
    // check that every character is a space or letter
    for (int i = 0; i < length; i++) {
        if (!isalpha(input[i]) && !isspace(input[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    int age;
    double height;
    char name[100];

    // get age input and check if valid
    printf("Enter your age: ");
    fgets(input, 100, stdin);
    while (!is_valid_integer(input)) {
        printf("Invalid input! Please enter a valid age: ");
        fgets(input, 100, stdin);
    }
    age = atoi(input);

    // get height input and check if valid
    printf("Enter your height (in meters): ");
    fgets(input, 100, stdin);
    while (!is_valid_double(input)) {
        printf("Invalid input! Please enter a valid height (in meters): ");
        fgets(input, 100, stdin);
    }
    height = atof(input);

    // get name input and check if valid
    printf("Enter your name: ");
    fgets(name, 100, stdin);
    while (!is_valid_name(name)) {
        printf("Invalid input! Please enter a valid name: ");
        fgets(name, 100, stdin);
    }

    // print out valid information
    printf("Your age is: %d\n", age);
    printf("Your height is: %.2f meters\n", height);
    printf("Your name is: %s", name);
    
    return 0;
}