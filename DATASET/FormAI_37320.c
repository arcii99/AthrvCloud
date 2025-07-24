//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[25];
    int upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;
    int length, i;

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);

    length = strlen(password);

    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    for (i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            upperCount++;
        } else if (islower(password[i])) {
            lowerCount++;
        } else if (isdigit(password[i])) {
            digitCount++;
        } else {
            specialCount++;
        }
    }

    printf("Password strength: ");

    if (upperCount > 0 && lowerCount > 0 && digitCount > 0 && specialCount > 0) {
        printf("Strong.\n");
    } else if (upperCount > 0 && lowerCount > 0 && digitCount > 0) {
        printf("Moderate.\n");
    } else {
        printf("Weak.\n");
    }

    return 0;
}