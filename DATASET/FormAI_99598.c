//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *parseTag(char **pos) {
    char *startTag = strstr(*pos, "<");
    if (startTag == NULL) {
        return NULL;
    }
    char *endTag = strstr(startTag, ">");
    if (endTag == NULL) {
       return NULL;
    }
    *pos = endTag + 1;
    return endTag;
}

void printSpaces(int numOfSpaces) {
    for (int i = 0; i < numOfSpaces; i++) {
        printf(" ");
    }
}

void prettyPrint(char *html, int level) {
    char *pos = html;
    while (*pos != '\0') {
        if (*pos == '<') {
            // we found a tag
            char *tagStart = pos;
            char *tagEnd = parseTag(&pos);
            if (tagStart != html) {
                // there is some text or whitespace before this tag so print it
                printf("\n");
                printSpaces(level);
                fwrite(html, sizeof(char), tagStart - html, stdout);
            }
            html = pos;
            if (tagStart[1] == '/') {
                // it's a closing tag, so decrease the indentation level
                level -= 2;
            }
            printf("\n");
            printSpaces(level);
            fwrite(tagStart, sizeof(char), tagEnd - tagStart + 1, stdout);
            if (tagStart[1] != '/') {
                // it's an opening tag, so increase the indentation level
                level += 2;
            }
            html = pos;
        } else if (*pos == '\r' || *pos == '\n' || *pos == '\t') {
            // ignore whitespace characters
            pos++;
        } else {
            // we found some text outside of tags
            pos++;
        }
    }
    // print any remaining text after the last tag
    printf("\n");
    printSpaces(level);
    fwrite(html, sizeof(char), strlen(html), stdout);
}

int main() {
    char html[] = "<html>\n<head>\n    <title>This is the title</title>\n</head>\n<body>\n    <h1>Welcome to my website</h1>\n    <p>This is a paragraph of text.</p>\n    <ul>\n        <li>Item 1</li>\n        <li>Item 2</li>\n        <li>Item 3</li>\n    </ul>\n</body>\n</html>\n";
    prettyPrint(html, 0);
    return 0;
}