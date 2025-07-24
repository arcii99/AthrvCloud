//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sentiment_analysis(char *input_text) {
    int pos_count = 0, neg_count = 0, neu_count = 0, count = 0;
    char *token, *copy_str;
    const char delimiter[2] = " ";
    float positive_words = 0.0, negative_words = 0.0, neutral_words = 0.0, total_words = 0.0;
    char positive_list[5][20] = {"happy", "good", "great", "love", "amazing"};
    char negative_list[5][20] = {"sad", "bad", "terrible", "hate", "awful"};

    copy_str = strdup(input_text); //create a copy of the input text

    token = strtok(copy_str, delimiter); //split the text by space

    while(token != NULL) { //iterate through the text
        
        for (int i = 0; i < 5; i++) { //check if token is positive
            if (strcmp(positive_list[i], token) == 0) {
                positive_words++;
                pos_count++;
            }
        }

        for (int i = 0; i < 5; i++) { //check if token is negative
            if (strcmp(negative_list[i], token) == 0) {
                negative_words++;
                neg_count++;
            }
        }

        if (pos_count == 0 && neg_count == 0) { //if token is not positive or negative, consider it neutral
            neutral_words++;
            neu_count++;
        }

        count++;
        token = strtok(NULL, delimiter);
        pos_count = 0;
        neg_count = 0;
    }

    printf("Positive Words: %.2f\n", (positive_words/count)*100);
    printf("Negative Words: %.2f\n", (negative_words/count)*100);
    printf("Neutral Words: %.2f\n", (neutral_words/count)*100);

    free(copy_str); //free the allocated memory
}

int main() {
    char input_text[500];

    printf("Enter a sentence: ");
    fgets(input_text, 500, stdin);

    sentiment_analysis(input_text);

    return 0;
}