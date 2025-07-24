//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char password[15];
    int score = 0, length, uppercase = 0, lowercase = 0, digit = 0, special_char = 0;

    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password (max 15 characters): ");
    scanf("%s", &password);

    length = strlen(password);

    if (length < 8) {
        printf("Your password is too short! It should be at least 8 characters long.\n");
        return 0;
    }
    else if (length > 15) {
        printf("Your password is too long! It should be at most 15 characters long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (password[i] >= 65 && password[i] <= 90) 
            uppercase++;
        else if (password[i] >= 97 && password[i] <= 122)
            lowercase++;
        else if (password[i] >= 48 && password[i] <= 57)
            digit++;
        else
            special_char++;
    }

    score = uppercase + lowercase + digit + special_char;

    if (score < 15)
        printf("Your password is weak. It has a score of %d out of 15.\n", score);
    else if (score < 22)
        printf("Your password is moderate. It has a score of %d out of 22.\n", score);
    else
        printf("Your password is strong. It has a score of %d out of 28.\n", score);

    return 0;
}