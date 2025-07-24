//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void sentiment_analysis(char line[]);

int main() {
    char txt_line[50];
    printf("Enter a line of text: ");
    fgets(txt_line, 50, stdin);
    sentiment_analysis(txt_line);
    return 0;
}

void sentiment_analysis(char line[]) {
    int num_words = 0;
    int i, pos_num = 0, neg_num = 0;
    char *word[20];
    char *pos_dict[10] = {"great", "good", "excellent", "fantastic", "love"};
    char *neg_dict[10] = {"bad", "terrible", "horrible", "awful", "never"};
    word[0] = strtok(line, " ");
    while (word[num_words] != NULL) {
        word[++num_words] = strtok(NULL, " ");
    }
    for (i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < 5; j++) {
            if ((strcmp(word[i], pos_dict[j])) == 0) {
                pos_num++;
            }
        }
        for (j = 0; j < 5; j++) {
            if ((strcmp(word[i], neg_dict[j])) == 0) {
                neg_num++;
            }
        }
    }
    printf("\nSentiment Analysis Results\n");
    printf("--------------------------\n");
    printf("Positive Words: %d\n", pos_num);
    printf("Negative Words: %d\n", neg_num);
}