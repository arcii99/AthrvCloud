//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *filename;
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *filepointer = fopen(filename, "r");
    if (filepointer == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char c;
    int indent_level = 0;
    
    while ((c = fgetc(filepointer)) != EOF) {
        if (c == '<') {
            putchar(c);
            if (fgetc(filepointer) == '/') {
                indent_level--;
            } else {
                indent_level++;
            }
        } else if (c == '>') {
            putchar(c);
            if (fgetc(filepointer) != '<') {
                putchar('\n');
                for (int i = 0; i < indent_level; i++) {
                    putchar('\t');
                }
            }
        } else {
            putchar(c);
        }
    }

    fclose(filepointer);

    return 0;
}