//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Function to beautify an HTML code
void beautify_html(char* html) {
    int indent = 0;
    int i = 0;
    int spacing = 0;
    int len = strlen(html);

    while (i < len) {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                indent -= spacing;
                printf("\n");
                for (int j = 0; j < indent; j++) {
                    printf("\t");
                }
            } else {
                if (html[i-1] == '>') {
                    printf("\n");
                    for (int j = 0; j < indent; j++) {
                        printf("\t");
                    }
                }
                spacing = 2;
                indent += spacing;
            }
        } else if (html[i-1] == '>') {
            spacing = 1;
            indent += spacing;
            printf("\n");
            for (int j = 0; j < indent; j++) {
                printf("\t");
            }
            indent -= spacing;
        }
        printf("%c", html[i]);
        i++;
    }
}

// Test the beautification function
int main() {
    char* html = "<html><head><title>Sample Page</title></head><body><h1>Welcome to my site!</h1><p>Here is some sample text.</p></body></html>";
    beautify_html(html);
    return 0;
}