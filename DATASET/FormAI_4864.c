//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
/* Linus Torvalds style C Sentiment Analysis tool example program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *input_string = NULL;
    size_t len = 0;
    int sentiment_score = 0;

    printf("Please enter a sentence to analyze: ");

    if (getline(&input_string, &len, stdin) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    char current_word[50];
    int i = 0, j = 0;
    while (input_string[i] != '\0') {
        if (input_string[i] == ' ' || input_string[i] == '\n') {
            current_word[j] = '\0';
            j = 0;

            if (strcmp(current_word, "good") == 0 ||
                strcmp(current_word, "great") == 0 ||
                strcmp(current_word, "excellent") == 0) {
                sentiment_score++;
            } else if (strcmp(current_word, "bad") == 0 ||
                       strcmp(current_word, "terrible") == 0 ||
                       strcmp(current_word, "awful") == 0) {
                sentiment_score--;
            }
        } else {
            current_word[j] = input_string[i];
            j++;
        }
        i++;
    }
    
    printf("The sentiment score of the input sentence is: %d\n", sentiment_score);

    free(input_string);

    return 0;
}