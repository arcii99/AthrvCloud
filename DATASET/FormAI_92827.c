//FormAI DATASET v1.0 Category: Data validation ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STR_LENGTH 20

bool validate_string(char str[], int length);
bool validate_number(char str[], int length);

int main(void) {
    char my_str[MAX_STR_LENGTH], my_num[MAX_STR_LENGTH];

    printf("Enter a string: ");
    fgets(my_str, MAX_STR_LENGTH, stdin);

    printf("Enter a number: ");
    fgets(my_num, MAX_STR_LENGTH, stdin);

    if (validate_string(my_str, MAX_STR_LENGTH) && validate_number(my_num, MAX_STR_LENGTH)) {
        printf("Both inputs are valid!\n");
    } else {
        printf("At least one input is invalid.\n");
    }

    return 0;
}

bool validate_string(char str[], int length) {
    bool isValid = true;

    for (int i = 0; i < length; i++) {
        if (!isalpha(str[i]) && !isspace(str[i]) && str[i] != '\0') {
            isValid = false;
            break;
        }
    }

    return isValid;
}

bool validate_number(char str[], int length) {
    bool isValid = true;

    for (int i = 0; i < length; i++) {
        if (!isdigit(str[i]) && str[i] != '\n' && str[i] != '\0') {
            isValid = false;
            break;
        }
    }

    return isValid;
}