//FormAI DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initializing variables
    char str[100], newStr[100];
    int len, i, j, k, l, m;

    // Getting input from user
    printf("Enter a string:\n");
    fgets(str, 100, stdin);

    // Removing spaces from string
    len = strlen(str);
    for (i = 0, j = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';

    // Reversing the string
    len = strlen(newStr);
    for (k = 0, l = len - 1; k < len / 2; k++, l--)
    {
        char temp = newStr[k];
        newStr[k] = newStr[l];
        newStr[l] = temp;
    }

    // Counting vowel and consonant
    int vowel_count = 0, consonant_count = 0;
    len = strlen(newStr);
    for (m = 0; m < len; m++)
    {
        if (newStr[m] == 'a' || newStr[m] == 'e' || newStr[m] == 'i' || newStr[m] == 'o' || newStr[m] == 'u')
        {
            vowel_count++;
        }
        else
        {
            consonant_count++;
        }
    }

    // Displaying the final manipulated string
    printf("The manipulated string is:\n%s\n", newStr);
    printf("Number of vowels: %d\n", vowel_count);
    printf("Number of consonants: %d\n", consonant_count);

    return 0;
}