//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert bytes to KB, MB, or GB
void convertBytes(long int bytes, char *size) {
    if (bytes >= 1073741824) {
        sprintf(size, "%.2f GB", (double) bytes / 1073741824);
    } else if (bytes >= 1048576) {
        sprintf(size, "%.2f MB", (double) bytes / 1048576);
    } else if (bytes >= 1024) {
        sprintf(size, "%.2f KB", (double) bytes / 1024);
    } else {
        sprintf(size, "%ld bytes", bytes);
    }
}

// Function to analyze C drive space usage
void analyzeCdrive() {
    char size[20];
    FILE *fp;
    char path[1035];

    // Open the command to retrieve the drive space usage
    fp = popen("du -sh /c/*", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // Parse the output and print the results
    printf("C Drive Space Usage:\n");
    while (fgets(path, sizeof(path), fp) != NULL) {
        char *p = strchr(path, '\t');
        if (p) {
            *p++ = '\0';
            printf("%s\t", path);
            long int bytes = atol(p) * 1024;
            convertBytes(bytes, size);
            printf("%s\n", size);
        }
    }

    // Close the command
    pclose(fp);
}

int main() {
    analyzeCdrive();

    return 0;
}