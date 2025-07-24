//FormAI DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char c;
    int tabCount = 0;
    char *output = (char*) malloc(1);
    int outputLength = 0;
    int lineBreakCount = 0;
    while ((c = getchar()) != EOF) {
        if (c == '<') {
            if (lineBreakCount > 0) {
                output[outputLength++] = '\n';
                lineBreakCount = 0;
            }
            output[outputLength++] = c;
            output[outputLength++] = '\n';
            tabCount++;
            for (int i = 0; i < tabCount; i++) {
                output[outputLength++] = '\t';
            }
        } else if (c == '>') {
            output[outputLength++] = '\n';
            lineBreakCount++;
            tabCount--;
            for (int i = 0; i < tabCount; i++) {
                output[outputLength++] = '\t';
            }
            output[outputLength++] = c;
        } else {
            output[outputLength++] = c;
        }
    }
    printf("%s", output);
    free(output);
    return 0;
}