//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 10

int analyze_sentiment(char sentence[]) {
    int sentiment = 0;

    // weigh positive and negative keywords
    char keywords_pos[][10] = {"happy", "great", "exciting", "prosperous"};
    char keywords_neg[][10] = {"sad", "bad", "disappointing", "tragic"};

    for (int i = 0; i < sizeof(keywords_pos)/sizeof(keywords_pos[0]); i++) {
        if (strstr(sentence, keywords_pos[i]) != NULL) {
            sentiment += 2;
        }
    }

    for (int i = 0; i < sizeof(keywords_neg)/sizeof(keywords_neg[0]); i++) {
        if (strstr(sentence, keywords_neg[i]) != NULL) {
            sentiment -= 2;
        }
    }

    // weigh based on punctuation
    int exclamation_marks = 0;
    int question_marks = 0;
    int period_marks = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == '!') {
            exclamation_marks++;
        } else if (sentence[i] == '?') {
            question_marks++;
        } else if (sentence[i] == '.') {
            period_marks++;
        }
    }

    if (exclamation_marks >= 2) {
        sentiment += 3;
    } else if (exclamation_marks == 1) {
        sentiment += 2;
    }

    if (question_marks >= 2) {
        sentiment -= 3;
    } else if (question_marks == 1) {
        sentiment -= 2;
    }

    // apply sentiment adjustment based on punctuation
    if (sentiment > 0 && period_marks < 2) {
        sentiment -= 1;
    } else if (sentiment < 0 && period_marks < 2) {
        sentiment += 1;
    }

    return sentiment;
}

int main() {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH] = {
        "I am feeling great today!", 
        "This cyberdeck is exciting to use.",
        "The data breach was tragic and disappointing.",
        "This city is a bad place to be.",
        "Why do bad things always happen to me?",
        "I can't believe how happy I am right now.",
        "The heist was successful and prosperous.",
        "This city is so sad and depressing.",
        "Why do I always feel so disappointed?",
        "That tragic incident is still haunting me."
    };

    for (int i = 0; i < MAX_SENTENCES; i++) {
        int sentiment = analyze_sentiment(sentences[i]);

        // display the sentiment result
        printf("Sentence: %s\n", sentences[i]);
        if (sentiment > 0) {
            printf("Sentiment: Positive (%d)\n\n", sentiment);
        } else if (sentiment < 0) {
            printf("Sentiment: Negative (%d)\n\n", sentiment);
        } else {
            printf("Sentiment: Neutral (0)\n\n");
        }
    }

    return 0;
}