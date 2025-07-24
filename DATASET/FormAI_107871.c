//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void analyzeDiskSpace(char *rootDirectory) {
    long long int totalSize = 0;
    FILE *fp = NULL;
    char command[1000], path[1000], size[100], *filename = NULL, line[1000];
    sprintf(command, "dir /s /b \"%s\"", rootDirectory);
    fp = popen(command, "r");

    if (fp == NULL) {
        printf("Failed to run command\n");
        return;
    }

    while (fgets(path, 1000, fp) != NULL) {
        if (strchr(path, '\\') == NULL)
            continue;
        filename = strrchr(path, '\\') + 1;
        if (strlen(filename) > 255)
            filename[255] = '\0';
        sprintf(command, "dir /s /a-d \"%s\" | find \"File(s)\"", path);
        FILE *f = popen(command, "r");
        if (fgets(line, sizeof(line), f)) {
            sscanf(line, "%s %*s %*s %*s %s", size, size + strlen(size) / 2);
            totalSize += atoll(size);
            printf("%s (%s)\n", filename, size);
        }
        pclose(f);
    }

    pclose(fp);
    printf("Total size: %lld bytes\n", totalSize);
}

int main() {
    char rootDirectory[1000];
    printf("Enter Root Directory to Analyze: ");
    scanf("%s", rootDirectory);
    analyzeDiskSpace(rootDirectory);
    return 0;
}