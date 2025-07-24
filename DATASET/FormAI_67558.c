//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[50];
    int length, uppercase_count = 0, lowercase_count = 0, digit_count = 0, special_count = 0, strength_score = 0;

    printf("Enter the password to evaluate: ");
    scanf("%s", password);

    length = strlen(password);

    // Check length
    if (length < 8) {
        printf("\nPassword is too short. Minimum length is 8 characters");
        return 0;
    }

    // Check character types
    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            uppercase_count++;
        else if (islower(password[i]))
            lowercase_count++;
        else if (isdigit(password[i]))
            digit_count++;
        else
            special_count++;
    }

    // Calculate strength score
    strength_score = ((uppercase_count + lowercase_count) * digit_count) * special_count;

    printf("\nPassword strength score: %d", strength_score);

    // Determine strength level
    if (strength_score < 10000)
        printf("\nPassword is weak. Please try again with a stronger password.");
    else if (strength_score < 50000)
        printf("\nPassword is moderate. Consider adding more complexity for extra security.");
    else
        printf("\nPassword is strong. Congratulations!");

    return 0;
}