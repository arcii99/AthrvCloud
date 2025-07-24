//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR_LEN 1024

char* beautifyHTML(char* html) {
    char* beautified = calloc(MAX_STR_LEN, sizeof(char));
    int indentLevel = 0;
    bool inTag = false;
    bool inQuote = false;
    bool closingTag = false;
    bool ignoreNext = false;
    size_t len = strlen(html);

    for (int i = 0; i < len; i++) {
        if (ignoreNext) {
            ignoreNext = false;
            continue;
        }
        char currChar = html[i];
        if (currChar == '<' && !inQuote) {
            inTag = true;
            closingTag = (html[i+1] == '/');
            if (!closingTag) {
                indentLevel++;
            }
            if (html[i+1] == '!') {
                indentLevel--;
            }
        }
        if (inTag) {
            beautified[strlen(beautified)] = currChar;
            if (currChar == '"' || currChar == '\'') {
                inQuote = !inQuote;
            }
        } else {
            if (currChar == '>') {
                beautified[strlen(beautified)] = currChar;
                if (closingTag) {
                    indentLevel--;
                }
                beautified[strlen(beautified)] = '\n';
                for (int j = 0; j < indentLevel; j++) {
                    beautified[strlen(beautified)] = '\t';
                }
                if (!closingTag) {
                    indentLevel++;
                }
            } else if (currChar == '/') {
                ignoreNext = true;
            }
            beautified[strlen(beautified)] = currChar;
        }
        if (currChar == '\n') {
            // Remove any spaces at the beginning of the line
            while (beautified[strlen(beautified)-2] == '\t') {
                beautified[strlen(beautified)-2] = '\n';
                beautified[strlen(beautified)-1] = '\0';
            }
        }
    }
    return beautified;
}

int main() {
    char html[MAX_STR_LEN] = "<!DOCTYPE html>\n<html>\n<body>\n<h1>This is a heading</h1>\n<p>This is a paragraph.</p>\n</body>\n</html>";
    char* beautified = beautifyHTML(html);
    printf("%s", beautified);
    free(beautified);
    return 0;
}