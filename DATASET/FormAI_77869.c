//FormAI DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_LENGTH 1024

typedef struct {
    char* buffer;
    size_t size;
} FileContents;

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    FileContents contents;
} File;

typedef struct {
    File* files;
    size_t used;
    size_t size;
} FileList;

void init_file_list(FileList* list) {
    list->files = malloc(1 * sizeof(File));
    list->used = 0;
    list->size = 1;
}

void add_file(FileList* list, const char* filename, const char* backup_filename) {
    if (list->used == list->size) {
        list->size *= 2;
        list->files = realloc(list->files, list->size * sizeof(File));
    }

    File file = { .filename = { 0 } };
    strncpy(file.filename, backup_filename, MAX_FILENAME_LENGTH - 1);

    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Failed to open file '%s'\n", filename);
        return;
    }

    fseek(f, 0, SEEK_END);
    file.contents.buffer = malloc(ftell(f));
    file.contents.size = ftell(f);
    rewind(f);

    fread(file.contents.buffer, 1, file.contents.size, f);
    fclose(f);

    list->files[list->used++] = file;
}

int main() {
    FileList backup_files;
    init_file_list(&backup_files);

    add_file(&backup_files, "file1.txt", "backup_file1.txt");
    add_file(&backup_files, "file2.txt", "backup_file2.txt");

    for (size_t i = 0; i < backup_files.used; i++) {
        File file = backup_files.files[i];
        FILE* f = fopen(file.filename, "w");
        fwrite(file.contents.buffer, 1, file.contents.size, f);
        fclose(f);

        printf("Successfully backed up '%s'\n", file.filename);
    }

    for (size_t i = 0; i < backup_files.used; i++) {
        free(backup_files.files[i].contents.buffer);
    }
    free(backup_files.files);

    return 0;
}