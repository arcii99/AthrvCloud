//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define a struct to hold sentiment analysis result for a single sentence
typedef struct {
    int positive;
    int negative;
    float score;
} SentimentAnalysisResult;

// Define a struct to hold overall sentiment analysis result for a document
typedef struct {
    int total_positive;
    int total_negative;
    float overall_score;
} DocumentSentimentAnalysisResult;

// Define a function to perform sentiment analysis on a single sentence
SentimentAnalysisResult analyzeSentiment(char* sentence) {
    SentimentAnalysisResult result;
    result.positive = 0;
    result.negative = 0;

    // Count number of positive and negative words in the sentence
    char* positive_words[4] = {"good", "awesome", "amazing", "great"};
    char* negative_words[4] = {"bad", "terrible", "awful", "horrible"};

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                result.positive++;
                break;
            } else if (strcmp(word, negative_words[i]) == 0) {
                result.negative++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    // Calculate sentiment score for the sentence
    result.score = (float) result.positive / (result.positive + result.negative);

    return result;
}

// Define a function to perform sentiment analysis on a full document
DocumentSentimentAnalysisResult analyzeDocument(char* document) {
    DocumentSentimentAnalysisResult result;
    result.total_positive = 0;
    result.total_negative = 0;

    // Split document into sentences and perform sentiment analysis on each sentence
    char* sentence = strtok(document, ".");
    while (sentence != NULL) {
        SentimentAnalysisResult sentence_result = analyzeSentiment(sentence);
        result.total_positive += sentence_result.positive;
        result.total_negative += sentence_result.negative;
        sentence = strtok(NULL, ".");
    }

    // Calculate overall sentiment score for the document
    result.overall_score = (float) result.total_positive / (result.total_positive + result.total_negative);

    return result;
}

// Example usage of the sentiment analysis tool
int main() {
    char* document = "The movie was great. The acting was good. However, the plot was terrible.";
    DocumentSentimentAnalysisResult result = analyzeDocument(document);
    printf("Overall positive sentiment: %d\n", result.total_positive);
    printf("Overall negative sentiment: %d\n", result.total_negative);
    printf("Overall sentiment score: %f\n", result.overall_score);
    return 0;
}