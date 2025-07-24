//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include <stdio.h>
#include <string.h>

// function to perform sentiment analysis
char* sentiment_analysis(char* sentence) {
    char positive_words[6][10] = {"good", "great", "excellent", "fantastic", "awesome", "happy"};
    char negative_words[5][10] = {"bad", "terrible", "awful", "horrible", "sad"};

    int positive_count = 0;
    int negative_count = 0;

    char *word = strtok(sentence, " ");

    // loop through each word in the sentence and count the number of positive and negative words
    while(word != NULL) {
        for(int i=0; i<6; i++) {
            if(strcmp(word, positive_words[i]) == 0) {
                positive_count++;
                break;
            }
        }
        for(int i=0; i<5; i++) {
            if(strcmp(word, negative_words[i]) == 0) {
                negative_count++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }

    // return the sentiment based on the word counts
    if(positive_count > negative_count) {
        return "Positive";
    } else if(negative_count > positive_count) {
        return "Negative";
    } else {
        return "Neutral";
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // remove the newline character from the end of the sentence
    sentence[strcspn(sentence, "\n")] = 0;

    char* result = sentiment_analysis(sentence);
    printf("%s", result);

    return 0;
}