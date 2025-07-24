//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 6    // Minimum length of a password
#define MAX_LENGTH 30   // Maximum length of a password
#define STRONG_POINTS 4 // Number of strong password elements required

/* Function to check if the password has at least one uppercase letter */
int has_upper_case(char *password)
{
    for (int i = 0; i < strlen(password); i++)
        if (isupper(password[i]))
            return 1;
    return 0;
}

/* Function to check if the password has at least one lowercase letter */
int has_lower_case(char *password)
{
    for (int i = 0; i < strlen(password); i++)
        if (islower(password[i]))
            return 1;
    return 0;
}

/* Function to check if the password has at least one digit */
int has_digit(char *password)
{
    for (int i = 0; i < strlen(password); i++)
        if (isdigit(password[i]))
            return 1;
    return 0;
}

/* Function to check if the password contains at least one special character */
int has_special(char *password)
{
    for (int i = 0; i < strlen(password); i++)
        if (!isalnum(password[i]))
            return 1;
    return 0;
}

int main()
{
    char password[MAX_LENGTH + 1];
    int points = 0;                                          // Counter for strong password elements
    char c;                                                  // Character buffer for input
    int length = 0;                                          // Counter for password length

    printf("Enter your password: ");
    while ((c = getchar()) != '\n' && length <= MAX_LENGTH)  // Read password character by character
    {
        if (isprint(c))                                     // Only add printable characters to password
            password[length++] = c;
    }
    password[length] = '\0';                                // Terminate the password string

    // Check password strength
    if (strlen(password) < MIN_LENGTH)                      // Too short
        printf("Password is too short. Please use at least %d characters.\n", MIN_LENGTH);
    else                                                    // Length is good
    {
        if (has_upper_case(password))                       // Uppercase letter found
            points++;
        if (has_lower_case(password))                       // Lowercase letter found
            points++;
        if (has_digit(password))                            // Digit found
            points++;
        if (has_special(password))                          // Special character found
            points++;

        if (points >= STRONG_POINTS)                         // Password is strong
            printf("Password is strong. Great job!\n");
        else                                                // Password is weak
            printf("Password is weak. Please use a stronger password.\n");
    }

    return 0;
}