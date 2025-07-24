//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <string.h>

/* Constant to define maximum password length */
#define MAX_PASSWORD_LENGTH 20

/**
  * Function to validate password:-
  * This function uses a recursive approach to
  * count the number of lowercase, uppercase and
  * special characters in the password.
  * If the password contains at least one lowercase,
  * uppercase letter and a special character, the function
  * will return 1, otherwise, it will return 0.
  */
int validatePassword(char* password, int length, int l_count, int u_count, int s_count)
{
    /* Base case: check if all conditions have been met */
    if (l_count > 0 && u_count > 0 && s_count > 0) {
        return 1;
    }

    /* Base case: length cannot be greater than MAX_PASSWORD_LENGTH */
    if (length > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    /* Recursive case: check the current character for type */
    char c = password[length];
    if (c >= 'a' && c <= 'z') {
        return validatePassword(password, length+1, l_count+1, u_count, s_count);
    } else if (c >= 'A' && c <= 'Z') {
        return validatePassword(password, length+1, l_count, u_count+1, s_count);
    } else if (c == '$' || c == '#' || c == '@') {
        return validatePassword(password, length+1, l_count, u_count, s_count+1);
    } else {
        return validatePassword(password, length+1, l_count, u_count, s_count);
    }
}

int main()
{
    /* Take input from user - password */
    char password[MAX_PASSWORD_LENGTH+1];
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH+1, stdin);

    /* Remove the newline character from the end */
    password[strcspn(password, "\n")] = 0;

    /* Validate the password and print output */
    if (validatePassword(password, 0, 0, 0, 0)) {
        printf("Valid password!\n");
    } else {
        printf("Invalid password!\n");
    }

    return 0;
}