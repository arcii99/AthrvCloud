//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Function to check if a word is spelled correctly
int checkSpelling(char *word)
{
    char dictionary[][20] = {"apple", "banana", "cherry", "orange", "peach", "pear", "strawberry", "watermelon"};
    int numWords = sizeof(dictionary) / sizeof(dictionary[0]);
    int i;
    for (i = 0; i < numWords; ++i) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    char word[20];
    printf("Welcome to the Cheerful Spell Checker!\n");
    printf("Enter a word to see if it is spelled correctly: ");

    // Get word from user
    scanf("%s", word);

    // Check spelling
    if (checkSpelling(word) == 1) {
        printf("Great news! The word \"%s\" is spelled correctly. Keep up the good work!\n", word);
    } else {
        printf("Oops! The word \"%s\" is spelled incorrectly. Don't worry, we can help you fix it!\n", word);
    }
    
    return 0;
}