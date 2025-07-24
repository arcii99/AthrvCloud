//FormAI DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_HTML_LENGTH 10000
#define INDENT_AMOUNT 4

// Function to beautify HTML
void beautify_html(char *html) {
    int indent_level = 0;
    char *token;
    char indent[100] = "";
    char result[MAX_HTML_LENGTH] = "";
    
    // Tokenize HTML
    token = strtok(html, "<>");
    while (token != NULL) {
        // Ignore empty strings
        if (strlen(token) > 0) {
            // If opening tag add indent and increase indent level
            if (token[0] == '<' && token[1] != '/') {
                sprintf(indent, "%*s", indent_level * INDENT_AMOUNT, "");
                strcat(result, indent);
                strcat(result, token);
                strcat(result, "\n");
                indent_level++;
            }
            // If closing tag decrease indent level and add indent
            else if (token[0] == '<' && token[1] == '/') {
                indent_level--;
                sprintf(indent, "%*s", indent_level * INDENT_AMOUNT, "");
                strcat(result, indent);
                strcat(result, token);
                strcat(result, "\n");
            }
            // Otherwise just add indent and token
            else {
                sprintf(indent, "%*s", indent_level * INDENT_AMOUNT, "");
                strcat(result, indent);
                strcat(result, token);
                strcat(result, "\n");
            }
        }

        // Get next token
        token = strtok(NULL, "<>");
    }
    
    // Copy the beautified HTML to the original buffer
    strcpy(html, result);
}

int main() {
    char html[MAX_HTML_LENGTH] = "<html><head><title>Example</title></head><body><h1>Heading</h1><p>This is some text.</p></body></html>";
    
    printf("Original HTML:\n%s\n", html);
    
    beautify_html(html);
    
    printf("Beautified HTML:\n%s\n", html);
    
    return 0;
}