//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i;
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_symbol = 0;
    printf("Enter a password: ");
    scanf("%[^\n]", password);
    length = strlen(password);

    for(i = 0; i < length; i++) {
        if(isupper(password[i])) {
            has_uppercase = 1;
        } else if(islower(password[i])) {
            has_lowercase = 1;
        } else if(isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_symbol = 1;
        }
    }

    if(length >= 8 && has_uppercase && has_lowercase && has_digit && has_symbol) {
        printf("Great Job! Password is Strong.");
    } else if(length >= 6 && (has_uppercase || has_lowercase) && has_digit) {
        printf("Good Job! The password is medium in strength.");
    } else {
        printf("Weak Password. Please use a combination of uppercase, lowercase, digits and symbols to make it complex.");
    }

    return 0;
}