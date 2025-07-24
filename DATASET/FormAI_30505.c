//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTabs(int count) {
    for(int i = 0; i < count; i++) {
        printf("\t");
    }
}

void beautifyHTML(char *html, int len, int level) {
    int i = 0, j = 0;
    while(i < len) {
        // Look for opening tag
        if(html[i] == '<' && html[i+1] != '/') {
            // Print tabs for this level
            printTabs(level);
            
            // Print opening tag
            printf("%c", html[i]);
            i++;
            
            // Print tag name
            while(html[i] != '>') {
                printf("%c", html[i]);
                i++;
            }
            printf(">\n");
            level++;
        }
        // Look for closing tag
        else if(html[i] == '<' && html[i+1] == '/') {
            // Move cursor to tag name
            j = i+2;
            while(html[j] != '>') {
                j++;
            }
            
            // Print tabs for this level
            level--;
            printTabs(level);

            // Print closing tag
            printf("%c%c", html[i], html[i+1]);
            i++;
            
            // Print tag name
            while(i < j) {
                printf("%c", html[i]);
                i++;
            }
            i++;
            printf(">\n");
        }
        // Look for text between tags
        else {
            // Print tabs for this level
            if(html[i-1] == '>') {
                printTabs(level);
            }
            
            // Print text
            while(html[i] != '<') {
                printf("%c", html[i]);
                i++;
            }
            printf("\n");
        }
    }
}

int main() {
    char html[] = "<html><head><title>Sample Page</title></head><body><h1>Welcome!</h1><p>This is a sample page.</p></body></html>";
    int len = strlen(html);
    
    beautifyHTML(html, len, 0);
    
    return 0;
}