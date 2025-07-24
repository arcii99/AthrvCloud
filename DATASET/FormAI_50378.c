//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE], words[MAX_SIZE][MAX_SIZE];
    int num_words = 0;
    float sentiment = 0;

    printf("Enter a sentence: ");
    fgets(input, MAX_SIZE, stdin);

    // Parsing words and storing in 2D array
    char *token = strtok(input, " ");
    while (token != NULL) {
        strcpy(words[num_words++], token);
        token = strtok(NULL, " ");
    }

    // Calculating sentiment
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0) {
            sentiment += 1;
        }
        else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0) {
            sentiment -= 1;
        }
    }

    // Outputting sentiment
    if (sentiment > 0) {
        printf("The sentence has a positive sentiment.\n");
    }
    else if (sentiment < 0) {
        printf("The sentence has a negative sentiment.\n");
    }
    else {
        printf("The sentence has a neutral sentiment.\n");
    }

    return 0;
}