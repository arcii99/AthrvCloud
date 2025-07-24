//FormAI DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    int c, count = 0;

    file = fopen("puzzle.txt", "r");

    if (file) {
        while ((c = getc(file)) != EOF) {
            if (c == ' ' || c == '\n') {
                count++;
            }
        }
        fclose(file);
    } else {
        printf("Something went wrong!\n");
        exit(1);
    }

    printf("The puzzle has %d words.\n", count);

    return 0;
}