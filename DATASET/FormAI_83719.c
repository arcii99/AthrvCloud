//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    printf("Greetings adventurer! Please enter your secret password:\n");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            has_lower = 1;
        }
        else if (isupper(password[i]))
        {
            has_upper = 1;
        }
        else if (isdigit(password[i]))
        {
            has_digit = 1;
        }
        else
        {
            has_special = 1;
        }
    }

    if (length < 8)
    {
        printf("Beware, thy password is weak and easy to guess. It must be at least 8 characters long. Thy password is rejected!\n");
    }
    else if (length >= 8 && has_upper && has_lower && has_digit && has_special)
    {
        printf("Well done, thy password is strong and secure. Keep it safe!\n");
    }
    else
    {
        printf("Meh, thy password is quite weak. Thou should add uppercase, lowercase, digits and special characters to make it stronger. Thy password is rejected!\n");
    }

    return 0;
}