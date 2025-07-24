//FormAI DATASET v1.0 Category: Text Summarizer ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000
#define SUMMARIZED_SIZE 200

int main() {
    char text[MAX_SIZE];
    char summarized[SUMMARIZED_SIZE];
    int i, j = 0;

    printf("Input text for summarization:\n");
    fgets(text, MAX_SIZE, stdin);

    // Find the end of the summarized text (first 200 non-space characters)
    for (i = 0; i < strlen(text); i++) {
        if (text[i] != ' ' && j < SUMMARIZED_SIZE) {
            summarized[j] = text[i];
            j++;
        } else if (j == SUMMARIZED_SIZE) {
            break;
        }
    }

    // Replace last word of the summarized text with ellipsis
    for (i = SUMMARIZED_SIZE - 1; i >= 0; i--) {
        if (summarized[i] == ' ') {
            summarized[i] = '.';
            summarized[i + 1] = '.';
            summarized[i + 2] = '.';
            break;
        }
    }

    // Print the summarized text
    printf("Summarized text:\n%s\n", summarized);

    return 0;
}