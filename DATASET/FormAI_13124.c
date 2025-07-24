//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 1;
    }
    int count = 0;
    char word[512];
    int i, c;
    while ((c = fgetc(fp)) != EOF) {
        if (isalnum(c) || c == '_') {
            word[i++] = c;
        } else if (i > 0) {
            word[i] = '\0';
            count++;
            i = 0;
        }
    }
    if (i > 0) {
        word[i] = '\0';
        count++;
    }
    fclose(fp);
    printf("%d words found in file %s\n", count, argv[1]);
    return 0;
}