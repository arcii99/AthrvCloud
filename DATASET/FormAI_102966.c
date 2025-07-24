//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h> // Standard Input/Output library
#include <stdlib.h> // Standard library
#include <string.h> // String library

// This program will take a sentence as input and convert it into a happy sentence.

void happy_sentence(char *str)
{
    char *word;
    word = strtok(str, " "); // Tokenize the sentence into different words.

    while (word != NULL) // Loop through each word until there are no more words.
    {
        if (strcmp(word, "sad") == 0) // If the word is "sad", replace it with "happy" using strcmp function.
        {
            printf("happy ");
        }
        else if (strcmp(word, "unhappy") == 0) // If the word is "unhappy", replace it with "joyful".
        {
            printf("joyful ");
        }
        else if (strcmp(word, "depressed") == 0) // If the word is "depressed", replace it with "excited".
        {
            printf("excited ");
        }
        else if (strcmp(word, "angry") == 0) // If the word is "angry", replace it with "calm".
        {
            printf("calm ");
        }
        else if (strcmp(word, "frown") == 0) // If the word is "frown", replace it with "smile".
        {
            printf("smile ");
        }
        else
        {
            printf("%s ", word); // If the word is not any of the above, print it as it is.
        }
        word = strtok(NULL, " "); // Move to the next word in the sentence.
    }
}

int main(void)
{
    char str[100]; // Define a character array to store the input sentence.
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin); // Read the input sentence.

    happy_sentence(str); // Call the function to convert the sentence into a happy sentence.

    return 0;
}