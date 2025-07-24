//FormAI DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void beautify(char* html) {
    char buffer[MAX_LENGTH];
    int bufferIndex = 0;
    int indentLevel = 0;
    int len = strlen(html);
    
    for (int i = 0; i < len; i++) {
        char currentChar = html[i];
        
        if (currentChar == '<') {
            printf("%s", buffer);
            bufferIndex = 0;
            printf("\n");
            for (int j = 0; j < indentLevel; j++) {
                printf("\t");
            }
            indentLevel++;
        }
        
        buffer[bufferIndex] = currentChar;
        bufferIndex++;
        
        if (currentChar == '>') {
            printf("%s", buffer);
            bufferIndex = 0;
            printf("\n");
            indentLevel--;
            for (int j = 0; j < indentLevel; j++) {
                printf("\t");
            }
        }
    }
    
    printf("%s", buffer);
}

int main() {
    char* html = "<html><head><title>My Website</title></head><body><h1>Welcome to my website</h1></body></html>";
    printf("Input HTML:\n%s\n\nBeautified HTML:\n", html);
    beautify(html);

    return 0;
}