//FormAI DATASET v1.0 Category: HTML beautifier ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *filename) {
    char buffer[1000];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }
    while (fgets(buffer, 1000, fp)) {
        int indentation = 0;
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '<') {
                if (buffer[i+1] == '/') {
                    indentation--;
                }
                for (int j = 0; j < indentation; j++) {
                    printf("  ");
                }
                if (buffer[i+1] != '!') {
                    printf("%c", buffer[i]);
                    indentation++;
                    if (buffer[i+1] != '/') {
                        printf("\n");
                    }
                }
            } else if (buffer[i] == '>') {
                printf("%c", buffer[i]);
                if (buffer[i-1] != '/') {
                    printf("\n");
                }
            } else {
                printf("%c", buffer[i]);
            }
        }
    }
    printf("\n");
    fclose(fp);
}

int main() {
    beautify_html("index.html");
    return 0;
}