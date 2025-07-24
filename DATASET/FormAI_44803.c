//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <string.h>

void beautifyHTML(char html[]) {
    int indent = 0;
    int length = strlen(html);
    int i = 0, j = 0;
    while (i < length) {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                indent--;
            }
            for (int k = 0; k < indent; k++) {
                printf("    ");
            }
            printf("%c", html[i]);
            if (html[i+1] != '/') {
                indent++;
            }
            printf("\n");
        } else {
            for (int k = 0; k < indent; k++) {
                printf("    ");
            }
            printf("%c", html[i]);
            if (html[i] == '>') {
                printf("\n");
            }
        }
        i++, j++;
    }
}

int main() {
    char html[] = "<html><head><title>Hello, World!</title></head><body><h1>Welcome!</h1><p>This is my website.</p></body></html>";
    beautifyHTML(html);
    return 0;
}