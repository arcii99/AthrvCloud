//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <string.h>

void analyze_sentence(char *sentence) {
    char *positive_words[] = {"good", "great", "love", "happy", "awesome"};
    char *negative_words[] = {"bad", "terrible", "hate", "sad", "disgusting"};
    int positive_count = 0;
    int negative_count = 0;
    char *word = strtok(sentence, " ");

    while(word != NULL) {
        for(int i = 0; i < 5; i++) {
            if(strcmp(word, positive_words[i]) == 0) {
                positive_count++;
            }
            if(strcmp(word, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        word = strtok(NULL, " ");
    }

    if(positive_count > negative_count) {
        printf("The sentence is positive.\n");
    }
    else if(positive_count < negative_count) {
        printf("The sentence is negative.\n");
    }
    else {
        printf("The sentence is neutral.\n");
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);
    analyze_sentence(sentence);
    return 0;
}