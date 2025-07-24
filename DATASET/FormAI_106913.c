//FormAI DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char spam_words[5][20] = {"buy", "sale", "discount", "offer", "click"};
    int i, j, num_spam_words = 5, count = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", input);

    for (i = 0; i < num_spam_words; i++) {
        if (strstr(input, spam_words[i]) != NULL) {
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo spam detected. This looks like a genuine message.\n");
    } else {
        printf("\nWarning! This message contains %d spam word(s):\n", count);
        for (i = 0; i < num_spam_words; i++) {
            for (j = 0; spam_words[i][j] != '\0'; j++) {
                printf("%c", spam_words[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}