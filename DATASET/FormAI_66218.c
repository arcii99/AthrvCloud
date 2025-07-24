//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000

char inBuf[MAX_SIZE];
char outBuf[MAX_SIZE];

int main() {
    int i, j = 0;
    int count = 0;
    int isTag = 0;
    int isComment = 0;

    printf("Enter the HTML code you want to beautify: ");

    fgets(inBuf, MAX_SIZE, stdin);

    for (i = 0; i < strlen(inBuf); i++) {
        if (!isComment) {
            if (inBuf[i] == '<' && !isTag) {
                isTag = 1;
            }
            else if (inBuf[i] == '>' && isTag) {
                isTag = 0;
                outBuf[j] = inBuf[i];
                j++;
            }
            else if (isspace(inBuf[i]) && isTag) {
                outBuf[j] = ' ';
                j++;
            }
            else if (!isTag) {
                if (inBuf[i] == '<') {
                    isComment = 1;
                }
                else if (inBuf[i] == '\n') {
                    count = 0;
                }
                else {
                    if (count == 0) {
                        for (int k = 0; k < j; k++) {
                            printf("%c", outBuf[k]);
                        }
                        j = 0;
                        count = 1;
                    }
                    printf("%c", inBuf[i]);
                }
            }
        }
        else if (isComment) {
            if (inBuf[i] == '>') {
                isComment = 0;
            }
        }
    }
    return 0;
}