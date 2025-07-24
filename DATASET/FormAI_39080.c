//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
    // Define password and its length
    char password[50];
    int length, uppercase, lowercase, digits, symbols;
    float score = 0;

    // Ask user for password
    printf("Enter the password: ");
    fgets(password, 50, stdin);
    length = strlen(password) - 1;

    // Calculate password strength
    for(int i = 0; i < length; i++) {
        // Check for uppercase letters
        if(password[i] >= 'A' && password[i] <= 'Z') {
            score += 2;
            uppercase = 1;
        }
        // Check for lowercase letters
        else if(password[i] >= 'a' && password[i] <= 'z') {
            score += 2;
            lowercase = 1;
        }
        // Check for digits
        else if(password[i] >= '0' && password[i] <= '9') {
            score += 1.5;
            digits = 1;
        }
        // Check for symbols
        else {
            score += 3;
            symbols = 1;
        }
    }

    // Deduct score for inadequate length
    if(length < 8) {
        score /= 2;
    }

    // Display password strength and feedback
    printf("\nPassword strength: %.2f\n", score);
    if(score >= 15) {
        printf("Feedback: Strong password\n");
    }
    else if(score >= 10) {
        printf("Feedback: Good password\n");
    }
    else if(score >= 5) {
        printf("Feedback: Weak password\n");
    }
    else {
        printf("Feedback: Very weak password\n");
    }

    // Display password requirements
    printf("Password must meet the following requirements:\n");
    printf("  * At least 8 characters long\n");
    printf("  * Contains at least one uppercase letter\n");
    printf("  * Contains at least one lowercase letter\n");
    printf("  * Contains at least one digit\n");
    printf("  * Contains at least one symbol\n");

    return 0;
}