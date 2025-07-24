//FormAI DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void read_file(char *filename) {
    printf("Reading file %s...\n", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    if (ferror(fp)) {
        perror("Error reading file");
    }

    fclose(fp);
}

void write_file(char *filename, char *text) {
    printf("Writing to file %s...\n", filename);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fputs(text, fp) == EOF) {
        perror("Error writing to file");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fclose(fp) != 0) {
        perror("Error closing file");
    }
}

void append_file(char *filename, char *text) {
    printf("Appending to file %s...\n", filename);

    FILE *fp = fopen(filename, "a");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fputs(text, fp) == EOF) {
        perror("Error writing to file");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fclose(fp) != 0) {
        perror("Error closing file");
    }
}

void copy_file(char *src_file, char *dest_file) {
    printf("Copying file %s to %s...\n", src_file, dest_file);

    FILE *src_fp = fopen(src_file, "r");

    if (src_fp == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest_fp = fopen(dest_file, "w");

    if (dest_fp == NULL) {
        perror("Error opening destination file");
        fclose(src_fp);
        exit(EXIT_FAILURE);
    }

    char buffer[100];

    while (fgets(buffer, sizeof(buffer), src_fp) != NULL) {
        if (fputs(buffer, dest_fp) == EOF) {
            perror("Error writing to file");
            fclose(src_fp);
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(src_fp) != 0) {
        perror("Error closing source file");
    }

    if (fclose(dest_fp) != 0) {
        perror("Error closing destination file");
    }
}

int main() {
    char *filename = "test.txt";
    char *text1 = "Hello, world!\n";
    char *text2 = "This is a test file.\n";
    char *text3 = "It contains some example text.\n";

    write_file(filename, text1);
    append_file(filename, text2);
    append_file(filename, text3);
    read_file(filename);

    char *copy_filename = "copy.txt";

    copy_file(filename, copy_filename);
    read_file(copy_filename);

    return 0;
}