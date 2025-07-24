//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD 100    // Maximum word length
#define MAX_LINES 1000  // Maximum number of lines in the input file

int get_word(char *word, int max_word_length);
int read_line(char *line, int max_line_length);
void process_word(char *word);
void print_result(char *word_list[], int freq[], int word_count);

int main()
{
    char line[MAX_LINES];
    char *word_list[MAX_LINES];
    int freq[MAX_LINES];

    int i, j, word_count;
    for (i = 0; i < MAX_LINES; i++)
    {
        word_list[i] = NULL;
        freq[i] = 0;
    }

    while (read_line(line, MAX_LINES) > 0)
    {
        i = 0;
        while (i < strlen(line))
        {
            char word[MAX_WORD];
            int word_length = get_word(&line[i], MAX_WORD);
            if (word_length > 0)
            {
                strncpy(word, &line[i], word_length);
                word[word_length] = '\0';
                process_word(word);
                int found = 0;
                word_count = 0;
                for (j = 0; j < MAX_LINES; j++)
                {
                    if (word_list[j] != NULL)
                    {
                        if (strcmp(word, word_list[j]) == 0)
                        {
                            freq[j]++;
                            found = 1;
                        }
                        word_count++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (!found)
                {
                    word_list[word_count] = strdup(word);
                    freq[word_count] = 1;
                }
                i += word_length;
            }
            else
            {
                i++;
            }
        }
    }
    print_result(word_list, freq, word_count);
    return 0;
}

int get_word(char *word, int max_word_length)
{
    // Returns the length of the word if it exists, otherwise returns 0
    int i, word_length = 0;
    for (i = 0; i < max_word_length; i++)
    {
        if (isalnum(word[i]))
        {
            word_length++;
        }
        else if (word_length > 0)
        {
            break;
        }
    }
    return word_length;
}

int read_line(char *line, int max_line_length)
{
    // Reads a line of text from the input file and returns 0 if end of file
    // has been reached, otherwise returns the length of the line read
    int i = 0, c;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (i < max_line_length)
        {
            line[i++] = c;
        }
    }
    line[i] = '\0';
    return i;
}

void process_word(char *word)
{
    // Converts the word into lowercase
    int i;
    for (i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
}

void print_result(char *word_list[], int freq[], int word_count)
{
    // Prints the word-frequency pairs in sorted order
    int i, j;
    char *temp;
    for (i = 0; i < word_count - 1; i++)
    {
        for (j = i + 1; j < word_count; j++)
        {
            if (strcmp(word_list[i], word_list[j]) > 0)
            {
                temp = word_list[i];
                word_list[i] = word_list[j];
                word_list[j] = temp;

                int freq_temp = freq[i];
                freq[i] = freq[j];
                freq[j] = freq_temp;
            }
        }
    }
    printf("Word Frequency\n");
    for (i = 0; i < word_count; i++)
    {
        printf("%s %d\n", word_list[i], freq[i]);
    }
}