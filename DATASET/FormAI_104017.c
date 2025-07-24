//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void scan_file(char *filePath) {
    FILE *file = fopen(filePath, "r");
    char buffer[4096];
    int virusFound = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, "virus") != NULL) {
            virusFound = 1;
            break;
        }
    }
    fclose(file);
    if (virusFound) {
        printf("Virus found in file: %s\n", filePath);
        // Perform virus removal action here
    }
}

void scan_directory(char *dirPath) {
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", dirPath);
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filePath[4096];
            snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
            scan_file(filePath);
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char subDirPath[4096];
            snprintf(subDirPath, sizeof(subDirPath), "%s/%s", dirPath, entry->d_name);
            scan_directory(subDirPath);
        }
    }
    closedir(dir);
}

int main() {
    char *dirPath = "/usr/local/data";
    scan_directory(dirPath);
    printf("Scan complete.\n");
    return 0;
}