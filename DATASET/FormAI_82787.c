//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Maximum number of threads to be created
#define MAX_THREADS 10

// Structure to hold sentiment scores
struct Sentiment {
    char word[20];
    int score;
};

// Array of sentiment scores
struct Sentiment sentiments[] = {
    {"happy", 3},
    {"sad", -3},
    {"good", 2},
    {"bad", -2},
    {"love", 3},
    {"hate", -3},
    {"excited", 4},
    {"bored", -2},
    {"angry", -4},
    {"calm", 1},
    {"anxious", -2},
    {"relaxed", 2},
    {"tired", -1},
    {"refreshed", 1},
    {"stressed", -3},
    {"peaceful", 3},
    {"lonely", -2},
    {"friendly", 2},
    {"unfriendly", -2},
    {"confident", 3},
    {"insecure", -2},
    {"important", 3},
    {"insignificant", -2},
    {"interested", 2},
    {"bored", -2}
};

// Function to calculate sentiment score of a string
int getSentimentScore(char* str) {
    int score = 0;
    char *word = strtok(str, " ");
    while (word != NULL) {
        for (int i = 0; i < sizeof(sentiments)/sizeof(struct Sentiment); i++) {
            if (strcmp(word, sentiments[i].word) == 0) {
                score += sentiments[i].score;
            }
        }
        word = strtok(NULL, " ");
    }
    return score;
}

// Thread function to analyze sentiment score of a string
void* analyzeSentiment(void* data) {
    printf("Thread %ld started.\n", pthread_self());
    char* str = (char*) data;
    int score = getSentimentScore(str);
    printf("Sentiment score of \"%s\" is %d.\n", str, score);
    printf("Thread %ld finished.\n", pthread_self());
    pthread_exit(NULL);
}

int main() {
    // Array to hold text for sentiment analysis
    char texts[][100] = {
        "I am feeling happy today.",
        "He looked sad when he heard the news.",
        "The food was good but the service was bad.",
        "I hate it when people talk during the movie.",
        "I am so excited for the concert tonight!",
        "I am feeling bored at work.",
        "The customer was angry because his order was wrong.",
        "I am feeling calm and relaxed after meditation.",
        "I always feel anxious before public speaking.",
        "I am feeling lonely without my friends around."
    };

    // Create threads for each text and start sentiment analysis
    pthread_t thread[MAX_THREADS];
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
        printf("Creating thread %d\n", i+1);
        pthread_create(&thread[i], NULL, analyzeSentiment, (void*) texts[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < sizeof(texts)/sizeof(texts[0]); i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}