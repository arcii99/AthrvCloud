//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indent = 0;

void indent_code() {
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }
}

int main() {
    char html[10000];
    char clean_html[10000];
    printf("Enter the HTML code:\n");
    fgets(html, 10000, stdin);

    int i = 0, j = 0;
    while (html[i] != '\0') {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                indent -= 1;
            }
            indent_code();
            printf("%c", html[i]);
            if (html[i+1] != '/') {
                indent += 1;
            }
            printf("\n");
            j = 1;
        } else if (html[i] == '>') {
            printf("%c", html[i]);
            printf("\n");
            j = 1;
        } else {
            if (j == 1) {
                indent_code();
                j = 0;
            }
            printf("%c", html[i]);
        }
        i++;
    }

    return 0;
}