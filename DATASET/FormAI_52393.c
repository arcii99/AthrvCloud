//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    int length, upper = 0, lower = 0, digit = 0, symbol = 0;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digit++;
        } else {
            symbol++;
        }
    }

    printf("\nYour password strength is:\n");

    if (length >= 12 && upper >= 2 && lower >= 2 && digit >= 2 && symbol >= 2) {
        printf("Strong\n");
    } else if ((length >= 8 && length < 12) && (upper >= 1 || lower >= 1) && digit >= 1 && symbol >= 1) {
        printf("Moderate\n");
    } else {
        printf("Weak\n");
    }

    return 0;
}