//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

void analyze_sentence(char *sentence) {
    int positive = 0;
    int negative = 0;

    char *positive_words[] = {"good", "great", "excellent", "wonderful", "amazing"};
    char *negative_words[] = {"bad", "terrible", "horrible", "awful", "disappointing"};

    char *word = strtok(sentence, " ");

    while (word != NULL) {
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, positive_words[i]) == 0) {
                positive++;
            }
            if (strcmp(word, negative_words[i]) == 0) {
                negative++;
            }
        }
        word = strtok(NULL, " ");
    }

    if (positive > negative) {
        printf("The sentence has a positive sentiment.\n");
    } else if (positive < negative) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }
}

int main() {
    char sentence[100];

    printf("Please enter a sentence:\n");
    fgets(sentence, 100, stdin);

    analyze_sentence(sentence);

    return 0;
}