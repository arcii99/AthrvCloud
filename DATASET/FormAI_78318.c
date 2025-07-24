//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int positive = 0, negative = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", input);

    char *positive_words[] = {"good", "great", "excellent", "happy", "love"};
    char *negative_words[] = {"bad", "terrible", "awful", "sad", "hate"};

    char *token = strtok(input, " ");
    while(token != NULL) {
        for(int i=0; i<5; i++) {
            if(strcmp(token, positive_words[i]) == 0) {
                positive++;
            } else if(strcmp(token, negative_words[i]) == 0) {
                negative++;
            }
        }
        token = strtok(NULL, " ");
    }

    if(positive > negative) {
        printf("The sentence is positive.\n");
    } else if(negative > positive) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}