//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>

struct word_sentiment {
    char word[50];
    int sentiment;
};

int main () {
    struct word_sentiment sentiments[10];

    // Setting up sentiments for the words
    strcpy(sentiments[0].word, "fun");
    sentiments[0].sentiment = 8;
    strcpy(sentiments[1].word, "sad");
    sentiments[1].sentiment = 2;
    strcpy(sentiments[2].word, "happy");
    sentiments[2].sentiment = 9;
    strcpy(sentiments[3].word, "exciting");
    sentiments[3].sentiment = 10;
    strcpy(sentiments[4].word, "depressed");
    sentiments[4].sentiment = 1;
    strcpy(sentiments[5].word, "enjoy");
    sentiments[5].sentiment = 7;
    strcpy(sentiments[6].word, "frustrated");
    sentiments[6].sentiment = 3;
    strcpy(sentiments[7].word, "lovely");
    sentiments[7].sentiment = 9;
    strcpy(sentiments[8].word, "peaceful");
    sentiments[8].sentiment = 8;
    strcpy(sentiments[9].word, "angry");
    sentiments[9].sentiment = 2;

    // Getting user input
    char input[100];
    printf("Enter text for sentiment analysis: ");
    fgets(input, 100, stdin);

    // Processing user input
    printf("\nResults:\n");
    char* token = strtok(input, " .,\n");
    int total_sentiment = 0;
    int num_words = 0;
    while (token != NULL) {
        for (int i=0; i<10; i++) {
            if (strcmp(sentiments[i].word, token) == 0) {
                total_sentiment += sentiments[i].sentiment;
                num_words++;
                printf("%s - %d\n", token, sentiments[i].sentiment);
            }
        }
        token = strtok(NULL, " .,\n");
    }

    // Calculating overall sentiment score
    int overall_sentiment = 0;
    if (num_words != 0) {
        overall_sentiment = total_sentiment / num_words;
    }
    printf("\nOverall sentiment score: %d", overall_sentiment);

    return 0;
}