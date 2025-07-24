//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify the given HTML contents
void beautify_html(char* content) {
    char beautified[5000];
    int index = 0;
    int indent_count = 0;
    int len = strlen(content);

    for(int i=0; i<len; i++) {
        char c = content[i];

        // Check for opening tag
        if(c == '<' && content[i+1] != '/') {
            // Indent the tag
            for(int j=0; j<indent_count; j++) {
                beautified[index++] = '\t';
            }

            // Copy the tag to the beautified array
            while(c != '>') {
                beautified[index++] = c;
                c = content[++i];
            }
            beautified[index++] = '>';
            beautified[index++] = '\n';

            // Increase the indentation
            indent_count++;
        }

        // Check for closing tag
        else if(c == '<' && content[i+1] == '/') {
            // Decrease the indentation
            indent_count--;

            // Indent the tag
            for(int j=0; j<indent_count; j++) {
                beautified[index++] = '\t';
            }

            // Copy the tag to the beautified array
            while(c != '>') {
                beautified[index++] = c;
                c = content[++i];
            }
            beautified[index++] = '>';
            beautified[index++] = '\n';
        }

        // Otherwise copy the content to the beautified array
        else {
            beautified[index++] = c;
        }
    }

    // Null terminate the beautified array
    beautified[index] = '\0';

    // Print the beautified HTML contents to the console
    printf("%s", beautified);
}

int main() {
    // Take the HTML contents as input from the user
    printf("Enter the HTML contents:\n");
    char content[5000];
    fgets(content, 5000, stdin);

    // Beautify the HTML contents
    printf("\nBeautified HTML contents:\n\n");
    beautify_html(content);

    return 0;
}