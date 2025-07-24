//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int sync_files(const char *src, const char *dest) {
    char bfr[BUFFER_SIZE];
    struct dirent *entry;
    struct stat ssrc, sdest;
    DIR *dir = opendir(src);
    if (dir == NULL) {
        printf("Error opening source directory %s\n", src);
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char src_path[BUFFER_SIZE], dest_path[BUFFER_SIZE];
        snprintf(src_path, BUFFER_SIZE, "%s/%s", src, entry->d_name);
        snprintf(dest_path, BUFFER_SIZE, "%s/%s", dest, entry->d_name);
        if (stat(src_path, &ssrc) == -1) {
            printf("Error getting details of %s\n", src_path);
            continue;
        }
        if (stat(dest_path, &sdest) != -1) {
            if (S_ISDIR(ssrc.st_mode)) { // If source is a directory
                if (!S_ISDIR(sdest.st_mode)) { // but destination is not
                    printf("Removing %s\n", dest_path);
                    if (remove(dest_path) != 0) {
                        printf("Error removing %s\n", dest_path);
                    }
                }
                else {
                    if (sync_files(src_path, dest_path) != 0) {
                        printf("Error syncing subdirectories\n");
                    }
                }
            }
            else { // If source is a file
                if (S_ISDIR(sdest.st_mode)) { // but destination is a directory
                    printf("Error: %s is a directory, %s is a file\n", dest_path, src_path);
                }
                else {
                    if (ssrc.st_mtime > sdest.st_mtime) { // If source is newer
                        printf("Copying %s to %s\n", src_path, dest_path);
                        FILE *src_file = fopen(src_path, "rb");
                        if (src_file == NULL) {
                            printf("Error opening %s\n", src_path);
                            continue;
                        }
                        FILE *dest_file = fopen(dest_path, "wb");
                        if (dest_file == NULL) {
                            fclose(src_file);
                            printf("Error opening %s\n", dest_path);
                            continue;
                        }
                        size_t r;
                        while ((r = fread(bfr, 1, BUFFER_SIZE, src_file)) > 0) {
                            fwrite(bfr, 1, r, dest_file);
                        }
                        fclose(src_file);
                        fclose(dest_file);
                    }
                }
            }
        }
        else { // Destination does not exist
            if (S_ISDIR(ssrc.st_mode)) { // If source is a directory
                printf("Creating %s\n", dest_path);
                #ifdef _WIN32
                if (mkdir(dest_path) != 0) {
                #else
                if (mkdir(dest_path, ssrc.st_mode) != 0) {
                #endif
                    printf("Error creating directory %s\n", dest_path);
                }
                else {
                    if (sync_files(src_path, dest_path) != 0) {
                        printf("Error syncing subdirectories\n");
                    }
                }
            }
            else { // If source is a file
                printf("Copying %s to %s\n", src_path, dest_path);
                FILE *src_file = fopen(src_path, "rb");
                if (src_file == NULL) {
                    printf("Error opening %s\n", src_path);
                    continue;
                }
                FILE *dest_file = fopen(dest_path, "wb");
                if (dest_file == NULL) {
                    fclose(src_file);
                    printf("Error opening %s\n", dest_path);
                    continue;
                }
                size_t r;
                while ((r = fread(bfr, 1, BUFFER_SIZE, src_file)) > 0) {
                    fwrite(bfr, 1, r, dest_file);
                }
                fclose(src_file);
                fclose(dest_file);
            }
        }
    }
    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}