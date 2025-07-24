//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to calculate the size of a directory
long long int calculateDirectorySize(const char *path) {
    long long int total = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }
    struct dirent *entry;
    struct stat info;
    while ((entry = readdir(dir)) != NULL) {
        char *filePath;
        asprintf(&filePath, "%s/%s", path, entry->d_name);
        if (stat(filePath, &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    total += calculateDirectorySize(filePath);
                }
            } else {
                total += info.st_size;
            }
        }
        free(filePath);
    }
    closedir(dir);
    return total;
}

// Function to convert file size from bytes to human readable format (KB, MB, GB, etc.)
void convertFileSize(long long int fileSize, char *formattedSize) {
    const char *sizeUnits[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    int sizeUnitIndex = 0;
    while (fileSize > 1024 && sizeUnitIndex < 8) {
        fileSize /= 1024;
        sizeUnitIndex++;
    }
    sprintf(formattedSize, "%lld %s", fileSize, sizeUnits[sizeUnitIndex]);
}

int main(int argc, char **argv) {
    // Default configuration values
    const char *path = ".";
    long long int minFileSize = 0;
    long long int maxFileSize = 0x7FFFFFFFFFFFFFFF; // Max value of signed long long
    int showDirectories = 0;
    int showHiddenFiles = 0;
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-path") == 0 && i + 1 < argc) {
            path = argv[i + 1];
        } else if (strcmp(argv[i], "-min-size") == 0 && i + 1 < argc) {
            minFileSize = atoll(argv[i + 1]);
        } else if (strcmp(argv[i], "-max-size") == 0 && i + 1 < argc) {
            maxFileSize = atoll(argv[i + 1]);
        } else if (strcmp(argv[i], "-show-directories") == 0) {
            showDirectories = 1;
        } else if (strcmp(argv[i], "-show-hidden") == 0) {
            showHiddenFiles = 1;
        }
    }
    // Calculate size of each file and directory in the specified path
    long long int totalSize = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Could not open directory %s\n", path);
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char *filePath;
        asprintf(&filePath, "%s/%s", path, entry->d_name);
        struct stat info;
        if (stat(filePath, &info) == 0) {
            if (!showHiddenFiles && entry->d_name[0] == '.') {
                continue;
            }
            if (S_ISDIR(info.st_mode)) {
                if (showDirectories) {
                    long long int dirSize = calculateDirectorySize(filePath);
                    if (dirSize >= minFileSize && dirSize <= maxFileSize) {
                        char formattedSize[20];
                        convertFileSize(dirSize, formattedSize);
                        printf("%s %s/\n", formattedSize, entry->d_name);
                    }
                    totalSize += dirSize;
                }
            } else {
                if (info.st_size >= minFileSize && info.st_size <= maxFileSize) {
                    char formattedSize[20];
                    convertFileSize(info.st_size, formattedSize);
                    printf("%s %s\n", formattedSize, entry->d_name);
                }
                totalSize += info.st_size;
            }
        }
        free(filePath);
    }
    // Print total size of path
    char formattedSize[20];
    convertFileSize(totalSize, formattedSize);
    printf("Total size: %s\n", formattedSize);
    closedir(dir);
    return 0;
}