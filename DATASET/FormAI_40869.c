//FormAI DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FILES 10000
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 100000000
#define CHUNK_SIZE 10000

typedef struct file {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
    bool empty;
} File;

typedef struct file_synchronizer {
    File* files[MAX_FILES];
    int num_files;
    bool is_master;
    char master_ip[20];
} FileSynchronizer;

void init_files(File** files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        files[i] = (File*)malloc(sizeof(File));
        files[i]->empty = true;
    }
}

void destroy_files(File** files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        free(files[i]);
    }
}

void add_file(FileSynchronizer* fs, char* name, int size) {
    if (fs->num_files == MAX_FILES) {
        printf("Max number of files exceeded!\n");
        return;
    }
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    file->empty = false;
    fs->files[fs->num_files++] = file;
}

void master_sync(FileSynchronizer* fs) {
    for (int i = 0; i < fs->num_files; i++) {
        if (fs->files[i]->empty) {
            printf("File %s is empty!\n", fs->files[i]->name);
            continue;
        }
        int num_chunks = (fs->files[i]->size + CHUNK_SIZE - 1) / CHUNK_SIZE;
        char message[10];
        sprintf(message, "%d", num_chunks);
        for (int j = 0; j < num_chunks; j++) {
            sleep(1);
            printf("Sending chunk %d of %d of file %s...\n", j+1, num_chunks, fs->files[i]->name);
        }
    }
}

void slave_sync(FileSynchronizer* fs) {
    printf("Connecting to master at IP address %s...\n", fs->master_ip);
    for (int i = 0; i < fs->num_files; i++) {
        if (fs->files[i]->empty) {
            printf("File %s is empty!\n", fs->files[i]->name);
            continue;
        }
        int num_chunks = (fs->files[i]->size + CHUNK_SIZE - 1) / CHUNK_SIZE;
        for (int j = 0; j < num_chunks; j++) {
            sleep(1);
            printf("Receiving chunk %d of %d of file %s...\n", j+1, num_chunks, fs->files[i]->name);
        }
    }
}

int main(int argc, char** argv) {
    srand(time(NULL));
    FileSynchronizer fs;
    fs.num_files = 0;
    int num_files = rand() % 10 + 1;
    init_files(fs.files, num_files);
    for (int i = 0; i < num_files; i++) {
        char name[MAX_FILE_NAME_LEN];
        sprintf(name, "file%d", i);
        int size = rand() % MAX_FILE_SIZE + 1;
        add_file(&fs, name, size);
    }
    printf("Files:\n");
    for (int i = 0; i < fs.num_files; i++) {
        printf("  %s (%d bytes)\n", fs.files[i]->name, fs.files[i]->size);
    }
    if (argc == 1) {
        fs.is_master = true;
        printf("I am Master!\n");
        master_sync(&fs);
    } else {
        fs.is_master = false;
        strcpy(fs.master_ip, argv[1]);
        printf("I am Slave! My Master's IP address is %s\n", fs.master_ip);
        slave_sync(&fs);
    }
    destroy_files(fs.files, fs.num_files);
    return 0;
}