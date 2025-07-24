//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool validate_number(char* number_str) {
    int length = strlen(number_str);
    if (length == 0) {
        printf("ERROR: Empty input");
        return false;
    }

    int dot_count = 0;
    for (int i = 0; i < length; i++) {
        if (i == 0 && (number_str[i] == '-' || number_str[i] == '+')) {
            continue;
        }

        if (!isdigit(number_str[i])) {
            if (number_str[i] == '.' && dot_count == 0) {
                dot_count++;
            } else {
                printf("ERROR: Invalid input");
                return false;
            }
        }
    }

    return true;
}

int main() {
    char number_str[32];
    printf("Enter a number: ");
    fgets(number_str, 32, stdin);

    if (validate_number(number_str)) {
        double number = strtod(number_str, NULL);
        printf("The input is a valid number: %g", number);
    }

    return 0;
}