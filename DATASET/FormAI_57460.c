//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILES_TO_SYNC 1000

void sync_files(const char *src_path, const char *dst_path, const char *sync_list_path);

int main(int argc, char *argv[]) {
    // Check if command-line arguments provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <source_path> <destination_path> <sync_list_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *src_path = argv[1];
    const char *dst_path = argv[2];
    const char *sync_list_path = argv[3];

    sync_files(src_path, dst_path, sync_list_path);

    return 0;
}

void sync_files(const char *src_path, const char *dst_path, const char *sync_list_path) {
    // Open sync list file
    FILE *sync_list_file = fopen(sync_list_path, "r");
    if (sync_list_file == NULL) {
        perror("Error opening sync list file");
        exit(EXIT_FAILURE);
    }

    // Read filenames from sync list file
    char file_list[MAX_FILES_TO_SYNC][MAX_PATH_LENGTH];
    int num_files_to_sync = 0;
    char buffer[MAX_PATH_LENGTH];
    while (fgets(buffer, sizeof(buffer), sync_list_file) != NULL) {
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        strncpy(file_list[num_files_to_sync], buffer, MAX_PATH_LENGTH);
        num_files_to_sync++;
    }
    fclose(sync_list_file);

    // Open source and destination directories
    DIR *src_dir = opendir(src_path);
    if (src_dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    DIR *dst_dir = opendir(dst_path);
    if (dst_dir == NULL) {
        // Create destination directory if it doesn't exist
        if (errno == ENOENT) {
            if (mkdir(dst_path, 0777) == -1) {
                perror("Error creating destination directory");
                closedir(src_dir);
                exit(EXIT_FAILURE);
            }
            dst_dir = opendir(dst_path);
        } else {
            perror("Error opening destination directory");
            closedir(src_dir);
            exit(EXIT_FAILURE);
        }
    }

    // Loop through source directory contents
    struct dirent *entry;
    while ((entry = readdir(src_dir)) != NULL) {
        // Skip special directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if source path is file or directory
        char src_path_buf[MAX_PATH_LENGTH];
        snprintf(src_path_buf, MAX_PATH_LENGTH, "%s/%s", src_path, entry->d_name);

        struct stat src_stat;
        if (stat(src_path_buf, &src_stat) == -1) {
            perror("Error getting source file stats");
            continue;
        }

        // Check if file in sync list
        int file_in_sync_list = 0;
        for (int i = 0; i < num_files_to_sync; i++) {
            if (strcmp(entry->d_name, file_list[i]) == 0) {
                file_in_sync_list = 1;
                break;
            }
        }

        // If file in sync list, sync to destination
        if (file_in_sync_list) {
            // Check if destination file exists and is up-to-date
            char dst_path_buf[MAX_PATH_LENGTH];
            snprintf(dst_path_buf, MAX_PATH_LENGTH, "%s/%s", dst_path, entry->d_name);

            struct stat dst_stat;
            if (stat(dst_path_buf, &dst_stat) != -1) {
                // Check if source file modified time is later than destination file
                if (src_stat.st_mtime > dst_stat.st_mtime) {
                    // Copy source file to destination
                    FILE *src_file = fopen(src_path_buf, "rb");
                    if (src_file == NULL) {
                        perror("Error opening source file for copying");
                        continue;
                    }

                    FILE *dst_file = fopen(dst_path_buf, "wb");
                    if (dst_file == NULL) {
                        perror("Error opening destination file for copying");
                        fclose(src_file);
                        continue;
                    }

                    char buffer[1024];
                    size_t bytes_read;
                    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, sizeof(char), bytes_read, dst_file);
                    }

                    fclose(dst_file);
                    fclose(src_file);
                }
            } else {
                // Copy source file to destination
                FILE *src_file = fopen(src_path_buf, "rb");
                if (src_file == NULL) {
                    perror("Error opening source file for copying");
                    continue;
                }

                FILE *dst_file = fopen(dst_path_buf, "wb");
                if (dst_file == NULL) {
                    perror("Error opening destination file for copying");
                    fclose(src_file);
                    continue;
                }

                char buffer[1024];
                size_t bytes_read;
                while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, sizeof(char), bytes_read, dst_file);
                }

                fclose(dst_file);
                fclose(src_file);
            }
        } else {
            // Delete file from destination if it exists
            char dst_path_buf[MAX_PATH_LENGTH];
            snprintf(dst_path_buf, MAX_PATH_LENGTH, "%s/%s", dst_path, entry->d_name);

            if (unlink(dst_path_buf) == -1 && errno != ENOENT) {
                perror("Error deleting file from destination");
                continue;
            }
        }
    }

    // Close source and destination directories
    closedir(src_dir);
    closedir(dst_dir);
}