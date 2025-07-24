//FormAI DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 1000
#define MAX_CHARACTERS_PER_WORD 50

int main() {
    char text[MAX_WORDS][MAX_CHARACTERS_PER_WORD];
    int freq[MAX_WORDS], i, j, count;
    char summary[1000] = "In summary, ";

    printf("Please enter the text:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        scanf("%s", &text[i]);

        if (strcmp(text[i], "love") == 0 || strcmp(text[i], "romance") == 0 || strcmp(text[i], "date") == 0) {
            strcat(summary, text[i]);
            strcat(summary, " ");
        }

        freq[i] = -1;
    }

    for (i = 0; i < MAX_WORDS; i++) {
        count = 1;

        for (j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(text[i], text[j]) == 0 && strcmp(text[i], "") != 0) {
                count++;
                freq[j] = 0;
            }
        }

        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    for (i = 0; i < MAX_WORDS; i++) {
        if (freq[i] != 0) {
            strcat(summary, text[i]);
            strcat(summary, " ");
        }
    }

    printf("Here is your romantic text summary:\n%s", summary);

    return 0;
}