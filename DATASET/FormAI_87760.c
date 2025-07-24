//FormAI DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract words from a given text and return the number of words
int extractWords(char text[], char words[][50])
{
    int i = 0, j = 0, wordCount = 0;

    // Iterate through the text character by character
    while (text[i] != '\0')
    {
        // Check if the current character is a letter
        if ((text[i] >= 'a' && text[i] <= 'z') ||
            (text[i] >= 'A' && text[i] <= 'Z'))
        {
            // Append the letter to the current word
            words[wordCount][j] = text[i];
            j++;
        }

        // Check if the current character is a space or punctuation mark
        else if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ':')
        {
            // Terminate the current word and start a new one
            words[wordCount][j] = '\0';
            wordCount++;
            j = 0;
        }

        // Move to the next character in the text
        i++;
    }

    // Terminate the last word in the text
    words[wordCount][j] = '\0';
    wordCount++;

    return wordCount;
}

// Function to convert a given text to lowercase
void toLowercase(char text[])
{
    int i = 0;

    while (text[i] != '\0')
    {
        // Check if the current character is an uppercase letter
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            // Convert the uppercase letter to lowercase
            text[i] = text[i] - 'A' + 'a';
        }

        // Move to the next character in the text
        i++;
    }
}

int main()
{
    char originalText[500];
    char words[100][50];
    int wordCount;

    // Get the text input from the user
    printf("Enter the text: ");
    fgets(originalText, sizeof(originalText), stdin);

    // Extract the words from the text and get the number of words
    wordCount = extractWords(originalText, words);

    // Convert the original text to lowercase
    toLowercase(originalText);

    // Print the original text
    printf("\nThe original text is:\n%s\n", originalText);

    // Print the extracted words
    printf("The extracted words are:\n");
    for (int i = 0; i < wordCount; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}