//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

// Function to compare two files and return 1 if they are different
int compare_files(char* file1_path, char* file2_path) {
    FILE* file1 = fopen(file1_path, "rb");
    FILE* file2 = fopen(file2_path, "rb");
    if (!file1 || !file2) {
        printf("Error: Could not open files for comparison\n");
        exit(1);
    }
    char c1, c2;
    while ((c1 = fgetc(file1)) != EOF) {
        if ((c2 = fgetc(file2)) == EOF) {
            fclose(file1);
            fclose(file2);
            return 1;
        }
        if (c1 != c2) {
            fclose(file1);
            fclose(file2);
            return 1;
        }
    }
    if (fgetc(file2) != EOF) {
        fclose(file1);
        fclose(file2);
        return 1;
    }
    fclose(file1);
    fclose(file2);
    return 0;
}

// Function to copy a file
void copy_file(char* src_path, char* dest_path) {
    FILE* src = fopen(src_path, "rb");
    FILE* dest = fopen(dest_path, "wb");
    if (!src || !dest) {
        printf("Error: Could not copy files\n");
        exit(1);
    }
    char c;
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }
    fclose(src);
    fclose(dest);
}

// Function to synchronize two directories
void synchronize_directories(char* src_path, char* dest_path) {
    DIR* src_dir = opendir(src_path);
    DIR* dest_dir = opendir(dest_path);
    if (!src_dir || !dest_dir) {
        printf("Error: Could not open directories for synchronization\n");
        exit(1);
    }
    struct dirent* src_file;
    struct dirent* dest_file;
    while ((src_file = readdir(src_dir)) != NULL) {
        if (strcmp(src_file->d_name, ".") == 0 || strcmp(src_file->d_name, "..") == 0) {
            continue;
        }
        char* src_file_path = malloc(strlen(src_path) + strlen(src_file->d_name) + 2);
        strcpy(src_file_path, src_path);
        strcat(src_file_path, "/");
        strcat(src_file_path, src_file->d_name);
        char* dest_file_path = malloc(strlen(dest_path) + strlen(src_file->d_name) + 2);
        strcpy(dest_file_path, dest_path);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, src_file->d_name);
        struct stat src_file_stat;
        stat(src_file_path, &src_file_stat);
        if (S_ISDIR(src_file_stat.st_mode)) {
            mkdir(dest_file_path, 0755);
            synchronize_directories(src_file_path, dest_file_path);
        } else {
            dest_file = NULL;
            while ((dest_file = readdir(dest_dir)) != NULL) {
                if (strcmp(dest_file->d_name, ".") == 0 || strcmp(dest_file->d_name, "..") == 0) {
                    continue;
                }
                if (strcmp(dest_file->d_name, src_file->d_name) == 0) {
                    char* dest_file_path2 = malloc(strlen(dest_path) + strlen(dest_file->d_name) + 2);
                    strcpy(dest_file_path2, dest_path);
                    strcat(dest_file_path2, "/");
                    strcat(dest_file_path2, dest_file->d_name);
                    struct stat dest_file_stat;
                    stat(dest_file_path2, &dest_file_stat);
                    if (src_file_stat.st_mtime > dest_file_stat.st_mtime || compare_files(src_file_path, dest_file_path2)) {
                        copy_file(src_file_path, dest_file_path2);
                    }
                    free(dest_file_path2);
                    break;
                }
            }
            if (!dest_file) {
                copy_file(src_file_path, dest_file_path);
            }
        }
        free(src_file_path);
        free(dest_file_path);
        rewinddir(dest_dir);
    }
    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(1);
    }
    synchronize_directories(argv[1], argv[2]);
    printf("Directories synchronized successfully\n");
    return 0;
}