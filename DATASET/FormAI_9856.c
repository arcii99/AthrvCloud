//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
/* This program processes text entered by the user and performs various operations on it. */

#include<stdio.h>
#include<ctype.h>

int main()
{
    char text[1000], ch;
    int i, vowels = 0, consonants = 0, digits = 0, spaces = 0, special = 0;

    // Get input text from user
    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);

    // Convert text to uppercase
    for(i = 0; text[i] != '\0'; i++)
    {
        ch = toupper(text[i]);

        // Count number of vowels, consonants, digits, spaces and special characters
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
        else if((ch >= 'A' && ch <= 'Z'))
        {
            consonants++;
        }
        else if(ch >= '0' && ch <= '9')
        {
            digits++;
        }
        else if(ch == ' ')
        {
            spaces++;
        }
        else
        {
            special++;
        }
    }

    // Print the results
    printf("\nYour input text: %s", text);
    printf("\nNumber of vowels: %d", vowels);
    printf("\nNumber of consonants: %d", consonants);
    printf("\nNumber of digits: %d", digits);
    printf("\nNumber of spaces: %d", spaces);
    printf("\nNumber of special characters: %d", special);

    return 0;
}