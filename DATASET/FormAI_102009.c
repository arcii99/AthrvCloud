//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    char *search_term = argv[2];
    FILE *fp;
    char *line;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    if (argc < 3) {
        printf("Usage: ./word_count <file_name> <search_term>\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *res = strstr(line, search_term);
        while (res != NULL) {
            count++;
            res = strstr(res + 1, search_term);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    printf("The word '%s' appears %d times in %s\n", search_term, count, filename);
    return 0;
}