//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// function to calculate the total size of a directory
unsigned long long int calculate_dir_size(char *path)
{
    struct dirent *entry;
    struct stat filestat;
    DIR *dir;
    unsigned long long int total_size = 0;

    dir = opendir(path);
    while ((entry = readdir(dir)) != NULL)
    {
        stat(entry->d_name, &filestat);
        if (S_ISDIR(filestat.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
                continue;
            char sub_path[100];
            strcpy(sub_path, path);
            strcat(sub_path, "/");
            strcat(sub_path, entry->d_name);
            total_size += calculate_dir_size(sub_path);
        }
        else
        {
            total_size += filestat.st_size;
        }
    }
    closedir(dir);

    return total_size;
}

int main()
{
    char path[100];
    printf("Enter the path of the directory: ");
    scanf("%s", path);

    unsigned long long int total_size = calculate_dir_size(path);
    printf("Total size of directory %s is %llu bytes.\n", path, total_size);

    return 0;
}