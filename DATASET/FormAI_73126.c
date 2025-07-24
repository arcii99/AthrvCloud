//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARS_PER_KB 1024

typedef struct {
    long totalSize;
    long freeSize;
    long usedSize;
} DiskSpace;

DiskSpace analyzeDiskSpace(char* path) {
    DiskSpace result;
    result.totalSize = 0;
    result.freeSize = 0;
    result.usedSize = 0;

    char command[128];
    sprintf(command, "df -k %s", path);

    FILE* stream = popen(command, "r");
    if (stream == NULL) {
        printf("Error opening stream\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, 1024, stream)) {
        if (strlen(line) <= 0) {
            continue;
        }

        if (strncmp(line, path, strlen(path)) == 0) {
            char delim[] = " \t\n";
            char *ptr = strtok(line, delim);
            
            // Skip the first token, which is the filesystem name
            ptr = strtok(NULL, delim);

            result.totalSize = atol(ptr);
            
            ptr = strtok(NULL, delim);
            result.usedSize = atol(ptr);

            ptr = strtok(NULL, delim);
            result.freeSize = atol(ptr);

            result.usedSize *= CHARS_PER_KB;
            result.freeSize *= CHARS_PER_KB;
            result.totalSize *= CHARS_PER_KB;

            break;
        }
    }

    pclose(stream);

    return result;
}

int main() {
    DiskSpace diskSpace = analyzeDiskSpace("/dev/sda1");

    printf("Total disk space: %ld bytes\n", diskSpace.totalSize);
    printf("Used disk space: %ld bytes\n", diskSpace.usedSize);
    printf("Free disk space: %ld bytes\n", diskSpace.freeSize);

    return 0;
}