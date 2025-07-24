//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_REVIEWS 100
#define MAX_CHARS 1000

// Function to calculate sentiment score
int calculate_sentiment_score(char *review) {
    int sentiment_score = 0;
    char positive_words[5][20] = {"good", "great", "excellent", "fantastic", "awesome"};
    char negative_words[5][20] = {"bad", "poor", "awful", "terrible", "disappointing"};

    // Check for positive words
    for(int i = 0; i < 5; i++) {
        if(strstr(review, positive_words[i]) != NULL) {
            sentiment_score += 1;
        }
    }

    // Check for negative words
    for(int i = 0; i < 5; i++) {
        if(strstr(review, negative_words[i]) != NULL) {
            sentiment_score -= 1;
        }
    }

    return sentiment_score;
}

// Thread function to process reviews
void *process_reviews(void *arg) {
    char **reviews = (char **)arg;
    int num_reviews = (int)strlen(*reviews);
    int *scores = malloc(num_reviews * sizeof(int));

    // Calculate sentiment score for each review
    for(int i = 0; i < num_reviews; i++) {
        scores[i] = calculate_sentiment_score(reviews[i]);
    }

    pthread_exit((void *)scores);
}

int main() {
    char reviews[MAX_REVIEWS][MAX_CHARS];
    char input[MAX_CHARS];
    int num_reviews = 0;

    // Read user input for reviews
    printf("Enter reviews:\n");
    while(fgets(input, MAX_CHARS, stdin) != NULL) {
        if(num_reviews == MAX_REVIEWS) {
            printf("Maximum number of reviews reached\n");
            break;
        }
        strcpy(reviews[num_reviews], input);
        num_reviews++;
    }

    // Create threads for processing reviews
    pthread_t threads[2];
    int rc, i;
    int *thread_scores[2];
    for(i = 0; i < 2; i++) {
        rc = pthread_create(&threads[i], NULL, process_reviews, (void *)reviews);
        if(rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for(i = 0; i < 2; i++) {
        pthread_join(threads[i], (void **)&thread_scores[i]);
    }

    // Combine scores from threads
    int *scores = malloc(num_reviews * sizeof(int));
    for(int i = 0; i < num_reviews; i++) {
        scores[i] = thread_scores[0][i] + thread_scores[1][i];
    }

    // Print sentiment scores for each review
    printf("Sentiment scores:\n");
    for(int i = 0; i < num_reviews; i++) {
        printf("%d\n", scores[i]);
    }

    // Free memory
    free(scores);
    free(thread_scores[0]);
    free(thread_scores[1]);

    pthread_exit(NULL);

    return 0;
}