//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* html = "<html><head><title>My Website</title></head><body><h1>Welcome to my site!</h1><p>This is the homepage of my website.</p></body></html>";
    char* formatted_html = (char*) malloc(strlen(html)*2);
    int indent_level = 0;
    int i = 0;
    int j = 0;

    while(html[i] != '\0') {
        if(html[i] == '<') {
            if(html[i+1] == '/') {
                // Closing tag
                indent_level--;
                for(int k = 0; k < indent_level; k++) {
                    formatted_html[j++] = '\t';
                }
            }
            else {
                // Opening tag
                for(int k = 0; k < indent_level; k++) {
                    formatted_html[j++] = '\t';
                }
                indent_level++;
            }
        }
        formatted_html[j++] = html[i];
        if(html[i] == '>') {
            formatted_html[j++] = '\n';
        }
        i++;
    }
    printf("Formatted HTML:\n%s\n", formatted_html);
    free(formatted_html);
    return 0;
}