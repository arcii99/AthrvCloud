//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to remove punctuation marks from a sentence
void remove_punctuations(char *string) {
    int i, j = 0;
    for(i = 0; string[i]; i++) {
        if(ispunct(string[i])) {
            continue;
        }
        string[j++] = string[i];
    }
    string[j] = '\0';
}

int main() {
    char sentence[1000];
    char positive_words[5][20] = {"good", "excellent", "awesome", "nice", "great"};
    char negative_words[5][20] = {"bad", "terrible", "horrible", "awful", "poor"};
    int positive_score = 0, negative_score = 0;
    printf("Enter a sentence to analyze its sentiment: ");
    fgets(sentence, 1000, stdin);
    remove_punctuations(sentence);
    char *token = strtok(sentence, " ");
    while(token != NULL) {
        for(int i = 0; i < 5; i++) {
            if(strcmp(token, positive_words[i]) == 0) {
                positive_score++;
            } else if(strcmp(token, negative_words[i]) == 0) {
                negative_score++;
            }
        }
        token = strtok(NULL, " ");
    }
    if(positive_score > negative_score) {
        printf("The sentiment of the sentence is positive\n");
    } else if(negative_score > positive_score) {
        printf("The sentiment of the sentence is negative\n");
    } else {
        printf("The sentiment of the sentence is neutral\n");
    }
    return 0;
}