//FormAI DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct File {
    char *name;
} File;

typedef struct Directory {
    char *name;
    int num_files;
    File **files;
} Directory;

void print_files(Directory *dir) {
    printf("%s:\n", dir->name);
    for (int i = 0; i < dir->num_files; i++) {
        printf("\t%s\n", dir->files[i]->name);
    }
}

void backup_file(Directory *source, Directory *destination, char *filename) {
    int source_file_index = -1;
    for (int i = 0; i < source->num_files; i++) {
        if (strcmp(source->files[i]->name, filename) == 0) {
            source_file_index = i;
            break;
        }
    }
    if (source_file_index == -1) {
        printf("Error: File not found in source directory\n");
        return;
    }
    File *file_copy = malloc(sizeof(File));
    file_copy->name = malloc(strlen(source->files[source_file_index]->name)+1);
    strcpy(file_copy->name, source->files[source_file_index]->name);
    int destination_file_index = -1;
    for (int i = 0; i < destination->num_files; i++) {
        if (strcmp(destination->files[i]->name, filename) == 0) {
            destination_file_index = i;
            free(destination->files[i]);
            break;
        }
    }
    if (destination_file_index == -1) {
        destination->num_files++;
        destination->files = realloc(destination->files, destination->num_files*sizeof(File*));
        destination_file_index = destination->num_files-1;
    }
    destination->files[destination_file_index] = file_copy;
}

void backup_directory(Directory *source, Directory *destination) {
    printf("Backing up directory %s...\n", source->name);
    for (int i = 0; i < source->num_files; i++) {
        backup_file(source, destination, source->files[i]->name);
    }
}

int main() {
    Directory *home = malloc(sizeof(Directory));
    home->name = "home";
    home->num_files = 4;
    home->files = malloc(4*sizeof(File*));
    home->files[0] = malloc(sizeof(File));
    home->files[0]->name = "file1.txt";
    home->files[1] = malloc(sizeof(File));
    home->files[1]->name = "file2.txt";
    home->files[2] = malloc(sizeof(File));
    home->files[2]->name = "file3.txt";
    home->files[3] = malloc(sizeof(File));
    home->files[3]->name = "file4.txt";
    Directory *backup = malloc(sizeof(Directory));
    backup->name = "backup";
    backup->num_files = 0;
    backup->files = NULL;
    print_files(home);
    printf("\n");
    backup_directory(home, backup);
    printf("\n");
    print_files(backup);

    return 0;
}