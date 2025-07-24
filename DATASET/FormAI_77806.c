//FormAI DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        printf("Unable to open file %s\n", argv[1]);
        exit(1);
    }

    int count = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (!isspace(c)) {
            count++;
            while ((c = fgetc(fp)) != EOF && !isspace(c));
        }
    }

    printf("The file %s contains %d words.\n", argv[1], count);

    fclose(fp);
    return 0;
}