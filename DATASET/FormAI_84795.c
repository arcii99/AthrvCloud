//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, lower = 0, upper = 0, digit = 0, symbol = 0, strength = 0;
    
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    length = strlen(password) - 1;
    
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower++;
        } else if (isupper(password[i])) {
            upper++;
        } else if (isdigit(password[i])) {
            digit++;
        } else {
            symbol++;
        }
    }
    
    if (length >= 8 && lower > 0 && upper > 0 && digit > 0 && symbol > 0) {
        strength = 4;
    } else if (length >= 8 && lower > 0 && upper > 0 && digit > 0 && symbol == 0) {
        strength = 3;
    } else if (length >= 8 && lower > 0 && upper > 0 && digit == 0 && symbol == 0) {
        strength = 2;
    } else if (length < 8) {
        strength = 1;
    }

    switch (strength) {
        case 1:
            printf("Your password is too weak. It must have at least 8 characters.\n");
            break;
        case 2:
            printf("Your password is weak. It must have digits or symbols.\n");
            break;
        case 3:
            printf("Your password is medium. It must have symbols.\n");
            break;
        case 4:
            printf("Your password is strong. Good job!\n");
            break;
    }
    
    return 0;
}