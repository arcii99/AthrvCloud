//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

/* Function to translate Alien language strings */
void translate_alien_language(const char *input_string)
{
    /* Define character map for translation */
    char character_map[26] = "BCDEFGHIJKLMNOPQRSTUVWXYZA";

    /* Get length of input string */
    int input_length = strlen(input_string);

    /* Loop through input string characters */
    for(int i=0; i<input_length; i++)
    {
        /* Check if character is an alphabet */
        if(input_string[i] >= 'A' && input_string[i] <= 'Z')
        {
            /* Translate character using character map */
            printf("%c", character_map[input_string[i] - 'A']);
        }
        else
        {
            /* Print non-alphabetic characters as they are */
            printf("%c", input_string[i]);
        }
    }
    printf("\n");
}

/* Driver code to test Alien Language Translator */
int main()
{
    /* Test cases */
    const char *test_cases[] = {
        "HELLO ALIEN",
        "WE ARE FRIENDS",
        "QWERTYUIOPASDFGHJKLZXCVBNM"
    };

    /* Translate test cases */
    for(int i=0; i<3; i++)
    {
        printf("Original String: %s\n", test_cases[i]);
        printf("Translated String: ");
        translate_alien_language(test_cases[i]);
    }

    return 0;
}