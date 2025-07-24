//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
/* Curious C Text Summarizer */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 200

int main()
{
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Welcome to the Curious C Text Summarizer!\n");

    printf("Please input your text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* Curious: I wonder how many characters I just read in? */
    size_t input_length = strlen(input);
    printf("I just read in %lu characters!\n", input_length);

    /* Curious: I wonder what the first few words of the text were? */
    char* first_few_words = strtok(input, " ,.-");
    printf("The first few words were: %s\n", first_few_words);

    /* Curious: I wonder how many words total are in the text? */
    int num_words = 1;
    char* word;
    for (word = strtok(NULL, " ,.-"); word != NULL; word = strtok(NULL, " ,.-"))
    {
        num_words++;
    }
    printf("There are %d words in the text!\n", num_words);

    /* Curious: I wonder if the text has any exclamation marks? */
    int has_exclamation = 0;
    char* exclamation = strchr(input, '!');
    if (exclamation != NULL)
    {
        has_exclamation = 1;
    }
    printf("The text %s an exclamation mark.\n", has_exclamation ? "has" : "does not have");

    /* Curious: I wonder what the output of the text summarizer is? */
    if (input_length > MAX_OUTPUT_LENGTH)
    {
        strncpy(output, input, MAX_OUTPUT_LENGTH);
        output[MAX_OUTPUT_LENGTH - 1] = '\0';
    }
    else
    {
        strcpy(output, input);
    }
    printf("The text summary is: %s\n", output);

    printf("Thank you for using the Curious C Text Summarizer!\n");

    return 0;
}