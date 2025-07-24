//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <string.h>

// Function to determine the sentiment of a sentence
char* sentiment_analysis(char* sentence) {

    // List of positive and negative words
    char* positive_words[] = {"good", "great", "excellent", "fantastic", "wonderful"};
    char* negative_words[] = {"bad", "terrible", "awful", "horrible", "disappointing"};

    // Variables to keep track of the number of positive/negative words
    int num_positive_words = 0;
    int num_negative_words = 0;

    // Tokenize the sentence
    char* token = strtok(sentence, " ");

    while (token != NULL) {
        // Check if the token is a positive or negative word
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                num_positive_words++;
            }
            else if (strcmp(token, negative_words[i]) == 0) {
                num_negative_words++;
            }
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Determine sentiment based on number of positive and negative words
    if (num_positive_words > num_negative_words) {
        return "Positive";
    }
    else if (num_positive_words < num_negative_words) {
        return "Negative";
    }
    else {
        return "Neutral";
    }
}

// Main function to test sentiment analysis
int main() {
    // Positive test cases
    char sentence1[] = "The movie was excellent and the acting was great.";
    char sentence2[] = "I had a fantastic time at the beach yesterday.";
    char sentence3[] = "The food at that restaurant is wonderful.";

    // Negative test cases
    char sentence4[] = "The service at that restaurant was terrible.";
    char sentence5[] = "The movie was awful and I was disappointed.";
    char sentence6[] = "He had a horrible experience at the theme park.";

    // Neutral test cases
    char sentence7[] = "I like to go for walks in the park.";
    char sentence8[] = "The weather today is cloudy and cool.";
    char sentence9[] = "She enjoys listening to classical music.";

    printf("Sentiment of sentence 1: %s\n", sentiment_analysis(sentence1));
    printf("Sentiment of sentence 2: %s\n", sentiment_analysis(sentence2));
    printf("Sentiment of sentence 3: %s\n", sentiment_analysis(sentence3));
    printf("Sentiment of sentence 4: %s\n", sentiment_analysis(sentence4));
    printf("Sentiment of sentence 5: %s\n", sentiment_analysis(sentence5));
    printf("Sentiment of sentence 6: %s\n", sentiment_analysis(sentence6));
    printf("Sentiment of sentence 7: %s\n", sentiment_analysis(sentence7));
    printf("Sentiment of sentence 8: %s\n", sentiment_analysis(sentence8));
    printf("Sentiment of sentence 9: %s\n", sentiment_analysis(sentence9));

    return 0;
}