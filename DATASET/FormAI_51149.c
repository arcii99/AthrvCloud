//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *html = "<html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>";
    // Original HTML code

    printf("Original HTML code:\n%s\n\n", html);

    // Remove extra spaces
    char *beauty_html = "";
    char *token = strtok(html, "><");
    while(token != NULL) {
        beauty_html = strcat(beauty_html, token);
        beauty_html = strcat(beauty_html, " ");
        token = strtok(NULL, "><");
    }

    // Add indentation
    char *indented_html = "";
    int indent_level = 0;
    token = strtok(beauty_html, " ");
    while(token != NULL) {
        int prev_indent_level = indent_level;
        if(strstr(token, "</") == token) {
            indent_level--;
            prev_indent_level = indent_level;
        }
        for(int i = 0; i < prev_indent_level * 4; i++) {
            indented_html = strcat(indented_html, " ");
        }
        indented_html = strcat(indented_html, token);
        indented_html = strcat(indented_html, "\n");
        if(strstr(token, "<") != NULL && strstr(token, "</") != token) {
            indent_level++;
        }
        token = strtok(NULL, " ");
    }

    printf("Beautified and indented HTML code:\n%s\n", indented_html);

    return 0;
}