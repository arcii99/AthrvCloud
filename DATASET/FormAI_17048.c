//FormAI DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SENT_LEN 200
#define DELIMITER ".?!"

int main() {

    char input[MAX_SENTENCES][MAX_SENT_LEN], summary[MAX_SENTENCES][MAX_SENT_LEN], *token;
    int freq[MAX_SENTENCES], count_sent = 0, i, j, k;

    printf("Enter text to summarize: ");

    // Reading input text from user
    while (fgets(input[count_sent], MAX_SENT_LEN, stdin)) {
        if (input[count_sent][0] == '\n') {
            break;
        }
        count_sent++;
    }

    // Tokenizing sentences
    for (i = 0; i < count_sent; i++) {
        token = strtok(input[i], DELIMITER);
        while (token != NULL) {
            for (j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }
            strcpy(input[i], token);
            freq[i]++;
            token = strtok(NULL, DELIMITER);
        }
    }

    // Summarizing text
    int max_freq, flag;
    count_sent = 0;
    for (i = 0; i < count_sent; i++) {
        max_freq = 0;
        for (j = 0; j < count_sent; j++) {
            flag = 0;
            for (k = 0; k < count_sent; k++) {
                if (i != k && j != k && strstr(input[k], input[j])) {
                    flag = 1;
                    break;
                }
            }
            if (!flag && freq[j] > max_freq) {
                max_freq = freq[j];
                strcpy(summary[count_sent], input[j]);
            }
        }
        count_sent++;
        if (count_sent >= 5) {
            break;
        }
    }

    // Outputting summary
    printf("\nSummary:\n");
    for (i = 0; i < count_sent; i++) {
        printf("%s. ", summary[i]);
    }
    printf("\n");

    return 0;
}