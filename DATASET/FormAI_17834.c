//FormAI DATASET v1.0 Category: Text processing ; Style: content
// This program is a basic text processing example that takes user input, counts the number of words in the input, 
// replaces a specific word with another word and displays the modified text.

#include <stdio.h>
#include <string.h>

int main()
{
    char input_text[1000];    // Declare a char array to store user input text
    char search_word[20];     // Declare a char array to store the word to search
    char replace_word[20];    // Declare a char array to store the replacement word
    int word_count = 0;       // Declare and initialize a variable to keep track of word count

    printf("Enter some text: ");
    gets(input_text);         // Reads entire line of input from the user and stores in input_text array

    for (int i = 0; i < strlen(input_text); i++)
    {
        // If the current character is a space or a newline, increment the word count
        if (input_text[i] == ' ' || input_text[i] == '\n')
        {
            word_count++;
        }
    }

    printf("The number of words in the input is: %d\n", word_count);

    printf("Enter a word to search: ");
    scanf("%s", search_word); // Reads a single word from the user and stores in search_word array

    printf("Enter a word to replace with: ");
    scanf("%s", replace_word); // Reads a single word from the user and stores in replace_word array

    // Look for the search_word in the input_text and replace it with replace_word
    char *position = strstr(input_text, search_word);   // Returns a pointer to the first occurrence of search_word in input_text
    if (position != NULL)
    {
        int index = position - input_text;   // Calculate the index of the first occurrence of search_word
        strncpy(input_text + index, replace_word, strlen(replace_word)); // Replace the search_word with replace_word from the position index
    }

    printf("Modified text: %s\n", input_text);

    return 0;
}