//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3
#define MAX_PASSWORD_SIZE 20

int main()
{
    int attempts = 0;
    char password[MAX_PASSWORD_SIZE];
    char secret_key[] = "retrostyle";
    int len_secret_key = strlen(secret_key);
    int failed_attempts[MAX_PASSWORD_SIZE] = {0};

    while (attempts < MAX_ATTEMPTS)
    {
        printf("Enter the password: ");
        scanf("%s", password);

        int len_password = strlen(password);

        if (len_password > MAX_PASSWORD_SIZE)
        {
            printf("Password too long, please keep it under %d characters.\n", MAX_PASSWORD_SIZE);
            continue;
        }

        int i, j;
        for (i = 0; i < len_password; i++)
        {
            int found = 0;
            for (j = 0; j < len_secret_key; j++)
                if (password[i] == secret_key[j])
                    found = 1;

            if (!found)
            {
                failed_attempts[i]++;
                if (failed_attempts[i] > 2)
                {
                    printf("Intrusion detected!\n");
                    exit(0);
                }
            }
        }

        if (strcmp(password, secret_key) == 0)
        {
            printf("Access granted.\n");
            break;
        }
        else
        {
            printf("Access denied.\n");
            attempts++;
        }
    }

    return 0;
}