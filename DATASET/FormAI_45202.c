//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *POSITIVE_WORDS[] = {"love", "happy", "good", "awesome", "brilliant"};
char *NEGATIVE_WORDS[] = {"hate", "angry", "bad", "terrible", "disgusting"};

int count_word(char *sentence, char *word) {
    char *pos = sentence;
    int count = 0;
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += strlen(word);
    }
    return count;
}

int get_sentiment_score(char *sentence) {
    int positive_score = 0;
    int negative_score = 0;
    for (int i = 0; i < 5; i++) {
        positive_score += count_word(sentence, POSITIVE_WORDS[i]);
        negative_score += count_word(sentence, NEGATIVE_WORDS[i]);
    }
    return positive_score - negative_score;
}

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int sentiment_score = get_sentiment_score(input);
    printf("The sentiment score of '%s' is %d\n", input, sentiment_score);
    if (sentiment_score > 0) {
        printf("The sentence is positive\n");
    } else if (sentiment_score < 0) {
        printf("The sentence is negative\n");
    } else {
        printf("The sentence is neutral\n");
    }
    return 0;
}