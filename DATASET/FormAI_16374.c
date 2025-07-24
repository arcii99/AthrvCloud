//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // validate command line args
    if (argc != 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }

    // open file for reading
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Unable to open file %s.\n", argv[1]);
        exit(1);
    }

    // read file into buffer
    fseek(fp, 0, SEEK_END);
    size_t len = ftell(fp);
    rewind(fp);
    char *buffer = calloc(len + 1, sizeof(char));
    fread(buffer, sizeof(char), len, fp);

    // count occurrences of word
    char *word = argv[2];
    size_t word_len = strlen(word);
    int count = 0;
    char *pos = buffer;
    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += word_len;
    }

    // display result
    printf("File %s contains %d occurrences of the word '%s'.\n", argv[1], count, word);

    free(buffer);
    fclose(fp);
    return 0;
}