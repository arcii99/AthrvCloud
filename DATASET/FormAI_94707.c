//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_spaces(char* str) {
    int i = 0, j = 0;
    while (str[j]) {
        str[i++] = str[j++];
        if (str[j - 1] == ' ') {
            while (str[j] == ' ') {
                j++;
            }
        }
    }
    str[i] = '\0';
}

void beautify(char* str) {
    int i = 0, j = 0;
    int indent = 0;
    while (str[i]) {
        if (str[i] == '<') {
            if (str[i + 1] == '/') {
                indent--;
            }
            for (int k = 0; k < indent; k++) {
                printf("    ");
            }
            if (str[i + 1] != '!') {
                printf("%c", str[i]);
                printf("%c", str[i + 1]);
            } else {
                printf("%c", str[i]);
            }
            if (str[i + 1] != '!') {
                printf("\n");
            }
            indent++;
        } else if (str[i] == '>') {
            if (str[i - 1] == '/') {
                indent--;
            }
            if (str[i - 1] != '/') {
                printf("%c", str[i]);
                printf("\n");
                for (int k = 0; k < indent; k++) {
                    printf("    ");
                }
            } else {
                printf("%c", str[i]);
            }
        } else {
            printf("%c", str[i]);
        }
        i++;
    }
}

int main() {
    char html[] = "<html><head><title>Example</title></head><body><h1>Hello, World!</h1><p>This is an example program.</p></body></html>";

    printf("Original HTML: %s\n", html);
    remove_spaces(html);
    printf("HTML without spaces: %s\n", html);
    printf("Beautified HTML:\n");
    beautify(html);

    return 0;
}