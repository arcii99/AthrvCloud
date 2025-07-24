//FormAI DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* beautify(char* html);

int main()
{
    char* html = "<html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>";
    char* beautifiedHtml = beautify(html);
    printf("%s", beautifiedHtml);
    free(beautifiedHtml);
    return 0;
}

char* beautify(char* html) {
    int indentationLevel = 0;
    int htmlLength = strlen(html);
    char* beautifiedHtml = malloc(htmlLength*2*sizeof(char));
    int beautifiedHtmlIndex = 0;
    for (int i = 0; i < htmlLength; i++) {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                indentationLevel--;
            }
            for (int j = 0; j < indentationLevel; j++) {
                beautifiedHtml[beautifiedHtmlIndex++] = '\t';
            }
            if (html[i+1] != '/') {
                indentationLevel++;
            }
        }
        beautifiedHtml[beautifiedHtmlIndex++] = html[i];
        if (html[i] == '>') {
            beautifiedHtml[beautifiedHtmlIndex++] = '\n';
        }
    }
    return beautifiedHtml;
}