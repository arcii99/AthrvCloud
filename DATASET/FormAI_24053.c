//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detect_sentiment(char sentence[]) {
    int pos_count = 0;
    int neg_count = 0;
    char* hello[4] = { "Hey", "Hello", "Hi", "Yo" };
    char* thanks[4] = { "Thanks", "Thank you", "Appreciate it", "Grateful" };
    char* insult[4] = { "Stupid", "Dumb", "Idiot", "Moron" };

    char* token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(hello[i], token) == 0) {
                printf("You seem happy! Hey back at you!\n");
                return;
            }
            if (strcmp(thanks[i], token) == 0) {
                printf("Glad to help, no problem!\n");
                return;
            }
            if (strcmp(insult[i], token) == 0) {
                printf("Excuse me?! That was not very nice!\n");
                return;
            }
        }
        if (strstr(token, "good") != NULL || strstr(token, "great") != NULL) {
            pos_count++;
        }
        else if (strstr(token, "bad") != NULL || strstr(token, "horrible") != NULL) {
            neg_count++;
        }
        token = strtok(NULL, " ");
    }
    if (pos_count > neg_count) {
        printf("You are feeling good today, fantastic!\n");
    }
    else {
        printf("You sound a bit down, cheer up buddy!\n");
    }
}

int main() {
    printf("Hello! How are you feeling today?\n");
    char input[100];
    fgets(input, 100, stdin);
    detect_sentiment(input);
    return 0;
}