//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REVIEWS 500
#define MAX_WORDS 2000
#define MAX_CHARACTERS 1000

int main() {
    // Initialize variables
    FILE *fp;
    char current_line[MAX_CHARACTERS];
    int current_rating = 0;
    char current_word[MAX_CHARACTERS];
    int positive_count = 0;
    int negative_count = 0;
    int review_count = 0;
    char positive_words[MAX_WORDS][MAX_CHARACTERS];
    char negative_words[MAX_WORDS][MAX_CHARACTERS];
    char reviews[MAX_REVIEWS][MAX_CHARACTERS];

    // Open positive words file
    fp = fopen("positive_words.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file positive_words.txt");
        exit(1);
    }

    // Read the positive words into the array
    int i = 0;
    while (fgets(current_word, MAX_CHARACTERS, fp) != NULL) {
        // Remove newline character
        current_word[strcspn(current_word, "\n")] = 0;
        strcpy(positive_words[i], current_word);
        i++;
    }
    fclose(fp);

    // Open negative words file
    fp = fopen("negative_words.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file negative_words.txt");
        exit(1);
    }

    // Read the negative words into the array
    i = 0;
    while (fgets(current_word, MAX_CHARACTERS, fp) != NULL) {
        // Remove newline character
        current_word[strcspn(current_word, "\n")] = 0;
        strcpy(negative_words[i], current_word);
        i++;
    }
    fclose(fp);

    // Open reviews file
    fp = fopen("reviews.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file reviews.txt");
        exit(1);
    }

    // Read the reviews into the array and process sentiment
    while (fgets(current_line, MAX_CHARACTERS, fp) != NULL) {
        // Remove newline character
        current_line[strcspn(current_line, "\n")] = 0;
        strcpy(reviews[review_count], current_line);
        review_count++;

        // Process sentiment of current review
        char *token = strtok(current_line, " ");
        while (token != NULL) {
            // Check if word is in positive words list
            for (int j = 0; j < MAX_WORDS; j++) {
                if (strcmp(token, positive_words[j]) == 0) {
                    positive_count++;
                    break;
                }
            }

            // Check if word is in negative words list
            for (int j = 0; j < MAX_WORDS; j++) {
                if (strcmp(token, negative_words[j]) == 0) {
                    negative_count++;
                    break;
                }
            }

            token = strtok(NULL, " ");
        }

        // Determine sentiment of review based on counts
        if (positive_count > negative_count) {
            current_rating = 1;
        }
        else if (negative_count > positive_count) {
            current_rating = -1;
        }
        else {
            current_rating = 0;
        }

        // Reset counts for next review
        positive_count = 0;
        negative_count = 0;
    }
    fclose(fp);

    // Print sentiment results
    printf("Sentiment analysis results:\n");
    for (int i = 0; i < review_count; i++) {
        printf("Review %d: %s = ", i + 1, reviews[i]);
        if (current_rating == 1) {
            printf("positive\n");
        }
        else if (current_rating == -1) {
            printf("negative\n");
        }
        else {
            printf("neutral\n");
        }
    }

    return 0;
}