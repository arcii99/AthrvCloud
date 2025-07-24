//FormAI DATASET v1.0 Category: Text Summarizer ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS_PER_LINE 1000

int main() {
    printf("Welcome to the Happy C Text Summarizer!\n");

    char text[MAX_LINES][MAX_CHARS_PER_LINE];
    char summary[MAX_CHARS_PER_LINE];

    int num_lines = 0;
    int num_summary_chars = 0;

    printf("Please input your text:\n");

    // Read in text
    while (num_lines < MAX_LINES) {
        fgets(text[num_lines], MAX_CHARS_PER_LINE, stdin);

        if (text[num_lines][0] == '\n') {
            break;
        }

        num_lines++;
    }

    // Remove newlines and merge into summary
    for(int i = 0; i < num_lines; i++) {
        if(strcmp(text[i], "\n") != 0) {
            strcat(summary, text[i]);
            num_summary_chars += strlen(text[i]);
        }
    }

    // Print summary
    printf("Your happy summary is:\n");
    printf("%s\n", summary);

    printf("We hope you're feeling good about your summarized text!\n");
    return 0;
}