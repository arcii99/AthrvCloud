//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <string.h>

void removeSpaces(char *str); // Function prototype.

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin); // Read string input from user.

    removeSpaces(str); // Call function to remove spaces.

    printf("String after removing spaces: %s", str); // Print the string without spaces.

    return 0;
}

void removeSpaces(char *str)
{
    int i, j;
    for (i = 0; str[i]; i++)
    {
        while (str[i] == ' ')
        {
            for (j = i; str[j]; j++)
                str[j] = str[j + 1]; // Shifts the characters left by 1 position.
        }
    }
}