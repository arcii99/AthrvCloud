//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    unsigned long long total_size = 0; // total size of all the files
    DIR *directory;
    struct dirent *entry;

    // open the current directory
    directory = opendir(".");
    if (directory == NULL)
    {
        printf("Error: Unable to open current directory.");
        return 1;
    }

    // for each file in the directory
    while ((entry = readdir(directory)) != NULL)
    {
        char path[1024];
        struct stat stat_buffer;

        // concatenate the file name with the path to get the full path of the file
        snprintf(path, sizeof(path), "%s/%s", ".", entry->d_name);

        // get the file information
        if (stat(path, &stat_buffer) == -1)
        {
            printf("Error: Unable to get file information for %s\n", entry->d_name);
            continue;
        }

        // if the file is a regular file
        if (S_ISREG(stat_buffer.st_mode))
        {
            total_size += stat_buffer.st_size; // add the size of the file to the total size
        }
    }

    // close the directory
    closedir(directory);

    // print the results
    printf("Total disk space used: %.2f GB", (double) total_size / (1024 * 1024 * 1024));
    return 0;
}