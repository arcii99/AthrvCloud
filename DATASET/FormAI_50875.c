//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double calculate_polarity_score(int positive_words_count, int negative_words_count) {
    double score = ((double)positive_words_count - (double)negative_words_count) / ((double)positive_words_count + (double)negative_words_count + 0.000001);
    return score;
}

int main() {
    // Initialize lists of positive and negative words
    char positive_words[5][10] = {"love", "happy", "excited", "great", "amazing"};
    char negative_words[5][10] = {"hate", "sad", "disappointed", "terrible", "awful"};

    char input_sentence[1000];
    int positive_words_count = 0;
    int negative_words_count = 0;

    // Get user input sentence
    printf("Enter your sentence: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);

    // Check each word in the sentence
    char* word = strtok(input_sentence, " ");
    while (word != NULL) {
        // Remove punctuation
        char* last_char = &word[strlen(word)-1];
        if (*last_char == '.' || *last_char == '?' || *last_char == '!') {
            *last_char = '\0';
        }

        // Compare with positive and negative word lists
        int i;
        for (i = 0; i < 5; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive_words_count++;
                break;
            } else if (strcmp(word, negative_words[i]) == 0) {
                negative_words_count++;
                break;
            }
        }

        // Get next word
        word = strtok(NULL, " ");
    }

    // Calculate polarity score and sentiment based on score
    double polarity_score = calculate_polarity_score(positive_words_count, negative_words_count);

    if (polarity_score > 0.5) {
        printf("This sentence has a positive sentiment.\n");
    } else if (polarity_score < -0.5) {
        printf("This sentence has a negative sentiment.\n");
    } else {
        printf("This sentence has a neutral sentiment.\n");
    }

    return 0;
}