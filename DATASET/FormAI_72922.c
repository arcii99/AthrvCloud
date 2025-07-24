//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    const char *pos_keywords[] = {"good", "awesome", "excellent", "happy"};
    const char *neg_keywords[] = {"bad", "terrible", "unhappy", "dislike"};
    char input[250];
    int pos_count = 0, neg_count = 0;
    float percent = 0.0;

    printf("Enter the text: ");
    scanf("%[^\n]", input);

    char *token = strtok(input, " ");

    while (token != NULL) {
        for (int i = 0; i < sizeof(pos_keywords) / sizeof(pos_keywords[0]); i++) {
            if (strcmp(token, pos_keywords[i]) == 0) {
                pos_count++;
                break;
            }
        }

        for (int i = 0; i < sizeof(neg_keywords) / sizeof(neg_keywords[0]); i++) {
            if (strcmp(token, neg_keywords[i]) == 0) {
                neg_count++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    percent = (pos_count - neg_count) / (float) (pos_count + neg_count) * 100;

    if (percent > 50) {
        printf("The overall sentiment is positive with %.2f%% positive words.\n", percent);
    } else if (percent < -50) {
        printf("The overall sentiment is negative with %.2f%% negative words.\n", -percent);
    } else {
        printf("The overall sentiment is neutral with %.2f%% positive words and %.2f%% negative words.\n", 
               (pos_count / (float) (pos_count + neg_count)) * 100, (neg_count / (float) (pos_count + neg_count)) * 100);
    }

    return 0;
}