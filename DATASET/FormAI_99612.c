//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int isSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int isSymbol(char c) {
    return (c == '<' || c == '>' || c == '/');
}

void beautify(char* html) {
    int i, j, k;
    int indent = 0;
    char result[MAX_LEN];
    memset(result, '\0', MAX_LEN);
    
    for (i = 0, j = 0; i < strlen(html); i++) {
        if (isSymbol(html[i])) {
            if (html[i] == '<' && html[i+1] != '/') {
                for (k = 0; k < indent; k++) {
                    result[j++] = '\t';
                }
                indent++;
                result[j++] = html[i];
                result[j++] = '\n';
            } else if (html[i] == '<' && html[i+1] == '/') {
                indent--;
                for (k = 0; k < indent; k++) {
                    result[j++] = '\t';
                }
                result[j++] = html[i];
                result[j++] = html[i+1];
                i++;
                result[j++] = '\n';
            } else if (html[i] == '>') {
                result[j++] = html[i];
                result[j++] = '\n';
            }
        } else if (isSpace(html[i-1]) && html[i] == ' ') {
            continue;
        } else {
            result[j++] = html[i];
        }
    }
    
    printf("%s", result);
}

int main() {
    char* html = "<html><head><title>Beautify Me!</title></head><body><h1>Hello, World!</h1><p>This is a test of the beautify function.</p></body></html>";
    
    beautify(html);
    
    return 0;
}