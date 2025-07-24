//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8 // minimum password length
#define MAX_LENGTH 20 // maximum password length
#define MAX_FAILS 3 // maximum number of allowed password attempts

// function to check if a password is strong
int isStrong(char password[])
{
    int length = strlen(password);

    // check password length
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return 0;
    }

    // count characters
    int num_upper = 0;
    int num_lower = 0;
    int num_digit = 0;
    int num_special = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isupper(c)) {
            num_upper++;
        } else if (islower(c)) {
            num_lower++;
        } else if (isdigit(c)) {
            num_digit++;
        } else if (!isalnum(c)) {
            num_special++;
        }
    }

    // check character counts
    if (num_upper < 1 || num_lower < 1 || num_digit < 1 || num_special < 1) {
        return 0;
    }

    // password is strong
    return 1;
}

// main function to prompt user for password and check strength
int main()
{
    char password[MAX_LENGTH + 1];
    int num_fails = 0; // number of failed password attempts

    // loop until user enters a strong password or exceeds maximum allowed attempts
    while (num_fails < MAX_FAILS) {
        printf("Please enter a password (between %d and %d characters):\n", MIN_LENGTH, MAX_LENGTH);
        if (fgets(password, MAX_LENGTH + 1, stdin) == NULL) {
            printf("Error reading password\n");
            continue;
        }
        password[strcspn(password, "\n")] = '\0'; // remove newline character

        if (isStrong(password)) {
            printf("Your password is strong!\n");
            return 0;
        } else {
            printf("Your password is not strong enough. Please try again.\n");
            num_fails++;
        }
    }

    printf("Sorry, you have exceeded the maximum number of allowed password attempts. Please try again later.\n");
    return 1;
}