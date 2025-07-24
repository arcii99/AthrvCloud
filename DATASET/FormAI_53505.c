//FormAI DATASET v1.0 Category: Data validation ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

bool is_valid_string(char string[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (!isalnum(string[i]) && !isspace(string[i])) {
            return false;
        }
    }
    return true;
}

bool is_valid_number(char string[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (!isdigit(string[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char name[MAX_STRING_LENGTH];
    char age_string[MAX_STRING_LENGTH];
    int age;
    bool valid_name = false;
    bool valid_age = false;

    printf("Enter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    while (!valid_name) {
        if (is_valid_string(name, strlen(name))) {
            valid_name = true;
        } else {
            printf("Invalid name, please enter again: ");
            fgets(name, MAX_STRING_LENGTH, stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline character
        }
    }

    printf("Enter your age: ");
    fgets(age_string, MAX_STRING_LENGTH, stdin);
    age_string[strcspn(age_string, "\n")] = 0; // Remove newline character

    while (!valid_age) {
        if (is_valid_number(age_string, strlen(age_string))) {
            age = atoi(age_string);
            valid_age = true;
        } else {
            printf("Invalid age, please enter again: ");
            fgets(age_string, MAX_STRING_LENGTH, stdin);
            age_string[strcspn(age_string, "\n")] = 0; // Remove newline character
        }
    }

    printf("Hello %s, your age is %d.\n", name, age);

    return 0;
}