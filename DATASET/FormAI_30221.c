//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int i, len, digit, upper, lower, spec, score;
    len = strlen(password);

    // Get password score
    digit = 0; upper = 0; lower = 0; spec = 0;
    for (i = 0; i < len; i++)
    {
        if (isdigit(password[i])) digit = 1;
        else if (isupper(password[i])) upper = 1;
        else if (islower(password[i])) lower = 1;
        else if (ispunct(password[i])) spec = 1;
    }
    score = digit + upper + lower + spec;

    // Check if password is strong enough
    if (score >= 3 && len >= 8)
        printf("Password is strong.\n");
    else if (score == 2 && len >= 6)
        printf("Password is moderately strong.\n");
    else
        printf("Password is weak.\n");

    return 0;
}