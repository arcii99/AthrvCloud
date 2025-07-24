//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>

#define MAX_LEN 1000
#define MAX_SUMMARY_LEN 100

int main() {
    char text[MAX_LEN];
    char summary[MAX_SUMMARY_LEN] = "";
    char *ptr;
    int sentence_count = 0;
    int summary_length = 0;

    printf("Enter the text to summarize:\n");

    fgets(text, MAX_LEN, stdin);

    ptr = text;

    while (*ptr) {
        if (*ptr == '.' || *ptr == '?' || *ptr == '!') {
            sentence_count++;

            if (sentence_count == 1) {
                // Add the first sentence to the summary
                int len = ptr - text + 1;
                if (len > MAX_SUMMARY_LEN) {
                    len = MAX_SUMMARY_LEN;
                }
                strncat(summary, text, len);
                summary_length += len;
            } else if (sentence_count % 2 == 0) {
                // Add every other sentence to the summary
                int len = ptr - text + 1;
                if (len > MAX_SUMMARY_LEN - summary_length) {
                    len = MAX_SUMMARY_LEN - summary_length;
                }
                strncat(summary, text, len);
                summary_length += len;
            }
        }

        ptr++;
    }

    printf("Summary:\n%s\n", summary);

    return 0;
}