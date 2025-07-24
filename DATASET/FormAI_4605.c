//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* htmlInput, char* indentation) {
    
    char* htmlOutput = (char*)malloc(sizeof(char) * strlen(htmlInput) * 2);
    strcpy(htmlOutput, "");

    int indent = 0;
    int pos = 0;
    int len = strlen(htmlInput);

    while (pos < len) {

        // Extract the tag
        char tag[100] = "";
        while (htmlInput[pos] != '<') {
            pos++;
            if (pos == len) {
                break;
            }
        }
        if (pos == len) {
            break;
        }
        pos++;
        while (htmlInput[pos] != '>' && htmlInput[pos] != ' ') {
            strncat(tag, &htmlInput[pos], 1);
            pos++;
            if (pos == len) {
                break;
            }
        }

        // Determine indentation
        if (strstr(htmlInput + pos, "</") == htmlInput + pos) {
            indent--;
        }
        int i;
        for (i = 0; i < indent; i++) {
            strcat(htmlOutput, indentation);
        }

        // Add tag to output
        strcat(htmlOutput, "<");
        strcat(htmlOutput, tag);
        strcat(htmlOutput, ">");

        if (strstr(htmlInput + pos, "/>") == htmlInput + pos) {
            strcat(htmlOutput, "\n");
        }
        if (htmlInput[pos] == '>' && strstr(htmlInput + pos, "</") == NULL) {
            strcat(htmlOutput, "\n");
            indent++;
        }

        // Advance to next position
        while (htmlInput[pos] != '<') {
            strncat(htmlOutput, &htmlInput[pos], 1);
            pos++;
            if (pos == len) {
                break;
            }
        }
        if (pos == len) {
            break;
        }
    }

    strcpy(htmlInput, htmlOutput);
}

int main() {

    char* input = "<html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><img src=\"image.png\"/><p>Here is some text.</p></body></html>";
    char* indentation = "    ";
    beautifyHTML(input, indentation);
    printf("%s", input);

    return 0;
}