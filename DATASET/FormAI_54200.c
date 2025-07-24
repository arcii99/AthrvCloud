//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, vowels = 0, consonants = 0, digits = 0, spaces = 0;
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else if (str[i] == ' ')
        {
            spaces++;
        }
    }
    printf("\nGiven String: %s", str);
    printf("\nNumber of vowels in the string: %d", vowels);
    printf("\nNumber of consonants in the string: %d", consonants);
    printf("\nNumber of digits in the string: %d", digits);
    printf("\nNumber of spaces in the string: %d", spaces);
    return 0;
}