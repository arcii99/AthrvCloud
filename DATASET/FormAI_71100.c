//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, i, char_type, ascii_value;
    char password[50] = "";
    srand(time(NULL));

    printf("Enter length of password: ");
    scanf("%d", &length);

    while (length < 6 || length > 50) {
        printf("Invalid length. Please enter a length between 6 and 50: ");
        scanf("%d", &length);
    }

    printf("\nPassword: ");

    for (i = 0; i < length; i++) {
        char_type = rand() % 4;

        if (char_type == 0) { // Uppercase letter
            ascii_value = rand() % 26 + 65;
            password[i] = (char)ascii_value;
        } else if (char_type == 1) { // Lowercase letter
            ascii_value = rand() % 26 + 97;
            password[i] = (char)ascii_value;
        } else if (char_type == 2) { // Number
            ascii_value = rand() % 10 + 48;
            password[i] = (char)ascii_value;
        } else { // Special character
            ascii_value = rand() % 15 + 33;
            password[i] = (char)ascii_value;
        }

        printf("%c", password[i]);
    }

    printf("\n");
    return 0;
}