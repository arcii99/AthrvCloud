//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize text
void summarize(char* text)
{
    // Initializing variables
    char result[1000] = "";
    int index = 0, len = strlen(text);

    // Loop through the text
    for(int i = 0; i < len; i++)
    {
        // Check for end of sentence
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            // Extract sentence and add to result
            char sentence[1000];
            strncpy(sentence, text + index, i - index + 1);
            sentence[i - index + 1] = '\0';

            strcat(result, sentence);
            strcat(result, " ");

            // Update index
            index = i + 1;
        }
    }

    // Print result
    printf("Summarized text: %s\n", result);
}

// Main function
int main()
{
    // Input text
    char text[10000];
    printf("Enter text to be summarized:\n");
    fgets(text, 10000, stdin);

    // Summarize text
    summarize(text);

    return 0;
}