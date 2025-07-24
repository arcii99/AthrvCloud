//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>

void wordCount(char *);

int main()
{
    char input[1000];

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    printf("\n");
    wordCount(input);

    return 0;
}

void wordCount(char *input)
{
    int i;
    int word = 1;
    int vowel = 0;
    int consonant = 0;
    int specialChar = 0;

    //converting all characters to lowercase
    for (i = 0; input[i] != '\0'; i++)
    {
        input[i] = tolower(input[i]);
    }

    for (i = 0; input[i] != '\n'; i++)
    {
        if (input[i] == ' ' || input[i] == '\t')
        {
            word++;
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
                input[i] == 'o' || input[i] == 'u')
            {
                vowel++;
            }
            else
            {
                consonant++;
            }
        }
        else
        {
            specialChar++;
        }
    }

    printf("Number of Words: %d\n", word);
    printf("Number of Vowels: %d\n", vowel);
    printf("Number of Consonants: %d\n", consonant);
    printf("Number of Special Characters: %d\n", specialChar);
}