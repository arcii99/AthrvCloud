//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a string (ending with a '.'): ");
    scanf("%[^\n]%*c", str); // reads input until newline char is encountered

    printf("\nYou entered: %s\n", str);

    int vowels = 0, consonants = 0, digits = 0, symbols = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '.'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            char ch = str[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
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
        else
        {
            symbols++;
        }
    }

    printf("\nTotal vowels: %d", vowels);
    printf("\nTotal consonants: %d", consonants);
    printf("\nTotal digits: %d", digits);
    printf("\nTotal symbols: %d", symbols);

    return 0;
}