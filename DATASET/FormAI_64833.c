//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_METADATA_SIZE 10000

int main() {
    char file_name[MAX_FILE_NAME];
    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    FILE *fp;

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error while opening the file!\n");
        exit(0);
    }

    char metadata[MAX_METADATA_SIZE];
    int metadata_size = 0;

    char ch = fgetc(fp);
    while (ch != EOF) {
        if (ch == '<') {
            while (ch != '>') {
                metadata[metadata_size++] = ch;
                ch = fgetc(fp);
            }
            metadata[metadata_size++] = ch;
            metadata[metadata_size] = '\0';
            printf("Metadata found: %s\n", metadata);
            metadata_size = 0;
        }

        ch = fgetc(fp);
    }

    fclose(fp);

    return 0;
}