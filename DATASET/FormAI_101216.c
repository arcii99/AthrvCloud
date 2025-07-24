//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_FILES 1000
#define MAX_FILENAME 100
#define MAX_PATH 500
#define MAX_BUFFER 1024

/* Struct to store file info */
typedef struct {
    char filename[MAX_FILENAME];
    char path[MAX_PATH];
    long timestamp;
} file_info;

/* Function to read all files from directory and return file_info array */
int read_directory(char* directory_path, file_info* files) {
    DIR* folder;
    struct dirent* file;
    struct stat file_stat;
    int count = 0;

    folder = opendir(directory_path);
    if (folder == NULL) {
        printf("Error opening directory: %s\n", directory_path);
        return -1;
    }

    while ((file = readdir(folder)) != NULL) {
        char file_path[MAX_PATH];
        strcpy(file_path, directory_path);
        strcat(file_path, "/");
        strcat(file_path, file->d_name);

        if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) {
            continue;
        }

        if (stat(file_path, &file_stat) < 0) {
            printf("Error obtaining file info: %s\n", file_path);
            continue;
        }

        strcpy(files[count].filename, file->d_name);
        strcpy(files[count].path, file_path);
        files[count].timestamp = file_stat.st_mtime;

        count++;
    }

    closedir(folder);
    return count;
}

/* Function to synchronize two directories */
bool sync_directories(char* source, char* destination) {
    file_info source_files[MAX_FILES];
    file_info destination_files[MAX_FILES];
    int source_file_count = read_directory(source, source_files);
    int destination_file_count = read_directory(destination, destination_files);

    if (source_file_count < 0 || destination_file_count < 0) {
        return false;
    }

    for (int i = 0; i < source_file_count; i++) {
        bool found = false;

        for (int j = 0; j < destination_file_count; j++) {
            if (strcmp(source_files[i].filename, destination_files[j].filename) == 0) {
                found = true;

                /* Only sync if source file has newer timestamp */
                if (source_files[i].timestamp > destination_files[j].timestamp) {
                    FILE* source_file = fopen(source_files[i].path, "rb");
                    FILE* destination_file = fopen(destination_files[j].path, "wb");
                    char buffer[MAX_BUFFER];
                    size_t bytes_read;

                    if (source_file == NULL || destination_file == NULL) {
                        printf("Error opening files for synchronization: %s and %s\n", source_files[i].path, destination_files[j].path);
                        return false;
                    }

                    while ((bytes_read = fread(buffer, sizeof(char), MAX_BUFFER, source_file)) > 0) {
                        fwrite(buffer, sizeof(char), bytes_read, destination_file);
                    }

                    fclose(source_file);
                    fclose(destination_file);
                }

                break;
            }
        }

        /* Copy new file to destination if not found */
        if (!found) {
            char destination_path[MAX_PATH];
            strcpy(destination_path, destination);
            strcat(destination_path, "/");
            strcat(destination_path, source_files[i].filename);

            FILE* source_file = fopen(source_files[i].path, "rb");
            FILE* destination_file = fopen(destination_path, "wb");
            char buffer[MAX_BUFFER];
            size_t bytes_read;

            if (source_file == NULL || destination_file == NULL) {
                printf("Error opening files for copying: %s and %s\n", source_files[i].path, destination_path);
                return false;
            }

            while ((bytes_read = fread(buffer, sizeof(char), MAX_BUFFER, source_file)) > 0) {
                fwrite(buffer, sizeof(char), bytes_read, destination_file);
            }

            fclose(source_file);
            fclose(destination_file);
        }
    }

    return true;
}

/* Main function */
int main() {
    char source[MAX_PATH] = "source";
    char destination[MAX_PATH] = "backup";

    bool success = sync_directories(source, destination);

    if (success) {
        printf("Directories synchronized.\n");
    } else {
        printf("Error synchronizing directories.\n");
    }

    return 0;
}