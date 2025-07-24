//FormAI DATASET v1.0 Category: File Synchronizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_PATH_LEN 1024
#define MAX_BUF_SIZE 1024

void sync_files(char* src_dir, char* dest_dir) {
    DIR* src_d = opendir(src_dir);
    if (src_d == NULL) {
        printf("Error: could not open source directory %s\n", src_dir);
        return;
    }
    DIR* dest_d = opendir(dest_dir);
    if (dest_d == NULL) {
        printf("Error: could not open destination directory %s\n", dest_dir);
        return;
    }

    struct dirent* src_dp;
    while ((src_dp = readdir(src_d)) != NULL) {
        if (strcmp(src_dp->d_name, ".") == 0 || strcmp(src_dp->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH_LEN];
        sprintf(src_path, "%s/%s", src_dir, src_dp->d_name);

        struct stat src_stat;
        if (stat(src_path, &src_stat) != 0) {
            printf("Error: could not stat file %s\n", src_path);
            continue;
        }

        // Check if file exists in destination directory
        char dest_path[MAX_PATH_LEN];
        sprintf(dest_path, "%s/%s", dest_dir, src_dp->d_name);
        struct stat dest_stat;
        bool dest_file_exists = (stat(dest_path, &dest_stat) == 0);
        
        // Check if source file is a directory
        if (S_ISDIR(src_stat.st_mode)) {
            if (!dest_file_exists) {
                // Create directory in destination if it does not exist
                mkdir(dest_path, src_stat.st_mode);
                printf("Created directory %s\n", dest_path);
                // Recursively call sync_files on nested directories
                sync_files(src_path, dest_path);
            } else {
                // Recursively call sync_files on nested directories
                sync_files(src_path, dest_path);
            }
        } else {
            // Check if the destination file exists and has a newer modification time 
            if (dest_file_exists && dest_stat.st_mtime >= src_stat.st_mtime) {
                printf("Skipping %s as destination file is newer\n", dest_path);
                continue;
            }
            printf("Copying %s to %s\n", src_path, dest_path);
            // Open source and destination files
            int src_fd = open(src_path, O_RDONLY);
            if (src_fd == -1) {
                printf("Error: could not open file %s for reading\n", src_path);
                continue;
            }
            int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
            if (dest_fd == -1) {
                printf("Error: could not open file %s for writing\n", dest_path);
                continue;
            }
            // Copy file data from source to destination
            char buf[MAX_BUF_SIZE];
            ssize_t read_bytes, write_bytes;
            while ((read_bytes = read(src_fd, buf, sizeof(buf))) > 0) {
                write_bytes = write(dest_fd, buf, read_bytes);
                if (write_bytes < read_bytes) {
                    printf("Error: could not write all bytes to %s\n", dest_path);
                    break;
                }
            }
            // Close files
            close(src_fd);
            close(dest_fd);
            // Set destination file time to match source file
            struct timeval times[2];
            times[0].tv_sec = src_stat.st_atime;
            times[0].tv_usec = 0;
            times[1].tv_sec = src_stat.st_mtime;
            times[1].tv_usec = 0;
            utimes(dest_path, times);
        }
    }
    closedir(src_d);
    closedir(dest_d);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}