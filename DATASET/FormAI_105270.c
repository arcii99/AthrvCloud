//FormAI DATASET v1.0 Category: Data recovery tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_block {
    char data[512];
};

struct file {
    char name[20];
    int start_block;
    int size;
    struct file *next_file;
};

struct file_system {
    struct data_block blocks[10000];
    struct file *root;
};

void init_file_system(struct file_system *fs) {
    memset(fs, 0, sizeof(struct file_system));
}

struct file *create_file(struct file_system *fs, char *name, int size) {
    struct file *f = malloc(sizeof(struct file));
    strcpy(f->name, name);
    f->size = size;

    int num_blocks = size / 512;
    if (size % 512 > 0) num_blocks++;

    for (int i = 0; i < num_blocks; i++) {
        int block_num = find_free_block(fs);
        if (block_num == -1) {
            printf("ERROR: Drive is full!\n");
            free(f);
            return NULL;
        }
        if (i == 0) {
            f->start_block = block_num;
        }
        write_block(fs, block_num, "");
    }

    f->next_file = fs->root;
    fs->root = f;

    return f;
}

void delete_file(struct file_system *fs, char *name) {
    struct file *curr = fs->root;
    struct file *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL) {
                fs->root = curr->next_file;
            } else {
                prev->next_file = curr->next_file;
            }
            int start_block = curr->start_block;
            int num_blocks = curr->size / 512;
            if (curr->size % 512 > 0) num_blocks++;

            for (int i = 0; i < num_blocks; i++) {
                free_block(fs, start_block);
                start_block++;
            }

            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next_file;
    }
    printf("ERROR: File not found\n");
}

void write_block(struct file_system *fs, int block_num, char *data) {
    strcpy(fs->blocks[block_num].data, data);
}

char *read_block(struct file_system *fs, int block_num) {
    return fs->blocks[block_num].data;
}

void print_file(struct file *f) {
    printf("%s\n", f->name);
    printf("Size: %d\n", f->size);
    printf("Start block: %d\n", f->start_block);
}

void print_file_system(struct file_system *fs) {
    struct file *curr = fs->root;
    while (curr != NULL) {
        print_file(curr);
        curr = curr->next_file;
    }
}

int find_free_block(struct file_system *fs) {
    for (int i = 0; i < 10000; i++) {
        if (strlen(fs->blocks[i].data) == 0) {
            return i;
        }
    }
    return -1;
}

void free_block(struct file_system *fs, int block_num) {
    memset(&fs->blocks[block_num], 0, sizeof(struct data_block));
}

int main() {
    struct file_system fs;
    init_file_system(&fs);

    create_file(&fs, "file1", 1024);
    create_file(&fs, "file2", 2048);
    create_file(&fs, "file3", 512);

    print_file_system(&fs);

    delete_file(&fs, "file2");

    print_file_system(&fs);

    return 0;
}