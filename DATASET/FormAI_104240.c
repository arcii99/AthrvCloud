//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    char password[30];
    int lowercase, uppercase, digit, special, len;
    int strength = 0;

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);

    len = strlen(password) - 1; // fgets adds a newline character, so we subtract 1 from the length

    for (int i = 0; i < len; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase = 1;
            strength++;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase = 1;
            strength++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
            strength++;
        }
        else
        {
            special = 1;
            strength += 2;
            // Special characters increase strength by 2
        }
    }

    if (len >= 10 && lowercase && uppercase && digit && special)
    {
        printf("Strong password.\n");
    }
    else if ((len >= 8 && len < 10) && (lowercase || uppercase) && digit && special)
    {
        printf("Moderate password.\n");
    }
    else
    {
        printf("Weak password.\n");
    }

    printf("Password Strength: %d\n", strength);

    return 0;
}