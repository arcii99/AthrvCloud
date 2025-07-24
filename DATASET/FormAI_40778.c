//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void make_backup(char* filename, char* backup_dir);
void create_directory(char* backup_dir);

int main(int argc, char* argv[]) {
    char* filename;
    char* backup_dir = "./backup/";
    int opt;

    while ((opt = getopt(argc, argv, "f:b:")) != -1) {
        switch(opt) {
            case 'f':
                filename = optarg;
                break;
            case 'b':
                backup_dir = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-f filename] [-b backup_directory]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (filename == NULL) {
        fprintf(stderr, "Error: Please specify a file to backup.\n");
        exit(EXIT_FAILURE);
    }

    // create backup directory if it doesn't exist
    create_directory(backup_dir);

    make_backup(filename, backup_dir);

    return 0;
}

void make_backup(char* filename, char* backup_dir) {
    time_t current_time;
    struct tm* time_info;
    char timestamp[80], backup_filename[256];
    FILE* file, *backup_file;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    // get current time for timestamp
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", time_info);

    // build backup filename
    sprintf(backup_filename, "%s%s_%s", backup_dir, filename, timestamp);

    // open files
    file = fopen(filename, "r");
    backup_file = fopen(backup_filename, "w");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (backup_file == NULL) {
        perror("Error creating backup file");
        exit(EXIT_FAILURE);
    }

    // copy file contents to backup file
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }

    // close files
    fclose(file);
    fclose(backup_file);

    printf("Backup of %s created: %s\n", filename, backup_filename);
}

void create_directory(char* backup_dir) {
    struct stat st;

    // check if directory exists
    if (stat(backup_dir, &st) == 0) {
        // directory exists
        if (!S_ISDIR(st.st_mode)) {
            // file with the same name exists
            fprintf(stderr, "Error: %s already exists and is not a directory.\n", backup_dir);
            exit(EXIT_FAILURE);
        }
    } else {
        // directory does not exist, create it
        if (mkdir(backup_dir, 0755) == -1) {
            perror("Error creating backup directory");
            exit(EXIT_FAILURE);
        }
    }
}