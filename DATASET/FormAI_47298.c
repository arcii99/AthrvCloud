//FormAI DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* summarize(char* text, int summary_length);

int main(void) {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    
    char* summary = summarize(text, 50);
    
    printf("%s\n", summary);
    
    free(summary);
    
    return 0;
}

char* summarize(char* text, int summary_length) {
    char* summary = malloc(summary_length * sizeof(char));
    int i, j = 0, k, l;
    char c;
    
    for (i = 0; i < strlen(text) && j < summary_length; i++) {
        c = text[i];
        if (isspace(c)) {
            summary[j] = c;
            j++;
        } else if (isalpha(c) && (j == 0 || isspace(summary[j-1]))) {
            k = i;
            while (isalpha(text[k])) {
                k++;
            }
            l = k - i;
            if (j + l > summary_length) {
                l = summary_length - j;
            }
            strncat(summary, text + i, l);
            j += l;
            i = k - 1;
            continue;
        } else if (c == '.' || c == '!' || c == '?') {
            summary[j] = c;
            j++;
            break;
        }
    }
    summary[j] = '\0';
    
    return summary;
}