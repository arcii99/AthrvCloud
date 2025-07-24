//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>

int main() {
    FILE *file;
    char line[100];

    file = fopen("cheerful.txt", "r");
    if (file == NULL) {
        printf("Oops, the file could not be opened.\n");
        return 1;
    }

    printf("Reading in cheerful phrases...\n\n");
    while (fgets(line, 100, file)) {
        printf("You are %s! That's so cheerful!\n", line);
    }

    fclose(file);
    return 0;
}