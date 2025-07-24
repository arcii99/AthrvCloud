//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *);

int main() {
    char html[500];
    printf("Enter HTML code to beautify:\n");
    fgets(html, 500, stdin);
    beautify(html);
    printf("%s", html);
    return 0;
}

void beautify(char *html) {
    int i, j = 0, l = strlen(html);
    char out[1000];
    for (i = 0; i < l; i++) {
        if (html[i] == '<') {
            while (html[i] != '>') {
                out[j++] = html[i++];
            }
            out[j++] = html[i];
            if (i+1 < l && html[i+1] != '<') {
                out[j++] = '\n';
            }
        } else if (html[i] == '>') {
            out[j++] = html[i];
            if (html[i+1] != '<') {
                out[j++] = '\n';
            }
        } else {
            out[j++] = html[i];
        }
    }
    out[j] = '\0';
    strcpy(html, out);
}