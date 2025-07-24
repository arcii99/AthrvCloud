//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase = 0, lowercase = 0, number = 0, special = 0;
    
    printf("Please enter a password: ");
    fgets(password, sizeof(password), stdin);  // Read user input
    
    length = strlen(password) - 1; // exclude newline character from the input string
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        }
        if (islower(password[i])) {
            lowercase++;
        }
        if (isdigit(password[i])) {
            number++;
        }
        if (!isalnum(password[i])) {
            special++;
        }
    }
    
    printf("Password length: %d\n", length);

    if (length < 8) {
        printf("Password strength: Weak\n");
        printf("* Password should contain at least 8 characters.\n");
    } else {
        printf("Password strength: Moderate\n");
    }
    
    if (length >= 12) {
        printf("Password strength: Strong\n");
    }
    
    if (uppercase == 0 || lowercase == 0) {
        printf("* Password should contain both uppercase and lowercase letters.\n");
    }
    
    if (number == 0) {
        printf("* Password should contain at least one digit.\n");
    }
    
    if (special == 0) {
        printf("* Password should contain at least one special character.\n");
    }
    
    return 0;
}