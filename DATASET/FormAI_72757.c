//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include <stdio.h>

int main() {
    char password[20];

    printf("Enter password: ");
    scanf("%s", password);

    int len = strlen(password);
    int num_count = 0, letter_count = 0, special_count = 0;

    for (int i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_count++;
        } else if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) {
            letter_count++;
        } else {
            special_count++;
        }
    }

    printf("\nPassword strength: ");

    if (len >= 8 && num_count >= 1 && letter_count >= 1 && special_count >= 1) {
        printf("Strong");
    } else if (len >= 8 && num_count >= 1 && letter_count >= 1) {
        printf("Moderate");
    } else {
        printf("Weak");
    }

    return 0;
}