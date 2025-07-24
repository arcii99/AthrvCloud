//FormAI DATASET v1.0 Category: Word Count Tool ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename;
    char *word = argv[1];
    int count = 0;
    FILE *file;

    if (argc != 2) {
        printf("Usage example: %s <filename> <word>\n", argv[0]);
        exit(1);
    } else {
        filename = argv[1];
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    while (!feof(file)) {
        char buffer[1024];

        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            char *ptr = buffer;

            while ((ptr = strstr(ptr, word)) != NULL) {
                count++;
                ptr++;
            }
        }
    }

    printf("The word '%s' appeared %d times in the file '%s'.\n", word, count, filename);

    fclose(file);

    return 0;
}