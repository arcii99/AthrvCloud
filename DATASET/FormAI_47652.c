//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_strength(char password[]) {
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, special = 0;

    for(int i = 0; i < length; i++) {
        if(isupper(password[i])) {
            uppercase++;
        }
        else if(islower(password[i])) {
            lowercase++;
        }
        else if(isdigit(password[i])) {
            digit++;
        }
        else {
            special++;
        }
    }

    if(length < 8 || (length < 12 && special < 1) ||
       (length < 16 && (uppercase < 1 || lowercase < 1))) {
        printf("Your password is weak, try adding more characters\n");
    }
    else if(length < 12 || (length < 16 && special < 1) || 
            (length < 20 && (uppercase < 1 || lowercase < 1))) {
        printf("Your password is medium strength, but could still be improved\n");
    }
    else {
        printf("Your password is strong and secure, congratulations!\n");
    }
}

int main() {
    char password[50];
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter a password to check: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;

    check_strength(password);
    
    return 0;
}