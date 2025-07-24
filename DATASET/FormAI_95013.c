//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {

    char password[50];
    int uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_count = 0;
    bool has_uppercase = false, has_lowercase = false, has_digit = false, has_special = false;
    bool is_long_enough = false;
    
    printf("Enter a password: ");
    scanf("%s", password);

    int length = strlen(password);

    if (length >= 8) {
        is_long_enough = true;
    }

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (isupper(c)) {
            has_uppercase = true;
            uppercase_count++;
        } else if (islower(c)) {
            has_lowercase = true;
            lowercase_count++;
        } else if (isdigit(c)) {
            has_digit = true;
            digit_count++;
        }  else {
            has_special = true;
            special_count++;
        }
    }

    printf("Password Strength Report:\n");
    printf("Length: %s\n", is_long_enough ? "Pass" : "Fail");
    printf("Uppercase Letters: %s (%d/%d)\n", has_uppercase ? "Pass" : "Fail", uppercase_count, length);
    printf("Lowercase Letters: %s (%d/%d)\n", has_lowercase ? "Pass" : "Fail", lowercase_count, length);
    printf("Digits: %s (%d/%d)\n", has_digit ? "Pass" : "Fail", digit_count, length);
    printf("Special Characters: %s (%d/%d)\n", has_special ? "Pass" : "Fail", special_count, length);
    
    return 0;
}