//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Metadata {
    char author[MAX_LEN];
    char date[MAX_LEN];
    char description[MAX_LEN];
};

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LEN];
    int i;
    struct Metadata md;

    if (argc < 2) {
        printf("Error: no file specified\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LEN, fp) != NULL) {
        if (strstr(line, "Author") != NULL) {
            strncpy(md.author, strchr(line, ':') + 1, MAX_LEN);
        }
        else if (strstr(line, "Date") != NULL) {
            strncpy(md.date, strchr(line, ':') + 1, MAX_LEN);
        }
        else if (strstr(line, "Description") != NULL) {
            strncpy(md.description, strchr(line, ':') + 1, MAX_LEN);
        }
    }

    printf("Author: %s\nDate: %s\nDescription: %s\n", md.author, md.date, md.description);

    fclose(fp);

    return 0;
}