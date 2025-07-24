//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH_LENGTH 4096
#define MAX_FILES 1024

int check_directory(char *path);
void synchronize(char *source, char *destination);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_path destination_path\n", argv[0]);
        return 1;
    }

    char *source = argv[1];
    char *destination = argv[2];

    int source_is_directory = check_directory(source);
    int destination_is_directory = check_directory(destination);

    if (!source_is_directory && !destination_is_directory) {
        printf("Error: Both source and destination must be directories.\n");
        return 1;
    }

    if (source_is_directory && destination_is_directory) {
        synchronize(source, destination);
    } else if (source_is_directory) {
        printf("Error: Only synchronized directory with directory.\n");
        return 1;
    } else {
        printf("Error: Synchronization of file is not supported yet.\n");
        return 1;
    }

    return 0;
}

int check_directory(char *path) {
    struct stat sb;

    if (stat(path, &sb) == -1) {
        printf("Error: Could not access file/directory '%s': %s.\n", path, strerror(errno));
        return 0;
    }

    if (S_ISDIR(sb.st_mode)) {
        return 1;
    } else {
        return 0;
    }
}

void synchronize(char *source, char *destination) {
    printf("Synchronizing '%s' with '%s'...\n", source, destination);

    DIR *source_dir = opendir(source);
    if (!source_dir) {
        printf("Error: Could not open source directory '%s': %s.\n", source, strerror(errno));
        return;
    }

    DIR *destination_dir = opendir(destination);
    if (!destination_dir) {
        printf("Error: Could not open destination directory '%s': %s.\n", destination, strerror(errno));
        closedir(source_dir);
        return;
    }

    struct dirent *source_entry;
    struct dirent *destination_entry;
    struct stat source_sb;
    struct stat destination_sb;
    char source_path[MAX_PATH_LENGTH];
    char destination_path[MAX_PATH_LENGTH];
    int num_files = 0;
    char *file_list[MAX_FILES];

    while ((source_entry = readdir(source_dir))) {
        if (strcmp(source_entry->d_name, ".") == 0 || strcmp(source_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source, source_entry->d_name);

        if (stat(source_path, &source_sb) == -1) {
            printf("Error: Could not access file/directory '%s': %s.\n", source_path, strerror(errno));
            continue;
        }

        if (!S_ISREG(source_sb.st_mode)) {
            continue;
        }

        num_files++;
        file_list[num_files - 1] = strdup(source_entry->d_name);
    }

    while ((destination_entry = readdir(destination_dir))) {
        if (strcmp(destination_entry->d_name, ".") == 0 || strcmp(destination_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(destination_path, MAX_PATH_LENGTH, "%s/%s", destination, destination_entry->d_name);

        if (stat(destination_path, &destination_sb) == -1) {
            printf("Error: Could not access file/directory '%s': %s.\n", destination_path, strerror(errno));
            continue;
        }

        if (!S_ISREG(destination_sb.st_mode)) {
            continue;
        }

        int i;
        for (i = 0; i < num_files; i++) {
            if (strcmp(file_list[i], destination_entry->d_name) == 0) {
                file_list[i] = NULL;
                break;
            }
        }

        if (i == num_files) {
            printf("Deleting file: %s\n", destination_entry->d_name);
            if (remove(destination_path) == -1) {
                printf("Error: Could not delete file '%s': %s.\n", destination_path, strerror(errno));
            }
        }
    }

    int i;
    for (i = 0; i < num_files; i++) {
        if (!file_list[i]) {
            continue;
        }

        snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source, file_list[i]);
        snprintf(destination_path, MAX_PATH_LENGTH, "%s/%s", destination, file_list[i]);

        printf("Copying file: %s\n", source_path);

        FILE *source_file = fopen(source_path, "r");
        if (!source_file) {
            printf("Error: Could not open source file '%s': %s.\n", source_path, strerror(errno));
            continue;
        }

        FILE *destination_file = fopen(destination_path, "w");
        if (!destination_file) {
            printf("Error: Could not create destination file '%s': %s.\n", destination_path, strerror(errno));
            fclose(source_file);
            continue;
        }

        char buffer[4096];
        int num_read;

        while ((num_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
            fwrite(buffer, 1, num_read, destination_file);
        }

        fclose(source_file);
        fclose(destination_file);
    }

    closedir(source_dir);
    closedir(destination_dir);

    printf("Synchronization complete.\n");
}