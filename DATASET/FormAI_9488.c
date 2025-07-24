//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int length, upper_count = 0, lower_count = 0, digit_count = 0, special_count = 0;

    printf("Enter your password: ");

    // Read password from user
    scanf("%s", password);

    // Calculate length of password
    length = strlen(password);

    // Check each character for different requirements
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upper_count++;
        }
        else if(password[i] >= 'a' && password[i] <= 'z') {
            lower_count++;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        }
        else {
            special_count++;
        }
    }

    // Print password strength based on requirements met
    printf("\nYour password strength: ");
    if(length < 8 || length > 20) {
        printf("Weak (Length should be between 8 and 20)");
    }
    else if(upper_count == 0 || lower_count == 0) {
        printf("Weak (Include both upper and lower case letters)");
    }
    else if(digit_count == 0 || special_count == 0) {
        printf("Weak (Include both digits and special characters)");
    }
    else {
        printf("Strong");
    }

    return 0;
}