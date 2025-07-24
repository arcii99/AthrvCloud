//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    printf("Welcome to the User Input Sanitizer program!\n");
    printf("This program will take in user input and remove any non-alphanumeric characters.\n");

    char input[100];

    printf("\nEnter an input string: ");
    fgets(input, 100, stdin);
    int i;
    for (i = 0; input[i]; i++)
    {
        if (!isalnum(input[i]))
        {
            input[i] = '\0';
        }
    }

    printf("\nSanitized input: %s\n", input);
    printf("Thank you for using the User Input Sanitizer program! Have a great day!");

    return 0;
}