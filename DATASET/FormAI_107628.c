//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* function to calculate total directory size */
long long int calculate_directory_size(char target_dir[]) {
    struct dirent *dir_ptr;
    struct stat stat_buf;
    DIR *dir;

    long long int total_size = 0; // variable to hold total size

    /* open target directory */
    dir = opendir(target_dir);

    /* check if directory is accessible */
    if (dir == NULL) {
        printf("Unable to access directory!");
        return -1;
    }

    /* loop through all files and sub-directories in target directory */
    while ((dir_ptr = readdir(dir)) != NULL) {
        /* store individual file/sub-directory path */
        char file_path[1024] = "";
        strcat(file_path, target_dir);
        strcat(file_path, "/");
        strcat(file_path, dir_ptr->d_name);

        /* get file/sub-directory attributes */
        stat(file_path, &stat_buf);

        /* check if item is directory */
        if (S_ISDIR(stat_buf.st_mode)) {
            /* ignore "." and ".." reference directories */
            if (strcmp(dir_ptr->d_name, ".") == 0 || strcmp(dir_ptr->d_name, "..") == 0) {
                continue;
            }

            /* recursion to calculate size of sub-directory */
            long long int dir_size = calculate_directory_size(file_path);
            total_size += dir_size;
        }
        /* calculate size of regular file */
        else {
            total_size += stat_buf.st_size;
        }
    }

    /* close directory pointer */
    closedir(dir);

    /* return total directory size */
    return total_size;
}

/* main function to analyze C disk space */
int main() {
    printf("C Disk Space Analyzer\n");

    /* calculate size of C drive */
    long long int total_c_size = calculate_directory_size("C:");

    /* check if calculation is successful */
    if (total_c_size != -1) {
        printf("C Drive Size: %lld bytes\n", total_c_size);
    }

    return 0;
}