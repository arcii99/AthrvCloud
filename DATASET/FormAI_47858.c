//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to check if the given character is an alphabet or not
int isAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

// Function to check if the given word is spelled correctly or not
int spellCheck(char *word)
{
    char dictionary[][25] = {"apple", "banana", "cherry", "orange", "kiwi", "mango", "peach", "pear", "pineapple", "strawberry"};

    // Convert the given word to lower case
    int len = strlen(word);
    for (int i = 0; i < len; i++)
        word[i] = tolower(word[i]);

    // Check if the word is present in the dictionary
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(dictionary[i], word) == 0)
            return 1;
    }

    return 0;
}

// Main function to test the spell checking functionality
int main()
{
    char input[100];
    printf("Enter a text to check for spelling errors: ");
    fgets(input, 100, stdin);

    // Loop through each character of the input
    int wordStart = -1;
    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];

        // If the current character is an alphabet and it is the first alphabet of a word, mark its starting index
        if (isAlphabet(c) && wordStart == -1)
            wordStart = i;

        // If the current character is not an alphabet and it is not the starting character of a word
        // Then check if the previous word is spelled correctly or not
        if (!isAlphabet(c) && wordStart != -1)
        {
            // Extract the previous word from the input string
            char word[25];
            strncpy(word, &input[wordStart], i - wordStart);
            word[i - wordStart] = '\0';

            // Check if the previous word is spelled correctly or not
            if (!spellCheck(word))
                printf("'%s' is spelled incorrectly.\n", word);

            // Reset the word start index for next word
            wordStart = -1;
        }
    }

    // Check the last word in the input string
    if (wordStart != -1)
    {
        char word[25];
        strncpy(word, &input[wordStart], strlen(input) - wordStart);
        word[strlen(input) - wordStart - 1] = '\0';

        if (!spellCheck(word))
            printf("'%s' is spelled incorrectly.\n", word);
    }

    return 0;
}