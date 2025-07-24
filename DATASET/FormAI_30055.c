//FormAI DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the C HTML Beautifier!\n\n");

    char html[1000];
    printf("Enter HTML code: ");
    fgets(html, sizeof(html), stdin);
    
    // Remove new line character
    html[strcspn(html, "\n")] = 0;
    
    // Remove extra spaces and tabs
    char *p = html;
    char *q = html;
    
    while (*q != 0) {
        if (*q != ' ' && *q != '\t') {
            *p++ = *q++;
        } else {
            q++;
            if (*q != ' ' && *q != '\t') {
                *p++ = ' ';
            } 
        }
    }
    *p = 0;
    
    // Add line breaks after opening tags
    p = html;
    q = html;
    int tag_depth = 0;
    
    while (*q != 0) {
        if (*q == '<') {
            tag_depth++;
            *p++ = *q++;
            if (*q != '/') {
                *p++ = '\n';
                for (int i = 0; i < tag_depth; i++) {
                    *p++ = '\t';
                }
            }
        } else if (*q == '>') {
            tag_depth--;
            *p++ = *q++;
            *p++ = '\n';
            for (int i = 0; i < tag_depth; i++) {
                *p++ = '\t';
            }
            if (*q != 0 && *q != '<') {
                *p++ = *q++;
            }
        } else {
            *p++ = *q++;
        }
    }
    *p = 0;
    
    // Print beautified HTML code
    printf("\nBeautified HTML code:\n%s", html);

    return 0;
}