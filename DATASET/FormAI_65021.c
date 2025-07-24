//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
// A text summarizer written in Ada Lovelace style
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// Define constants
#define MAX_CHARACTERS 1000
#define MAX_SENTENCES 10
#define MAX_WORDS 30

// Function to remove unwanted characters and whitespace
void clean_string(char *str)
{
    int len = strlen(str);

    // Remove unwanted characters
    for(int i = 0; i < len; i++)
    {
        if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\n'))
        {
            str[i] = ' ';
        }
    }

    // Remove extra whitespace
    int i, j;
    for(i = 0, j = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' && (str[i+1] == ' ' || str[i+1] == '\n'))
        {
            continue;
        }
        str[j] = str[i];
        j++;
    }
    str[j] = '\0';
}

// Function to split string into words
int split_string(char *str, char words[][MAX_CHARACTERS])
{
    int i = 0;
    char *token = strtok(str, " ");
    while(token != NULL)
    {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    return i;
}

// Function to check if a word is a keyword
bool is_keyword(char *word)
{
    char keywords[][MAX_CHARACTERS] = { "the", "and", "a", "an", "is", "of", "in", "that", "this" };
    for(int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++)
    {
        if(strcmp(word, keywords[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

// Function to summarize the text
void summarize_text(char *text)
{
    // Clean the text
    clean_string(text);

    // Split the text into sentences
    char sentences[MAX_SENTENCES][MAX_CHARACTERS];
    int sentence_count = 0;
    char *sentence = strtok(text, ".");
    while(sentence != NULL)
    {
        strcpy(sentences[sentence_count], sentence);
        sentence_count++;
        sentence = strtok(NULL, ".");
    }

    // Create an array to store the score of each sentence
    int sentence_scores[MAX_SENTENCES] = { 0 };

    // Loop through each sentence
    for(int i = 0; i < sentence_count; i++)
    {
        char words[MAX_WORDS][MAX_CHARACTERS];
        int word_count = split_string(sentences[i], words);

        // Loop through each word
        for(int j = 0; j < word_count; j++)
        {
            if(is_keyword(words[j]))
            {
                sentence_scores[i]++;
            }
        }
    }

    // Print the top 3 sentences
    printf("\nSummary:\n");
    for(int i = 0; i < 3; i++)
    {
        int max_score = 0;
        int max_index = 0;
        // Find the sentence with the highest score
        for(int j = 0; j < sentence_count; j++)
        {
            if(sentence_scores[j] > max_score)
            {
                max_score = sentence_scores[j];
                max_index = j;
            }
        }
        // Print the sentence and its score
        printf("%s. (%d)\n", sentences[max_index], max_score);
        // Set the score to 0 so it won't be chosen again
        sentence_scores[max_index] = 0;
    }

}

int main()
{
    // Example text to summarize
    char text[] = "Once upon a time, there was a little girl named Goldilocks. She went for a walk in the forest. Pretty soon, she came upon a house. She knocked and, when no one answered, she walked right in. At the table in the kitchen, there were three bowls of porridge. Goldilocks was hungry. She tasted the porridge from the first bowl. “This porridge is too hot!” she exclaimed. So, she tasted the porridge from the second bowl. “This porridge is too cold,” she said. So, she tasted the last bowl of porridge. “Ahhh, this porridge is just right,” she said happily and she ate it all up. ";

    // Summarize the text
    summarize_text(text);

    return 0;
}