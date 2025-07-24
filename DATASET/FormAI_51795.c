//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 2

void print_indent(int indent) {
    for (int i = 0; i < indent * INDENT_SIZE; i++) {
        printf(" ");
    }
}

int main() {
    char* html = "<html><head><title>Hello World</title></head><body><h1>Welcome to my website!</h1><p>This is an example HTML page.</p></body></html>";
    int len = strlen(html);
    int indent_level = 0;
    int i = 0;

    while (i < len) {
        // Check if current character is a tag
        if (html[i] == '<') {
            // Check if current tag is a closing tag
            if (html[i+1] == '/') {
                indent_level--;
            }

            // Print new line and indent before the tag
            printf("\n");
            print_indent(indent_level);

            // Print the tag
            printf("%c", html[i]);

            // Check if tag is a closing tag
            if (html[i+1] == '/') {
                printf("%c", html[i+1]);
                i += 2;
            } else {
                i++;
            }

            // Print tag name
            while (html[i] != '>' && html[i] != ' ') {
                printf("%c", html[i]);
                i++;
            }

            // Indent to next level for opening tag
            if (html[i] != '>') {
                printf("%c", html[i]);
                printf("%c", html[i+1]);
                printf("\n");
                indent_level++;
                print_indent(indent_level);
                i += 2;
            } else {
                printf("%c", html[i]);
                printf("\n");
                i++;
            }
        } else {
            // Print text content
            printf("%c", html[i]);
            i++;
        }
    }

    printf("\n");
    return 0;
}