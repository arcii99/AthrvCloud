//FormAI DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void beautify(char *html) {
    char *formatted = malloc(MAX_SIZE * sizeof(char));
    int indentation = 0;
    int i, j;

    if (!formatted) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0, j = 0; html[i] != '\0'; i++) {
        if (html[i] == '<') {
            if (html[i + 1] == '/') {
                indentation -= 2;
            }
            for (int k = 0; k < indentation; k++) {
                formatted[j++] = ' ';
            }
            if (html[i + 1] != '!') {
                indentation += 2;
            }
        }

        formatted[j++] = html[i];

        if (html[i] == '>') {
            formatted[j++] = '\n';
            formatted[j] = '\0';
        }
    }

    strcpy(html, formatted);
    free(formatted);
}

int main() {
    char html[MAX_SIZE] = "<html><body><h1>Hello, World!</h1></body></html>";
    printf("Original HTML:\n%s\n", html);
    
    beautify(html);
    printf("\nBeautified HTML:\n%s", html);
    
    return 0;
}