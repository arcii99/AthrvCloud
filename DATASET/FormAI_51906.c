//FormAI DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int file_exists(char* filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void copy_file(char* source_path, char* destination_path) {
    int source_fd = open(source_path, O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    int destination_fd = open(destination_path, O_WRONLY|O_CREAT, 0777);
    if (destination_fd == -1) {
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    int n;
    char buffer[BUFFER_SIZE];
    while ((n = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(destination_fd, buffer, n) != n) {
            perror("Error writing to destination file");
            exit(EXIT_FAILURE);
        }
    }

    if (n == -1) {
        perror("Error reading from source file");
        exit(EXIT_FAILURE);
    }

    close(source_fd);
    close(destination_fd);
}

void sync_files(char* source_dir, char* destination_dir) {
    DIR* source_d = opendir(source_dir);
    DIR* destination_d = opendir(destination_dir);

    if (source_d == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    if (destination_d == NULL) {
        perror("Error opening destination directory");
        exit(EXIT_FAILURE);
    }

    struct dirent* source_de;
    while ((source_de = readdir(source_d)) != NULL) {
        char source_path[BUFFER_SIZE];
        snprintf(source_path, BUFFER_SIZE, "%s%s", source_dir, source_de->d_name);

        // check if the file exists in the destination directory
        if (file_exists(source_path)) {
            char destination_path[BUFFER_SIZE];
            snprintf(destination_path, BUFFER_SIZE, "%s%s", destination_dir, source_de->d_name);

            struct stat source_sb;
            struct stat destination_sb;

            // get source file stats
            if (stat(source_path, &source_sb) == -1) {
                perror("Error getting source file stats");
                exit(EXIT_FAILURE);
            }

            // get destination file stats
            int destination_file_exists = stat(destination_path, &destination_sb) == 0;
            if (destination_file_exists == -1 && errno != ENOENT) {
                perror("Error getting destination file stats");
                exit(EXIT_FAILURE);
            }

            // check if the file in the destination directory is older than the source file
            if (destination_file_exists) {
                if (source_sb.st_mtime > destination_sb.st_mtime) {
                    copy_file(source_path, destination_path);
                    printf("Copied file %s\n", source_de->d_name);
                }
            } else { // the file does not exist in the destination directory
                copy_file(source_path, destination_path);
                printf("Copied file %s\n", source_de->d_name);
            }
        }
    }

    closedir(source_d);
    closedir(destination_d);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s source_dir destination_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* source_dir = argv[1];
    char* destination_dir = argv[2];

    while (1) {
        sync_files(source_dir, destination_dir);
        sleep(10); // check every 10 seconds
    }

    exit(EXIT_SUCCESS);
}