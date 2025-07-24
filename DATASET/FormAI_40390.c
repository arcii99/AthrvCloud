//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define KB (1024)       // kilobyte
#define MB (1024 * KB)  // megabyte
#define GB (1024 * MB)  // gigabyte

/* Function Prototypes */
void printSize(double size);
void listAllFiles(char *path);
void parseArgs(int argc, char **argv, char *path);

/* Global Variables */
unsigned long long totalSize = 0;
unsigned long long minSize = 0;
unsigned long long maxSize = GB;   // Default max size of 1GB
char *directoryPath;               // The directory to be analyzed

int main(int argc, char **argv) {
    parseArgs(argc, argv, ".");
    listAllFiles(directoryPath);
    printf("Total Size: ");
    printSize(totalSize);
    printf("\n");
    return 0;
}

void printSize(double size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i;
    for (i = 0; i < 5 && size >= 1024; ++i)
        size /= 1024;
    printf("%.2f %s", size, units[i]);
}

void listAllFiles(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory\n");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    struct stat info;
    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        if (stat(fullPath, &info) == -1) {
            printf("Failed to get file info: %s\n", fullPath);
            continue;
        }
        if (S_ISDIR(info.st_mode)) {    // Recursively list all files in this directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            listAllFiles(fullPath);
        }
        else if (S_ISREG(info.st_mode)) {   // If this is a regular file, add its size to the total size
            if (info.st_size < minSize || info.st_size > maxSize)
                continue;
            totalSize += info.st_size;
        }
    }
    closedir(dir);
}

void parseArgs(int argc, char **argv, char *path) {
    int opt;
    while ((opt = getopt(argc, argv, "d:m:n:")) != -1) {
        switch (opt) {
            case 'd':   // Specify the directory path to be analyzed
                path = strdup(optarg);
                break;
            case 'm':   // Minimum size of files in bytes
                minSize = atoll(optarg);
                break;
            case 'n':   // Maximum size of files in bytes
                maxSize = atoll(optarg);
                break;
            default:
                printf("Usage: %s [-d directory] [-m min_size] [-n max_size]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    if (optind < argc)   // If there are any extra arguments, they will be considered the directory path
        path = strdup(argv[optind]);
    directoryPath = path;
}