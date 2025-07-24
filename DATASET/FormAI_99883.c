//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>

#define MAX_STRING_LENGTH 100

int is_spam(char *string, int string_length);

int main()
{
    char string[MAX_STRING_LENGTH];
    int string_length;

    printf("Enter the string: ");
    fgets(string, MAX_STRING_LENGTH, stdin);

    string_length = strlen(string);

    if (is_spam(string, string_length))
    {
        printf("Spam detected.\n");
    }
    else
    {
        printf("No spam detected.\n");
    }

    return 0;
}

int is_spam(char *string, int string_length)
{
    if (string_length == 0)
    {
        return 0;
    }

    if (strstr(string, "buy") != NULL ||
        strstr(string, "discount") != NULL ||
        strstr(string, "free") != NULL ||
        strstr(string, "money") != NULL ||
        strstr(string, "spam") != NULL ||
        strstr(string, "win") != NULL)
    {
        return 1;
    }

    int res = is_spam(string + 1, string_length - 1);

    return res;
}