//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 1000

int main() {
    char html[MAX_LENGTH], minified[MAX_LENGTH];
    int i, j, in_tag = 0;

    printf("Enter your HTML code:\n");
    fgets(html, MAX_LENGTH, stdin);

    for (i = 0, j = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            in_tag = 1;
        } else if (html[i] == '>') {
            in_tag = 0;
        }

        if (!in_tag && !isspace(html[i])) {
            minified[j++] = html[i];
        }
    }
    minified[j] = '\0';

    printf("Minified HTML:\n%s", minified);

    return 0;
}