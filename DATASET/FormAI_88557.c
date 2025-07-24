//FormAI DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char* filepath) {
    FILE *fp;

    fp = fopen(filepath, "r");
    if (fp == NULL)
        return;

    char c, prev;
    int count_indentation = 0;
    int in_tag = 0;
    int in_string = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '"' && prev != '\\') {
            in_string = !in_string;
        } else if (!in_string){
            if (c == '<') {
                in_tag = 1;
                printf("%c\n", c);
            } else if (c == '>') {
                in_tag = 0;
                printf("%c", c);
            } else if (c == '/') {
                printf("%c", c);
            } else if (c == '\n') {
                printf("%c", c);
                count_indentation = 0;
            } else if (c == ' ') {
                if (in_tag) {
                    printf("%c", c);
                } else if (count_indentation > 0) {
                    count_indentation++;
                }
            } else {
                if (count_indentation > 0) {
                    for (int i=0; i<count_indentation; i++) {
                        printf(" ");
                    }
                    count_indentation = 0;
                }
                printf("%c", c);
                if (c == '{' || c == '(') {
                    count_indentation += 4;
                }
            }
        } else {
            printf("%c", c);
        }
        prev = c;
    }

    fclose(fp);
}

int main() {
    beautify("example.html");
    return 0;
}