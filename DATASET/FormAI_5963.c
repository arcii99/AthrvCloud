//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Check if input is a valid integer
int is_integer(char* input) {
    int len = strlen(input);
    if (len == 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(*(input+i))) {
            return 0;
        }
    }
    return 1;
}

// Check if input is a valid float
int is_float(char* input) {
    int len = strlen(input);
    if (len == 0) {
        return 0;
    }
    int decimal_found = 0;
    for (int i = 0; i < len; i++) {
        if (*(input+i) == '.') {
            if (decimal_found) {
                return 0;
            } else {
                decimal_found = 1;
            }
        } else if (!isdigit(*(input+i))) {
            return 0;
        }
    }
    return 1;
}

// Check if input is a valid email
int is_email(char* input) {
    int len = strlen(input);
    if (len == 0) {
        return 0;
    }
    int at_found = 0;
    int dot_found = 0;
    for (int i = 0; i < len; i++) {
        if (*(input+i) == '@') {
            if (at_found) {
                return 0;
            } else {
                at_found = 1;
            }
        } else if (*(input+i) == '.') {
            if (dot_found) {
                return 0;
            } else {
                dot_found = 1;
            }
        }
    }
    return (at_found && dot_found);
}

// Check if input is a valid date
int is_date(char* input) {
    int len = strlen(input);
    if (len != 10) {
        return 0;
    }
    int slash_count = 0;
    for (int i = 0; i < len; i++) {
        if (i == 2 || i == 5) {
            // Check for slashes
            if (*(input+i) != '/') {
                return 0;
            } else {
                slash_count++;
            }
        } else {
            // Check for digits
            if (!isdigit(*(input+i))) {
                return 0;
            }
        }
    }
    return (slash_count == 2);
}

// Main function for testing
int main() {
    // Test integer validation
    char int_input[10] = "12345";
    if (is_integer(int_input)) {
        printf("%s is a valid integer.\n", int_input);
    } else {
        printf("%s is not a valid integer.\n", int_input);
    }

    // Test float validation
    char float_input[10] = "123.45";
    if (is_float(float_input)) {
        printf("%s is a valid float.\n", float_input);
    } else {
        printf("%s is not a valid float.\n", float_input);
    }

    // Test email validation
    char email_input[30] = "test@example.com";
    if (is_email(email_input)) {
        printf("%s is a valid email.\n", email_input);
    } else {
        printf("%s is not a valid email.\n", email_input);
    }

    // Test date validation
    char date_input[20] = "31/12/2022";
    if (is_date(date_input)) {
        printf("%s is a valid date.\n", date_input);
    } else {
        printf("%s is not a valid date.\n", date_input);
    }

    return 0;
}