//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// A function to remove punctuations from a given string
void removePunctuations(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (ispunct(s[i])) {
            for (int j = i; j < len; j++) {
                s[j] = s[j + 1];
            }
            len--;
            i--;
        }
    }
}

// A function to convert a given string to lowercase
void toLowercase(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
}

// A function to count the number of occurences of a given
// word in a sentence
int countWordFrequency(char *sentence, char *word) {
    int count = 0;
    int sentenceLen = strlen(sentence);
    int wordLen = strlen(word);
    char *ptr = sentence;
    while ((ptr = strstr(ptr, word)) != NULL) {
        if ((ptr == sentence || !isalpha(*(ptr - 1))) && !isalpha(*(ptr + wordLen))) {
            count++;
        }
        ptr += wordLen;
    }
    return count;
}

// A function to calculate the sentiment score of a given sentence
double calculateSentimentScore(char *sentence) {
    int positiveWordsCount = 0;
    int negativeWordsCount = 0;

    char *positiveWords[] = {"good", "great", "excellent", "awesome", "fantastic"};
    char *negativeWords[] = {"bad", "terrible", "poor", "awful", "horrible"};

    // Remove punctuations from the sentence
    removePunctuations(sentence);

    // Convert the sentence to lowercase
    toLowercase(sentence);

    // Count the number of positive and negative words in the sentence
    for (int i = 0; i < 5; i++) {
        positiveWordsCount += countWordFrequency(sentence, positiveWords[i]);
        negativeWordsCount += countWordFrequency(sentence, negativeWords[i]);
    }

    // Calculate the sentiment score using the following formula:
    // (positiveWordsCount - negativeWordsCount) / (totalWordsCount + 0.0)
    int totalWordsCount = positiveWordsCount + negativeWordsCount;
    double sentimentScore = (positiveWordsCount - negativeWordsCount) / (totalWordsCount + 0.0);
    return sentimentScore;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    double sentimentScore = calculateSentimentScore(sentence);
    printf("Sentiment score: %f\n", sentimentScore);
    if (sentimentScore > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if (sentimentScore < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }
    return 0;
}