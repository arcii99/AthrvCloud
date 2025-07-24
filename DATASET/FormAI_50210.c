//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify a HTML code string
char *beautify_html(char *code) {
    int len = strlen(code);    // Get the length of the string
    char *result = (char*)malloc(sizeof(char) * len * 2);    // Allocate memory for the result string
    int tab_count = 0;    // Keep track of the number of tabs to add

    for (int i = 0; i < len; i++) {
        if (code[i] == '<') {
            // Check if the tag is a closing tag
            int is_closing_tag = 0;
            if (code[i+1] == '/') {
                is_closing_tag = 1;
            }

            // Add appropriate tabs
            for (int j = 0; j < tab_count; j++) {
                strcat(result, "\t");
            }

            // Add the tag to the result string
            strcat(result, "<");
            if (is_closing_tag) {
                tab_count--;
            } else {
                tab_count++;
            }

            // Add the tag name to the result string
            while (code[i] != '>') {
                strcat(result, &code[i]);
                i++;
            }
            strcat(result, ">");

            // Add a newline after the opening tag
            if (!is_closing_tag) {
                strcat(result, "\n");
            }
        } else {
            // Add the character to the result string
            strcat(result, &code[i]);
        }
    }

    // Add a null terminator to the end of the result string
    strcat(result, "\0");

    return result;
}

int main() {
    char *html_code = "<html><head><title>My Title</title></head><body><h1>Welcome!</h1><p>This is an example HTML code</p></body></html>";

    char *beautified_html = beautify_html(html_code);

    printf("%s\n", beautified_html);

    return 0;
}