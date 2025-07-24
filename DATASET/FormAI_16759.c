//FormAI DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    char *src_path = argv[1];
    char *dest_path = argv[2];

    printf("Creating backup of '%s' at '%s'\n", src_path, dest_path);

    FILE *src_fp, *dest_fp;
    src_fp = fopen(src_path, "r");
    if (src_fp == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    dest_fp = fopen(dest_path, "w");
    if (dest_fp == NULL) {
        printf("Error creating destination file.\n");
        return 1;
    }

    char buffer[MAX_LEN];

    while (fgets(buffer, MAX_LEN, src_fp) != NULL) {
        fputs(buffer, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);

    printf("Backup created successfully!\n");

    return 0;
}