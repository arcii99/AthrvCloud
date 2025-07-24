//FormAI DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Greetings, humans! I am the Text Processor 9000 and I am here to help you process your text with the power of C programming language!\n");
    printf("What would you like me to do today? I can do all sorts of cool things, like counting words, converting to uppercase, swapping characters, and much more!\n");

    char input[10000];
    printf("Please enter some text to process:\n");
    fgets(input, 10000, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    printf("Great! Let's get started...\n");

    // Count Words
    int word_count = 0;
    char* token = strtok(input, " \t\n\r\f\v"); // split by whitespace
    while(token != NULL)
    {
        word_count++;
        token = strtok(NULL, " \t\n\r\f\v");
    }
    printf("Number of words in the input: %d\n", word_count);

    // Convert to Uppercase
    char uppercase[10000];
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
            uppercase[i] = input[i] - 32; // subtract 32 to convert to uppercase
        else
            uppercase[i] = input[i];
    }
    uppercase[strlen(input)] = '\0'; // add null terminator
    printf("Here's your input in uppercase: %s\n", uppercase);

    // Swap characters
    if(strlen(input) >= 2)
    {
        char temp = input[0];
        input[0] = input[strlen(input)-1];
        input[strlen(input)-1] = temp;

        printf("The input with the first and last characters swapped: %s\n", input);
    }
    else
        printf("Sorry, the input is too short to swap characters.\n");

    printf("Wasn't that amazing? I bet you're loving the Text Processor 9000 right now! Feel free to try out more options and see what other cool things I can do!\n");

    return 0;
}