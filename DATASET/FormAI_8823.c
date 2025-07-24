//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s DirectoryName\n", argv[0]);
        return 1;
    }

    char *cmd = malloc(sizeof(char) * (strlen(argv[1]) + 50));
    sprintf(cmd, "dir %s /s", argv[1]);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error: Failed to run command\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    unsigned long long total_size = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *ptr = strstr(line, "bytes");
        if (ptr != NULL) {
            unsigned long long size = strtoull(ptr - 13, NULL, 0);
            total_size += size;
        }
    }

    printf("Total size of %s directory: %llu bytes\n", argv[1], total_size);

    free(cmd);
    pclose(fp);
    if (line)
        free(line);

    return 0;
}