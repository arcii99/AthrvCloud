//FormAI DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 10000
#define SUMMARY_SIZE 2000

char input[MAX_INPUT_SIZE];
char summary[SUMMARY_SIZE];

void strip(char *s) {
    int len = strlen(s);
    while (len > 0 && isspace(s[len - 1])) s[--len] = '\0';
    while (*s && isspace(*s)) memmove(s, s+1, strlen(s));
}

int main() {
    printf("Enter a text to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    strip(input);

    char *ptr;
    ptr = strtok(input, ".!?");

    while (ptr != NULL) {
        strip(ptr);
        if (strlen(summary) + strlen(ptr) > SUMMARY_SIZE - 4) break;
        strcat(summary, ptr);
        strcat(summary, ". ");
        ptr = strtok(NULL, ".!?");
    }

    printf("Summary: %s\n", summary);

    return 0;
}