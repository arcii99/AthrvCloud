//FormAI DATASET v1.0 Category: Data validation ; Style: recursive
#include <stdio.h>
#include <ctype.h>

// Function prototype
int validate(char *str);

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    if (validate(str))
        printf("The string is valid\n");
    else
        printf("The string is invalid\n");

    return 0;
}

int validate(char *str)
{
    if (*str == '\0')
        return 1;

    if (!isdigit(*str))
        return 0;

    return validate(str + 1);
}