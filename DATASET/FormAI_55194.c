//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 25   // Maximum word length is set to 25 characters

int word_count(const char *sentence);

int main()
{
    char sentence[300];      // Maximum input sentence length is set to 300 characters 
    int count;

    printf("Welcome to the Medieval Style Word Count Tool\n");
    printf("Please enter your sentence (maximum 300 characters):\n");
    fgets(sentence, 300, stdin);

    count = word_count(sentence);

    printf("Your sentence contains %d words in total.\n", count);
    return 0;
}

int word_count(const char *sentence)
{
    int i, word_count = 0, len;
    char word[MAX_WORD_LENGTH+1];      // Setting word buffer size to MAX_WORD_LENGTH + 1 for null termination

    len = strlen(sentence);

    // Loop through the sentence and count each word encountered
    for(i=0; i<len; i++)
    {
        if(isalpha(sentence[i]))
        {
            int j=0;
            // Copying the current word into the buffer until a space or end of sentence is encountered
            while(isalpha(sentence[i+j]) && j<MAX_WORD_LENGTH)
            {
                word[j] = sentence[i+j];
                j++;
            }
            word[j] = '\0';     // Null terminating the word buffer

            i += j;     // Increment i by j to skip the word in the sentence loop
            word_count++;
        }
    }

    return word_count;
}