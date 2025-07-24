//FormAI DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_BLOCKS 50

struct file {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    int block_ids[10];
};

struct block {
    char data[1024];
};

struct file_system {
    struct file files[MAX_BLOCKS];
    struct block blocks[MAX_BLOCKS];
    int free_blocks[MAX_BLOCKS];
    int file_count;
    int block_count;
};

void initialize_file_system(struct file_system *fs) {
    int i;
    for(i=0; i<MAX_BLOCKS; i++) {
        sprintf(fs->blocks[i].data, "Block %d", i);
        fs->free_blocks[i] = 1;
    }
    fs->file_count = 0;
    fs->block_count = MAX_BLOCKS;
}

int allocate_blocks(struct file_system *fs, int size) {
    int i, j, k = 0;
    int start = -1;
    for(i=0; i<fs->block_count; i++) {
        if(fs->free_blocks[i] == 1) {
            if(start == -1) {
                start = i;
            }
            k++;
            if(k == size) {
                break;
            }
        } else {
            k = 0;
            start = -1;
        }
    }
    if(k == size) {
        for(j=start; j<start+size; j++) {
            fs->free_blocks[j] = 0;
        }
        return start;
    }
    return -1;
}

void create_file(struct file_system *fs, char *name, int size) {
    int block_id = allocate_blocks(fs, size);
    if(block_id == -1) {
        printf("Not enough space to allocate file %s with size %d\n", name, size);
        return;
    }
    struct file *f = &fs->files[fs->file_count];
    strcpy(f->name, name);
    f->size = size;
    int i;
    for(i=0; i<size; i++) {
        f->block_ids[i] = block_id + i;
    }
    fs->file_count++;
}

void delete_file(struct file_system *fs, char *name) {
    int i, j, k;
    for(i=0; i<fs->file_count; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            for(j=0; j<fs->files[i].size; j++) {
                int block_id = fs->files[i].block_ids[j];
                fs->free_blocks[block_id] = 1;
            }
            for(k=i+1; k<fs->file_count; k++) {
                fs->files[k-1] = fs->files[k];
            }
            fs->file_count--;
            return;
        }
    }
    printf("File %s not found\n", name);
}

void display_file_system(struct file_system *fs) {
    int i, j;
    printf("Files:\n");
    for(i=0; i<fs->file_count; i++) {
        struct file f = fs->files[i];
        printf("\t%s, size: %d blocks:", f.name, f.size);
        for(j=0; j<f.size; j++) {
            printf(" %d", f.block_ids[j]);
        }
        printf("\n");
    }
    printf("Blocks:\n");
    for(i=0; i<fs->block_count; i++) {
        printf("\t%d: %s\n", i, fs->blocks[i].data);
    }
}

int main() {
    struct file_system fs;
    initialize_file_system(&fs);
    create_file(&fs, "file1", 3);
    create_file(&fs, "file2", 7);
    create_file(&fs, "file3", 4);
    display_file_system(&fs);
    delete_file(&fs, "file2");
    display_file_system(&fs);
    return 0;
}