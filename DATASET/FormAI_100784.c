//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define TAB_WIDTH 4

/* Function to beautify HTML code */
void beautify_html(char *filename) {
    FILE *fp;
    char ch;
    int tab_count = 0, prev_ch = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '<') {
            if (prev_ch == '\n' || prev_ch == '\t' || prev_ch == ' ') {
                printf("\n");
            }
            printf("%c", ch);
            tab_count++;
        }
        else if (ch == '>') {
            printf("%c", ch);
            if (prev_ch == '/') {
                printf("\n");
                tab_count--;
            }
            printf("\n");
            for (int i = 0; i < tab_count; i++) {
                for (int j = 0; j < TAB_WIDTH; j++) {
                    printf(" ");
                }
            }
        }
        else {
            printf("%c", ch);
        }
        prev_ch = ch;
    }

    fclose(fp);
}

int main() {
    char filename[] = "test.html";
    beautify_html(filename);
    return 0;
}