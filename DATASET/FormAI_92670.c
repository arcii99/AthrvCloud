//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

bool is_valid_integer(char* str) {
    if (*str == '\0') {
        return false;
    }
    if (*str == '-') {
        str++;
    }
    while (*str != '\0') {
        if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

bool is_valid_float(char* str) {
    if (*str == '\0') {
        return false;
    }
    if (*str == '-') {
        str++;
    }
    bool has_dot = false;
    while (*str != '\0') {
        if (*str == '.') {
            if (has_dot) {
                return false;
            } else {
                has_dot = true;
            }
        } else if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

bool is_valid_string(char* str) {
    if (*str == '\0') {
        return false;
    }
    while (*str != '\0') {
        if (!isalpha(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter an integer: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    while (!is_valid_integer(input)) {
        printf("Invalid input. Try again: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
    }
    int num = atoi(input);
    printf("Valid input: %d\n", num);

    printf("Enter a float: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    while (!is_valid_float(input)) {
        printf("Invalid input. Try again: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
    }
    float fnum = atof(input);
    printf("Valid input: %f\n", fnum);

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    while (!is_valid_string(input)) {
        printf("Invalid input. Try again: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
    }
    printf("Valid input: %s\n", input);

    return 0;
}