//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_char = 0, score = 0;

    printf("Enter your password: ");
    fgets(password, 100, stdin);
    length = strlen(password);

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            has_uppercase = 1;
        } else if (islower(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (!isalnum(c)) {
            has_special_char = 1;
        }
    }

    if (has_uppercase) {
        score++;
    }
    if (has_lowercase) {
        score++;
    }
    if (has_digit) {
        score++;
    }
    if (has_special_char) {
        score++;
    }

    printf("Your password strength score is %d out of 4.\n", score);

    switch (score) {
        case 0:
            printf("Are you even trying?!\n");
            break;
        case 1:
            printf("Your password is weak, try adding more characters.\n");
            break;
        case 2:
            printf("Not bad, but there is still room for improvement.\n");
            break;
        case 3:
            printf("A strong password, but you can always add more.\n");
            break;
        case 4:
            printf("Wow, your password is virtually uncrackable!\n");
            break;
        default:
            printf("Oops, something went wrong.\n");
            break;
    }

    return 0;
}