//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_HTML_SIZE 1024

int main(){
    char html[MAX_HTML_SIZE];
    int indentationLevel = 0;
    char *token;

    printf("Enter an HTML text:\n");
    fgets(html, MAX_HTML_SIZE, stdin);

    printf("\nFormatted HTML Output:\n");
    token = strtok(html, "<>");
    while(token != NULL) {
        if(token[0] == '/') {    // closing tag
            indentationLevel--;
        }

        for(int i = 0; i < indentationLevel*4; i++) {   // print indentation
            printf(" ");
        }
        printf("<%s>\n", token);

        if(token[0] != '/' && token[strlen(token)-1] != '/') {     // opening tag and not self-closing
            indentationLevel++;
        }

        token = strtok(NULL, "<>");
    }

    return 0;
}