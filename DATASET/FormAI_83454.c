//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length = 0, numCount = 0, charCount = 0, i = 0;
    char password[100], specialChars[11] = "!@#$%^&*()";
    srand(time(0));

    printf("Please enter the desired length of the password (minimum 8): ");
    scanf("%d", &length);

    if (length < 8)
    {
        printf("\nError: password length should be at least 8.\n");
        return 1;
    }

    printf("Do you want to include numbers in the password? (Enter 1 for Yes or 0 for No): ");
    scanf("%d", &numCount);

    printf("Do you want to include special characters in the password? (Enter 1 for Yes or 0 for No): ");
    scanf("%d", &charCount);

    while (i < length)
    {
        int randomChar = rand() % 75 + 48;

        if ((randomChar >= 48 && randomChar <= 57 && numCount) || (randomChar >= 65 && randomChar <= 90) || (randomChar >= 97 && randomChar <= 122) || (randomChar >= 33 && randomChar <= 47 && charCount))
        {
            password[i] = (char) randomChar;
            i++;
        }
    }

    printf("\nYour secure password is: %s\n", password);

    return 0;
}