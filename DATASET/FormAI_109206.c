//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

void checkFile(char *path);
void scanDirectory(char *path);

long long fileSize(char *path);
char *formatBytes(long long bytes);

int main(int argc, char *argv[]) {

    char *path;

    if(argc < 2) {
        printf("Usage: %s <directory or file>\n", argv[0]);
        exit(1);
    }

    path = argv[1];

    checkFile(path);

    return 0;
}

void checkFile(char *path) {

    if(fileSize(path) < 0) {
        printf("Error: Could not read '%s'\n", path);
        return;
    }

    printf("%s %s\n", formatBytes(fileSize(path)), path);
}

long long fileSize(char *path) {

    FILE *file;
    long long size = -1;

    file = fopen(path, "rb");

    if(file) {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        fclose(file);
    }

    return size;
}

char *formatBytes(long long bytes) {

    char *unit[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB", "BB"};
    static char output[200];
    int i;

    memset(output, 0, sizeof(output));

    for(i = 0; bytes > 1024 && i < 8; i++) {
        bytes /= 1024;
    }

    sprintf(output, "%lld %s", bytes, unit[i]);

    return output;
}

void scanDirectory(char *path) {
    // to be implemented
}