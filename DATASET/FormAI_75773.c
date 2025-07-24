//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 150

// Function to remove unwanted characters from a string
void remove_special_chars(char *str)
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] == ' '))
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to convert a string to lowercase
void to_lower_case(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// Function to count the occurrences of a word in a string
int count_word_occurrences(char *str, char *word)
{
    int i, count = 0;
    char *token;
    char str_copy[1000];

    strcpy(str_copy, str);
    to_lower_case(str);
    to_lower_case(word);

    token = strtok(str_copy, " ");
    while (token != NULL)
    {
        if (strcmp(token, word) == 0)
        {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

// Main function
int main()
{
    char input_text[1000];
    char summary[MAX_SUMMARY_LENGTH] = "";
    char *word_pointer, highest_word[50];
    int highest_count = 0, count;

    printf("Welcome to the C Text Summarizer! Please enter the text you want summarized:\n\n");
    fgets(input_text, sizeof(input_text), stdin);

    remove_special_chars(input_text);

    // Find the most common word in the input text
    word_pointer = strtok(input_text, " ");
    while (word_pointer != NULL)
    {
        count = count_word_occurrences(input_text, word_pointer);

        if (count > highest_count)
        {
            highest_count = count;
            strcpy(highest_word, word_pointer);
        }

        word_pointer = strtok(NULL, " ");
    }

    // Build the summary
    strcat(summary, "The most important word in this text is '");
    strcat(summary, highest_word);
    strcat(summary, "'. ");

    if (highest_count == 1)
    {
        strcat(summary, "It appears only once in the text. ");
    }
    else
    {
        strcat(summary, "It appears ");
        sprintf(summary + strlen(summary), "%d", highest_count);
        strcat(summary, " times in the text. ");
    }

    if (strlen(input_text) <= MAX_SUMMARY_LENGTH)
    {
        strcat(summary, "The text is short enough to summarize in its entirety: ");
        strcat(summary, input_text);
    }
    else
    {
        strcat(summary, "The text is too long to summarize in its entirety, but here is the first sentence: ");
        word_pointer = strtok(input_text, ".");
        strcat(summary, word_pointer);
        strcat(summary, ".");
    }

    printf("\n\nHere is your summary:\n\n%s\n", summary);

    return 0;
}