//FormAI DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count number of words in a string
int countWords(char *str)
{
    int count = 0;
    char *token = strtok(str, " "); // Split string by space
    while (token != NULL)
    {
        count++; // increment word count
        token = strtok(NULL, " ");
    }
    return count;
}

int main()
{
    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter a sentence to count the number of words:\n");

    char sentence[100];
    fgets(sentence, sizeof(sentence), stdin); // Get user input string
    sentence[strlen(sentence) - 1] = '\0'; // Remove newline character from string

    int wordCount = countWords(sentence); // Call function to count number of words
    printf("Number of words: %d\n", wordCount);

    printf("Thank you for using the C Word Count Tool! Have a great day!\n");

    return 0;
}