//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char *file);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please provide at least one file to scan.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        scan(argv[i]);
    }

    printf("Scan complete!\n");

    return 0;
}

void scan(char *file) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", file);
        return;
    }

    while (getline(&line, &len, fp) != -1) {
        if (strcasestr(line, "virus") != NULL) {
            printf("Found virus in file: %s\n", file);
            printf("Virus detected in line: %s", line);
            break;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}