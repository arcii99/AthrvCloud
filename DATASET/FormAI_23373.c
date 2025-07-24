//FormAI DATASET v1.0 Category: Syntax parsing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[50] = "sample.c";
    char line[100];
    char word[25];
    int i, j, k;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, 100, fp)) {
        i = j = 0;

        while (isspace(line[i])) {
            i++;
        }

        while (isalpha(line[i])) {
            word[j++] = line[i++];
        }
        word[j] = '\0';

        if (strcmp(word, "int") == 0 || strcmp(word, "float") == 0 ||
            strcmp(word, "char") == 0) {
            while (isspace(line[i])) {
                i++;
            }
            j = 0;
            while (isalpha(line[i]) || line[i] == '_') {
                word[j++] = line[i++];
            }
            word[j] = '\0';

            if (strcmp(word, "main") == 0) {
                while (line[i] != '(') {
                    i++;
                }
                i++;
                while (isspace(line[i]) || isalnum(line[i])) {
                    putchar(line[i++]);
                }
                putchar('\n');
            }
        }
    }

    fclose(fp);
    return 0;
}