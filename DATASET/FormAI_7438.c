//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: standalone
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_WORDS 10000
#define MAX_SIZE 50

int main()
{
    char text[MAX_WORDS][MAX_SIZE], word[MAX_SIZE];
    int frequency[MAX_WORDS];
    int total_words = 0, count, i, j;

    printf("Enter text: \n");
    // Read in text from the user
    while(scanf("%s", &text[total_words]) == 1)
    {
        total_words++;
    }
    // Calculate the frequency of each word
    for(i = 0; i < total_words; i++)
    {
        strcpy(word, text[i]);
        count = 1;
        for(j = i+1; j < total_words; j++)
        {
            if(strcmp(word, text[j]) == 0)
            {
                count++;
                // Set the frequency of the repeated word to zero
                frequency[j] = 0;
            }
        }
        // Store the frequency of the word
        if(frequency[i] != 0)
        {
            frequency[i] = count;
        }
    }
    // Print the words and their frequency
    printf("\nWord \t Frequency\n");
    for(i = 0; i < total_words; i++)
    {
        if(frequency[i] != 0)
        {
            printf("%s \t %d\n", text[i], frequency[i]);
        }
    }
    return 0;
}