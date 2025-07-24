//FormAI DATASET v1.0 Category: File system simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_DIRECTORY_DEPTH 10
#define MAX_FILE_SIZE 1024
#define DIRECTORY_CLUSTER_INDEX 0

// Directory structure
struct Directory {
    int cluster_index;
    char name[MAX_FILENAME_LENGTH];
    int parent_directory_cluster_index;
    int child_directory_count;
    int child_directories[MAX_DIRECTORY_DEPTH];
    int child_file_count;
    int child_files[MAX_DIRECTORY_DEPTH];
};

// Helper function to read a directory
void read_directory(struct Directory *directory, FILE *file) {
    fread(&directory->cluster_index, sizeof(int), 1, file);
    fread(&directory->name, sizeof(char), MAX_FILENAME_LENGTH, file);
    fread(&directory->parent_directory_cluster_index, sizeof(int), 1, file);
    fread(&directory->child_directory_count, sizeof(int), 1, file);
    fread(&directory->child_directories, sizeof(int), MAX_DIRECTORY_DEPTH, file);
    fread(&directory->child_file_count, sizeof(int), 1, file);
    fread(&directory->child_files, sizeof(int), MAX_DIRECTORY_DEPTH, file);
}

// Helper function to write a directory
void write_directory(struct Directory *directory, FILE *file) {
    fwrite(&directory->cluster_index, sizeof(int), 1, file);
    fwrite(&directory->name, sizeof(char), MAX_FILENAME_LENGTH, file);
    fwrite(&directory->parent_directory_cluster_index, sizeof(int), 1, file);
    fwrite(&directory->child_directory_count, sizeof(int), 1, file);
    fwrite(&directory->child_directories, sizeof(int), MAX_DIRECTORY_DEPTH, file);
    fwrite(&directory->child_file_count, sizeof(int), 1, file);
    fwrite(&directory->child_files, sizeof(int), MAX_DIRECTORY_DEPTH, file);
}

int main() {
    // Initialize the file system
    int file_system_size = 10000;
    char file_system_name[] = "my_file_system.fsys";
    FILE *file_system = fopen(file_system_name, "w+b");
    char *file_system_data = calloc(file_system_size, sizeof(char));
    fwrite(file_system_data, sizeof(char), file_system_size, file_system);
    fclose(file_system);

    // Mount the file system
    file_system = fopen(file_system_name, "r+b");
    fseek(file_system, 0, SEEK_SET);

    // Create the root directory
    struct Directory root_directory = {
        .cluster_index = DIRECTORY_CLUSTER_INDEX,
        .name = "/",
        .parent_directory_cluster_index = DIRECTORY_CLUSTER_INDEX,
        .child_directory_count = 0,
        .child_directories = {0},
        .child_file_count = 0,
        .child_files = {0}
    };
    int root_directory_cluster_index = DIRECTORY_CLUSTER_INDEX;
    fseek(file_system, root_directory_cluster_index, SEEK_SET);
    write_directory(&root_directory, file_system);

    // Create a subdirectory
    struct Directory subdirectory = {
        .cluster_index = file_system_size,
        .name = "subdirectory",
        .parent_directory_cluster_index = root_directory_cluster_index,
        .child_directory_count = 0,
        .child_directories = {0},
        .child_file_count = 0,
        .child_files = {0}
    };
    root_directory.child_directories[root_directory.child_directory_count++] = subdirectory.cluster_index;
    fseek(file_system, subdirectory.cluster_index, SEEK_SET);
    write_directory(&subdirectory, file_system);

    // Create a file in the subdirectory
    struct File {
        int cluster_index;
        char name[MAX_FILENAME_LENGTH];
        int parent_directory_cluster_index;
        char data[MAX_FILE_SIZE];
    } file;
    strcpy(file.name, "example.txt");
    file.parent_directory_cluster_index = subdirectory.cluster_index;
    strncpy(file.data, "This is an example file.", MAX_FILE_SIZE);
    fseek(file_system, file_system_size, SEEK_SET);
    fwrite(file.data, sizeof(char), strlen(file.data), file_system);
    file.cluster_index = file_system_size;
    subdirectory.child_files[subdirectory.child_file_count++] = file.cluster_index;
    fseek(file_system, file.cluster_index, SEEK_SET);
    fwrite(&file, sizeof(struct File), 1, file_system);

    // Save the changes and unmount the file system
    fseek(file_system, root_directory_cluster_index, SEEK_SET);
    write_directory(&root_directory, file_system);
    fseek(file_system, subdirectory.cluster_index, SEEK_SET);
    write_directory(&subdirectory, file_system);
    fclose(file_system);
    free(file_system_data);

    return 0;
}