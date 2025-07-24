//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int len, strength = 0, alphabets = 0, numbers = 0, special_chars = 0;
    
    printf("My dear, please enter the password you want to check: ");
    fgets(password, 100, stdin);
    len = strlen(password)-1; // fgets adds a newline character at the end
    
    for (int i=0; i<len; i++) {
        if (isalpha(password[i])) {
            alphabets++;
            if (isupper(password[i])) {
                strength++;
            }
        }
        else if (isdigit(password[i])) {
            numbers++;
            strength++;
        }
        else if (ispunct(password[i])) {
            special_chars++;
            strength++;
        }
    }
    
    if (len >= 8 && strength >= 3 && alphabets >= 1 && numbers >= 1 && special_chars >= 1) {
        printf("Oh my love, your password is strong enough to protect our love forever!\n");
    }
    else {
        printf("My dear, your password is weak! Please try again with a stronger one.");
    }

    return 0;
}