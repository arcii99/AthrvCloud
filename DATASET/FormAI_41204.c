//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void beautify_html(char* html_string, char* beautified_html) {
    int indent_level = 0; // current indentation level
    int index = 0; // current index of beautified_html
    int len = strlen(html_string); // length of html_string

    for(int i=0; i<len; i++) {
        if(html_string[i] == '<') {
            if(html_string[i+1] == '/') indent_level--; // decrease indent level for closing tags
            for(int j=0; j<indent_level; j++) {
                beautified_html[index] = '\t'; // add tabs for indentation
                index++;
            }
            if(html_string[i+1] != '/') indent_level++; // increase indent level for opening tags
        }

        beautified_html[index] = html_string[i]; // add current character to beautified_html
        index++;

        if(html_string[i] == '>') {
            beautified_html[index] = '\n'; // add newline after closing tag
            index++;
        }
    }

    beautified_html[index] = '\0'; // add null-terminating character at end of string
}

int main() {
    char html_string[] = "<html><head><title>Sample Website</title></head><body><h1>Welcome to my Website</h1><p>This is a sample paragraph.</p><ul><li>List item 1</li><li>List item 2</li></ul></body></html>";
    char beautified_html[1000];

    beautify_html(html_string, beautified_html);
    printf("%s", beautified_html);

    return 0;
}