//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        return 0;
    }

    // read file contents into buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    char* buffer = (char*)malloc(size + 1);
    memset(buffer, 0, size + 1);
    fseek(file, 0, SEEK_SET);
    fread(buffer, size, 1, file);
    fclose(file);

    // count words in buffer
    int count = 0;
    char* ptr = strtok(buffer, " \t\n\r");
    while (ptr != NULL) {
        count++;
        ptr = strtok(NULL, " \t\n\r");
    }

    printf("%d words\n", count);

    free(buffer);
    return 0;
}