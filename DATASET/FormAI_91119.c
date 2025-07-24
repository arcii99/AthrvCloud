//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <string.h>
#define MAX_SUMMARY 100

int main() {
    char text[1000], summary[MAX_SUMMARY];
    int i, j, k, length, count = 0, sumCount = 0, start, end;

    printf("Enter the text you want to summarize: ");
    fgets(text, 1000, stdin);
    length = strlen(text);

    for (i = 0; i < length; i++) {
        if (text[i] == '.') {
            count++;
        }
    }

    if (count > 0) {
        summary[sumCount++] = text[0];
        for (i = 0; i < length; i++) {
            if (text[i] == '.') {
                start = i + 1;
                end = i + 1;
                while (text[end] != ' ' && end < length) {
                    end++;
                }

                for (j = start; j < end; j++) {
                    if (sumCount < MAX_SUMMARY) {
                        summary[sumCount++] = text[j];
                    }
                }

                summary[sumCount++] = '.';
                summary[sumCount++] = ' ';
            }

        }
        summary[sumCount++] = '\0';
        printf("Summary: %s\n", summary);
    } else {
        printf("No period detected, cannot summarize.\n");
    }

    return 0;
}