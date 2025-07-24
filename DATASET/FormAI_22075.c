//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_handling(char *msg);

int main(void) {
    FILE *fp;
    char buf[256];
    char filename[50];
    int filesize;

    printf("Enter the filename: ");
    if (fgets(filename, 50, stdin) == NULL)
        error_handling("Failed to read filename");
    filename[strcspn(filename, "\n")] = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        error_handling("Failed to open file");

    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    if (filesize == -1)
        error_handling("Failed to get filesize");

    if (fgets(buf, sizeof(buf), fp) == NULL)
        error_handling("Failed to read file contents");

    printf("File contents:\n%s\n", buf);

    if (fclose(fp) == EOF)
        error_handling("Failed to close file");

    return 0;
}

void error_handling(char *msg) {
    fprintf(stderr, "[ERROR]: %s\n", msg);
    exit(1);
}