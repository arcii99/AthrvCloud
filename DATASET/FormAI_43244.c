//FormAI DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void beautifyHTML(char *filename) {
    FILE *fptr;
    char ch, prev_ch = ' ';
    int indent_level = 0;

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '<') {
            if (prev_ch != ' ') {
                printf("\n");
            }
            for (int i = 0; i < (indent_level * 4); i++) {
                printf(" ");
            }
            putchar(ch);

            if (fgetc(fptr) == '/') {
                indent_level--;
                for (int i = 0; i < (indent_level * 4); i++) {
                    printf(" ");
                }
                putchar('/');
            } else {
                indent_level++;
            }
        } else if (ch == '>') {
            putchar(ch);
            printf("\n");
        } else {
            putchar(ch);
        }

        prev_ch = ch;
    }

    fclose(fptr);
}

int main() {
    beautifyHTML("example.html");
    return 0;
}