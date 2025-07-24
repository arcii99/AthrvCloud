//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_LENGTH 50
#define FILE_CONTENT_MAX_LENGTH 100

typedef struct File {
    char name[FILE_NAME_MAX_LENGTH];
    char content[FILE_CONTENT_MAX_LENGTH];
} File;

typedef struct FileSystem {
    int num_files;
    File files[BUFFER_SIZE];
} FileSystem;

void add_file(FileSystem* fs, const char* name, const char* content) {
    if(fs->num_files == BUFFER_SIZE) {
        printf("Error: Cannot add file. Maximum number of files reached.\n");
        return;
    }

    for(int i=0;i<fs->num_files;i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            printf("Error: Cannot add file. File with name %s already exists.\n", name);
            return;
        }
    }

    File new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);

    fs->files[fs->num_files] = new_file;
    fs->num_files++;

    printf("File %s added successfully.\n", name);
}

void delete_file(FileSystem* fs, const char* name) {
    for(int i=0;i<fs->num_files;i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            for(int j=i;j<fs->num_files-1;j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File %s deleted successfully.\n", name);
            return;
        }
    }

    printf("Error: Cannot delete file. File with name %s does not exist.\n", name);
}

void print_files(FileSystem* fs) {
    printf("Files in FileSystem:\n");
    for(int i=0;i<fs->num_files;i++) {
        printf("- %s\n", fs->files[i].name);
    }
}

int main() {
    FileSystem fs;
    fs.num_files = 0;

    add_file(&fs, "file1.txt", "This is the content of file1.");
    add_file(&fs, "file2.txt", "This is the content of file2.");
    add_file(&fs, "file3.txt", "This is the content of file3.");
    print_files(&fs);

    delete_file(&fs, "file2.txt");
    print_files(&fs);

    add_file(&fs, "file4.txt", "This is the content of file4.");
    add_file(&fs, "file1.txt", "This is the new content of file1.");
    print_files(&fs);

    delete_file(&fs, "file3.txt");
    delete_file(&fs, "file5.txt");
    print_files(&fs);

    return 0;
}