//FormAI DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
    char email[MAX_SIZE];
    int count = 0;

    printf("Enter an email: ");
    fgets(email, MAX_SIZE, stdin);

    char *ptr = strstr(email, "spam");
    if (ptr != NULL)
    {
        count++;
    }

    int len = strlen(email);
    for (int i = 0; i < len; i++)
    {
        if (email[i] == '!')
        {
            count++;
        }
    }

    if (count > 0)
    {
        printf("This email contains spam.");
    }
    else
    {
        printf("This email does not contain spam.");
    }

    return 0;
}