//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define DIR_MODE S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        return 1;
    }

    const char *src_dir = argv[1];
    const char *dst_dir = argv[2];

    DIR *src_dirp = opendir(src_dir);
    if (!src_dirp) {
        printf("Error: could not open source directory: %s\n", src_dir);
        return 1;
    }

    DIR *dst_dirp = opendir(dst_dir);
    if (!dst_dirp) {
        printf("Destination directory does not exist, creating...\n");
        if (mkdir(dst_dir, DIR_MODE) == -1) {
            printf("Error: could not create destination directory: %s\n", dst_dir);
            return 1;
        }
        dst_dirp = opendir(dst_dir);
    }

    // Iterate over source directory
    struct dirent *dir_entry;
    while ((dir_entry = readdir(src_dirp)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        // Construct source and destination paths
        char src_path[512];
        char dst_path[512];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, dir_entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, dir_entry->d_name);

        struct stat src_stat;
        if (stat(src_path, &src_stat) == -1) {
            printf("Error: could not read stat of %s\n", src_path);
            continue;
        }

        // Check if file/directory exists in destination directory
        struct stat dst_stat;
        if (stat(dst_path, &dst_stat) != -1) {
            if (S_ISDIR(src_stat.st_mode)) {
                printf("Skipping directory %s\n", src_path);
                continue;
            }

            if (src_stat.st_mtime <= dst_stat.st_mtime) {
                printf("Skipping unchanged file %s\n", src_path);
                continue;
            }

            printf("Updating file %s\n", src_path);

            // Remove existing file
            if (remove(dst_path) != 0) {
                printf("Error: could not remove existing file %s", dst_path);
                continue;
            }
        } else {
            printf("Creating file %s\n", src_path);
        }

        if (S_ISDIR(src_stat.st_mode)) {
            // Create directory
            if (mkdir(dst_path, DIR_MODE) == -1) {
                printf("Error: could not create directory %s\n", dst_path);
                continue;
            }

            // Recursively synchronize subdirectory
            char sub_src_path[512];
            char sub_dst_path[512];
            snprintf(sub_src_path, sizeof(sub_src_path), "%s/%s", src_dir, dir_entry->d_name);
            snprintf(sub_dst_path, sizeof(sub_dst_path), "%s/%s", dst_dir, dir_entry->d_name);

            printf("Syncing directory %s\n", sub_src_path);

            char *args[] = { argv[0], sub_src_path, sub_dst_path, NULL };
            execv(argv[0], args);

        } else {
            // Copy file
            FILE *src_file = fopen(src_path, "r");
            if (!src_file) {
                printf("Error: could not open source file %s\n", src_path);
                continue;
            }

            FILE *dst_file = fopen(dst_path, "w");
            if (!dst_file) {
                printf("Error: could not open destination file %s\n", dst_path);
                fclose(src_file);
                continue;
            }

            char buffer[1024];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dst_file);
            }

            fclose(src_file);
            fclose(dst_file);

            // Set permissions and modification time
            chmod(dst_path, src_stat.st_mode);
            utimes(dst_path, &(struct timeval[]){{ src_stat.st_atime, src_stat.st_mtime }});
        }
    }

    closedir(src_dirp);
    closedir(dst_dirp);

    return 0;
}