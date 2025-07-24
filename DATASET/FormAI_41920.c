//FormAI DATASET v1.0 Category: Data validation ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to validate integer input
int validateInteger(char *input)
{
    int i, length = strlen(input);
    if (length == 0)
        return 0;
    for (i = 0; i < length; i++)
    {
        if (!isdigit(input[i]))
            return 0;
    }
    return 1;
}

// function to validate float input
int validateFloat(char *input)
{
    int i, length = strlen(input);
    if (length == 0)
        return 0;
    int dotCount = 0;
    for (i = 0; i < length; i++)
    {
        if (!isdigit(input[i]))
        {
            if (input[i] == '.' && dotCount == 0)
                dotCount++;
            else
                return 0;
        }
    }
    return 1;
}

// function to validate string input
int validateString(char *input)
{
    int i, length = strlen(input);
    if (length == 0)
        return 0;
    for (i = 0; i < length; i++)
    {
        if (!isalpha(input[i]) && !isspace(input[i]))
            return 0;
    }
    return 1;
}

int main()
{
    char choice, input[100];
    int intValue, floatValue;
    do
    {
        printf("Press 1 to validate an integer\n");
        printf("Press 2 to validate a float\n");
        printf("Press 3 to validate a string\n");
        printf("Press 4 to exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
            printf("Enter an integer: ");
            scanf("%s", input);
            if (validateInteger(input))
                printf("Valid integer\n");
            else
                printf("Invalid integer\n");
            break;
        case '2':
            printf("Enter a float: ");
            scanf("%s", input);
            if (validateFloat(input))
                printf("Valid float\n");
            else
                printf("Invalid float\n");
            break;
        case '3':
            printf("Enter a string: ");
            scanf(" %[^\n]s", input);
            if (validateString(input))
                printf("Valid string\n");
            else
                printf("Invalid string\n");
            break;
        case '4':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != '4');
    return 0;
}