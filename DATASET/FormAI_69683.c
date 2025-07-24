//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include<stdio.h>
#include<string.h>

// function to check if a given word is spelled correctly
int spellCheck(char *word)
{
    // dictionary of correct words
    char *dictionary[] = {"hello", "world", "programming", "language", "computer", "science", "algorithm", "data", "structure"};
    int dictSize = 9;

    // compare given word with each word in the dictionary
    for(int i = 0; i < dictSize; i++)
    {
        if(strcmp(word, dictionary[i]) == 0)
        {
            return 1; // word found in dictionary, spelling is correct
        }
    }

    return 0; // word not found in dictionary, spelling is incorrect
}

int main()
{
    char word[50];

    // read input from user
    printf("Enter a word to spell check: ");
    scanf("%s", word);

    // check if the given word is spelled correctly
    int isCorrect = spellCheck(word);

    // display the result
    if(isCorrect)
        printf("Spelling is correct!");
    else
        printf("Spelling is incorrect!");

    return 0;
}