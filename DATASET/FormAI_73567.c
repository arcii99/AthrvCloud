//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

int main()
{
    char input_text[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0, letter_count = 0;
    float average_word_length, standard_deviation;
    int i, j;

    printf("Enter text: ");
    // read in input text
    while (scanf("%s", input_text[word_count]) == 1)
    {
        word_count++;
    }

    for (i = 0; i < word_count; i++)
    {
        letter_count += strlen(input_text[i]);
    }

    average_word_length = (float)letter_count / (float)word_count;

    float word_length_sum = 0.0;
    for (i = 0; i < word_count; i++)
    {
        word_length_sum += pow(strlen(input_text[i]) - average_word_length, 2.0);
    }

    standard_deviation = sqrt(word_length_sum / word_count);

    printf("\n\nSTATISTICAL ANALYSIS OF THE INPUT TEXT:\n");
    printf("Word count: %d\n", word_count);
    printf("Average word length: %.2f\n", average_word_length);
    printf("Standard deviation of word length: %.2f\n", standard_deviation);

    return 0;
}