//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Returns 1 if password is strong, 0 otherwise
int isStrongPassword(char *password)
{
    int length = strlen(password);

    if (length < 8) {
        printf("Password is too short!\n");
        return 0;
    }

    int lower = 0, upper = 0, digit = 0, special = 0;

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower = 1;
        } else if (isupper(password[i])) {
            upper = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    if (!lower || !upper || !digit || !special) {
        printf("Password is not strong enough!\n");
        return 0;
    }

    printf("Password is strong. Good job!\n");
    return 1;
}

int main()
{
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int result = isStrongPassword(password);

    return 0;
}