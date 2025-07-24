//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char input[50];
    bool valid = false;
    int value;

    while (!valid)
    {
        printf("Enter a number: ");
        fgets(input, sizeof(input), stdin);

        // Check if each character is a digit
        int i;
        for (i = 0; input[i] != '\0'; i++)
        {
            if (!isdigit(input[i]))
            {
                printf("Invalid input. Please enter a number.\n");
                break;
            }
        }

        // If all characters are digits, convert to an integer
        if (input[i] == '\0')
        {
            value = atoi(input);
            valid = true;
        }
    }

    printf("Valid input: %d\n", value);

    return 0;
}