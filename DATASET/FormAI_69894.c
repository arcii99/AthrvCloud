//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LEN 50
#define MAX_WORD_COUNT 1000

void remove_non_alphanumeric(char *str);

int main()
{
    char text[MAX_WORD_COUNT][MAX_WORD_LEN] = {0};
    int frequency[MAX_WORD_COUNT] = {0};
    int total_words = 0;

    printf("Enter text:\n");

    // read text from user input
    char input[MAX_WORD_LEN];
    while (fgets(input, MAX_WORD_LEN, stdin))
    {
        // split input into words
        char *word = strtok(input, " \n\r\t");
        while (word)
        {
            // remove non-alphanumeric characters
            remove_non_alphanumeric(word);
            if (strlen(word) > 0)
            {
                // convert to lowercase
                for (int i = 0; i < strlen(word); i++)
                {
                    word[i] = tolower(word[i]);
                }
                // add word to text array
                strcpy(text[total_words], word);
                total_words++;
            }
            word = strtok(NULL, " \n\r\t");
        }
    }

    // count word frequency
    for (int i = 0; i < total_words; i++)
    {
        // search for word in text array
        int index = -1;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(text[i], text[j]) == 0)
            {
                index = j;
                break;
            }
        }
        // if word is not found, add to frequency array
        if (index == -1)
        {
            frequency[i] = 1;
        }
        // if word is found, increment frequency in frequency array
        else
        {
            frequency[index]++;
        }
    }

    // sort words by frequency
    for (int i = 0; i < total_words - 1; i++)
    {
        for (int j = i + 1; j < total_words; j++)
        {
            if (frequency[i] < frequency[j])
            {
                int temp_freq = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp_freq;
                char temp_word[MAX_WORD_LEN];
                strcpy(temp_word, text[i]);
                strcpy(text[i], text[j]);
                strcpy(text[j], temp_word);
            }
        }
    }

    // print word frequency
    printf("\nWord frequency:\n");
    for (int i = 0; i < total_words; i++)
    {
        printf("%s\t%d\n", text[i], frequency[i]);
    }

    return 0;
}

void remove_non_alphanumeric(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (isalnum(str[i]))
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}