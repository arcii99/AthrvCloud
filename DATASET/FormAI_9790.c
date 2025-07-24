//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 8  // Minimum password length
#define MAX_LENGTH 20 // Maximum password length

int main() {
    int length, i, j, choice;
    char password[MAX_LENGTH + 1];
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*()_-+={}[]|\\:;\"'<>,.?/~`";

    srand((unsigned int)time(NULL)); // Initialize random number generator

    printf("Welcome to the Secure Password Generator!\n");
    printf("How long would you like your password to be? (Between %d and %d characters)\n", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Password length must be between %d and %d characters!\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    printf("Would you like the password to contain:\n");
    printf("1. Lowercase letters\n");
    printf("2. Uppercase letters\n");
    printf("3. Digits\n");
    printf("4. Symbols\n");
    printf("5. Lowercase and uppercase letters\n");
    printf("6. Lowercase letters and digits\n");
    printf("7. Lowercase letters and symbols\n");
    printf("8. Uppercase letters and digits\n");
    printf("9. Uppercase letters and symbols\n");
    printf("10. Digits and symbols\n");
    printf("11. Lowercase, uppercase letters and digits\n");
    printf("12. Lowercase letters, digits and symbols\n");
    printf("13. Lowercase, uppercase letters and symbols\n");
    printf("14. Uppercase letters, digits and symbols\n");
    printf("15. All of the above\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 15) {
        printf("Invalid choice. Please choose between 1 and 15.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            for (i = 0; i < length; i++) {
                j = rand() % 26;
                password[i] = lowercase[j];
            }
            break;

        case 2:
            for (i = 0; i < length; i++) {
                j = rand() % 26;
                password[i] = uppercase[j];
            }
            break;

        case 3:
            for (i = 0; i < length; i++) {
                j = rand() % 10;
                password[i] = digits[j];
            }
            break;

        case 4:
            for (i = 0; i < length; i++) {
                j = rand() % 29;
                password[i] = symbols[j];
            }
            break;

        case 5:
            for (i = 0; i < length; i++) {
                j = rand() % 52;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else {
                    password[i] = uppercase[j - 26];
                }
            }
            break;

        case 6:
            for (i = 0; i < length; i++) {
                j = rand() % 36;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else {
                    password[i] = digits[j - 26];
                }
            }
            break;

        case 7:
            for (i = 0; i < length; i++) {
                j = rand() % 31;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else {
                    password[i] = symbols[j - 26];
                }
            }
            break;

        case 8:
            for (i = 0; i < length; i++) {
                j = rand() % 36;
                if (j < 26) {
                    password[i] = uppercase[j];
                } else {
                    password[i] = digits[j - 26];
                }
            }
            break;

        case 9:
            for (i = 0; i < length; i++) {
                j = rand() % 31;
                if (j < 26) {
                    password[i] = uppercase[j];
                } else {
                    password[i] = symbols[j - 26];
                }
            }
            break;

        case 10:
            for (i = 0; i < length; i++) {
                j = rand() % 23;
                password[i] = symbols[j];
            }
            break;

        case 11:
            for (i = 0; i < length; i++) {
                j = rand() % 62;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else if (j < 52) {
                    password[i] = uppercase[j - 26];
                } else {
                    password[i] = digits[j - 52];
                }
            }
            break;

        case 12:
            for (i = 0; i < length; i++) {
                j = rand() % 36;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else if (j < 30) {
                    password[i] = digits[j - 26];
                } else {
                    password[i] = symbols[j - 30];
                }
            }
            break;

        case 13:
            for (i = 0; i < length; i++) {
                j = rand() % 57;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else if (j < 52) {
                    password[i] = uppercase[j - 26];
                } else {
                    password[i] = symbols[j - 52];
                }
            }
            break;

        case 14:
            for (i = 0; i < length; i++) {
                j = rand() % 36;
                if (j < 26) {
                    password[i] = uppercase[j];
                } else if (j < 30) {
                    password[i] = digits[j - 26];
                } else {
                    password[i] = symbols[j - 30];
                }
            }
            break;

        case 15:
            for (i = 0; i < length; i++) {
                j = rand() % 75;
                if (j < 26) {
                    password[i] = lowercase[j];
                } else if (j < 52) {
                    password[i] = uppercase[j - 26];
                } else if (j < 62) {
                    password[i] = digits[j - 52];
                } else {
                    password[i] = symbols[j - 62];
                }
            }
            break;
    }

    password[length] = '\0'; // Null-terminate the password string

    printf("Your password is: %s\n", password);

    return 0;
}