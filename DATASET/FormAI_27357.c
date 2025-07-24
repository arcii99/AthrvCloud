//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

// Function to calculate size of directory
long long calculateSize(char *path)
{
    DIR *directory;
    struct dirent *entry;
    struct stat filestat;
    long long totalSize = 0;
    char filePath[512];

    // Open the directory
    directory = opendir(path);
    if (directory == NULL)
    {
        fprintf(stderr, "Error opening directory %s: %s\n", path, strerror(errno));
        return -1;
    }

    // Iterate through each item in the directory
    while ((entry = readdir(directory)) != NULL)
    {
        // Ignore . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the full path of the file or sub-directory
        sprintf(filePath, "%s/%s", path, entry->d_name);

        // Get the file statistics
        if (stat(filePath, &filestat) != 0)
        {
            fprintf(stderr, "Error getting statistics for %s: %s\n", filePath, strerror(errno));
            continue;
        }

        // If it's a directory, recursively calculate its total size
        if (S_ISDIR(filestat.st_mode))
        {
            long long subDirSize = calculateSize(filePath);
            if (subDirSize == -1)
                continue;
            totalSize += subDirSize;
        }
        // If it's a file, add its size to the total
        else if (S_ISREG(filestat.st_mode))
        {
            totalSize += filestat.st_size;
        }
    }

    // Close the directory
    if (closedir(directory) != 0)
    {
        fprintf(stderr, "Error closing directory %s: %s\n", path, strerror(errno));
        return -1;
    }

    return totalSize;
}

int main(int argc, char **argv)
{
    // Check that the user provided a directory path argument
    if (argc != 2)
    {
        printf("Usage: %s directory_path\n", argv[0]);
        return 1;
    }

    // Get the total size of the directory
    long long totalSize = calculateSize(argv[1]);
    if (totalSize == -1)
    {
        printf("Error calculating size of directory %s", argv[1]);
        return 1;
    }

    // Print the size in human-readable format
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unitIndex = 0;
    long double size = (long double)totalSize;
    while (size > 1024 && unitIndex < 4)
    {
        size /= 1024;
        unitIndex++;
    }
    printf("Total size of %s: %.2Lf %s\n", argv[1], size, units[unitIndex]);

    return 0;
}