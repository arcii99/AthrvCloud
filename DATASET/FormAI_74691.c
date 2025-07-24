//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>

// Function to count the number of positive words in a sentence
int count_positive_words(char *sentence) {
    int count = 0;
    char *positive_words[] = {"happy", "love", "amazing", "fantastic", "great", "wonderful"};

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        for (int i = 0; i < 6; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to count the number of negative words in a sentence
int count_negative_words(char *sentence) {
    int count = 0;
    char *negative_words[] = {"sad", "hate", "disgust", "dislike", "terrible", "awful"};

    char *word = strtok(sentence, " ");
    while (word != NULL) {
        for (int i = 0; i < 6; i++) {
            if (strcmp(word, negative_words[i]) == 0) {
                count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char sentence[100];

    printf("Enter a sentence to analyze sentiment: ");
    fgets(sentence, sizeof(sentence), stdin);

    int positive_words = count_positive_words(sentence);
    int negative_words = count_negative_words(sentence);

    if (positive_words > negative_words) {
        printf("Great! Your sentence is very positive with %d positive words and %d negative words.\n",
               positive_words, negative_words);
    } else if (positive_words < negative_words) {
        printf("Oh no! Your sentence is very negative with %d negative words and %d positive words.\n",
               negative_words, positive_words);
    } else {
        printf("Your sentence is neutral with %d positive words and %d negative words.\n",
               positive_words, negative_words);
    }

    return 0;
}