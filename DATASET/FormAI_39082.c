//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LEN 100

int main(int argc, char *argv[]) {
    char filename[FILENAME_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char *filecontents = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&filecontents, &len, fp)) != -1) {
        fputs(filecontents, stdout);
    }

    fclose(fp);
    free(filecontents);
    return 0;
}