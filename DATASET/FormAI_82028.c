//FormAI DATASET v1.0 Category: File system simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 65536
#define MAX_FILES 1024
#define MAX_FILENAME_LENGTH 20

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int used_blocks[MAX_BLOCKS];
} File;

typedef struct {
    int free_blocks[MAX_BLOCKS];
    int next_free_block;
} BlockManager;

typedef struct {
    File files[MAX_FILES];
    BlockManager block_manager;
} FileSystem;

void init_block_manager(BlockManager *bm) {
    int i;

    for (i = 0; i < MAX_BLOCKS; i++) {
        bm->free_blocks[i] = 1;
    }

    bm->next_free_block = 0;
}

void init_file_system(FileSystem *fs) {
    int i;

    for (i = 0; i < MAX_FILES; i++) {
        fs->files[i].name[0] = '\0';
        fs->files[i].size = 0;
    }

    init_block_manager(&fs->block_manager);
}

int get_next_free_block(BlockManager *bm) {
    int i;
    int result = bm->next_free_block;

    for (i = bm->next_free_block; i < MAX_BLOCKS; i++) {
        if (bm->free_blocks[i] == 1) {
            result = i;
            bm->next_free_block = i;
            break;
        }
    }

    if (result == MAX_BLOCKS) {
        printf("Error: no more free blocks\n");
        return -1;
    }

    bm->free_blocks[result] = 0;

    return result;
}

void free_blocks(BlockManager *bm, File *file) {
    int i;

    for (i = 0; i < MAX_BLOCKS; i++) {
        if (file->used_blocks[i] != -1) {
            bm->free_blocks[file->used_blocks[i]] = 1;
            file->used_blocks[i] = -1;
        }
    }

    file->size = 0;
}

int get_file_index(FileSystem *fs, char *name) {
    int i;

    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void create_file(FileSystem *fs, char *name, int size) {
    int i;
    int file_index = get_file_index(fs, name);

    if (file_index != -1) {
        printf("File %s already exists, overwriting...\n", name);
        free_blocks(&fs->block_manager, &fs->files[file_index]);
    } else {
        for (i = 0; i < MAX_FILES; i++) {
            if (fs->files[i].name[0] == '\0') {
                file_index = i;
                break;
            }
        }
        strncpy(fs->files[file_index].name, name, MAX_FILENAME_LENGTH);
    }

    fs->files[file_index].size = size;

    for (i = 0; i < MAX_BLOCKS; i++) {
        if (size <= 0) {
            break;
        }
        if (fs->block_manager.free_blocks[i] == 1) {
            fs->files[file_index].used_blocks[i] = get_next_free_block(&fs->block_manager);
            size -= BLOCK_SIZE;
        }
    }

    if (size > 0) {
        printf("Error: file size too large\n");
        free_blocks(&fs->block_manager, &fs->files[file_index]);
    }
}

void delete_file(FileSystem *fs, char *name) {
    int file_index = get_file_index(fs, name);

    if (file_index == -1) {
        printf("Error: file not found\n");
        return;
    }

    free_blocks(&fs->block_manager, &fs->files[file_index]);
    fs->files[file_index].name[0] = '\0';
    fs->files[file_index].size = 0;
}

void list_files(FileSystem *fs) {
    int i;

    for (i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name[0] != '\0') {
            printf("%s\n", fs->files[i].name);
        }
    }
}

void usage() {
    printf("Usage: command args\n");
    printf("Commands:\n");
    printf("  list\n");
    printf("  create file size\n");
    printf("  delete file\n");
}

int main(int argc, char **argv) {
    char *command;
    char *arg1;
    char *arg2;
    FileSystem fs;
    int size;

    init_file_system(&fs);

    while (1) {
        printf("> ");
        scanf("%ms", &command);

        if (strcmp(command, "list") == 0) {
            list_files(&fs);
        } else if (strcmp(command, "create") == 0) {
            scanf("%ms %d", &arg1, &size);
            create_file(&fs, arg1, size);
            free(arg1);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%ms", &arg1);
            delete_file(&fs, arg1);
            free(arg1);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            usage();
        }

        free(command);
    }

    return 0;
}