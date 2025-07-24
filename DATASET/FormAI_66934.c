//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "VIRUS"

int scan_file(const char *filename) {
    FILE *fp;
    char buffer[1024];
    size_t n;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return -1;
    }

    while ((n = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) {
        if (strstr(buffer, VIRUS_SIGNATURE) != NULL) {
            printf("File %s contains a virus!\n", filename);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    printf("File %s is clean!\n", filename);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [filename1] [filename2] ...\n", argv[0]);
        return -1;
    }

    for (int i = 1; i < argc; i++) {
        int result = scan_file(argv[i]);

        if (result != 0) {
            return result;
        }
    }

    return 0;
}