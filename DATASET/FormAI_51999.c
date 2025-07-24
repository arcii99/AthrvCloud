//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char filename[50];
    char c;
    int wordCount = 0;
    printf("Enter a filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while ((c = getc(file)) != EOF) {
        if (isspace(c)) {
            wordCount++;
        }
    }

    printf("The word count of the file %s is %d\n", filename, wordCount);

    fclose(file);
    return 0;
}