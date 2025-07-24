//FormAI DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define FILENAME_LENGTH 64
#define MAX_FILES 1024

typedef struct {
    char name[FILENAME_LENGTH];
    int size;
    int blocks[10];
    int block_count;
} file;

typedef struct {
    char name[FILENAME_LENGTH];
    int start_block;
} directory_entry;

directory_entry directory[MAX_FILES];
file files[MAX_FILES];
int disk_space[BLOCK_SIZE];
int next_block = 0;

void initialize_disk_space() {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        disk_space[i] = -1;
    }
}

int get_free_block() {
    int free_block = -1;

    for (int i = 0; i < BLOCK_SIZE; i++) {
        if (disk_space[i] == -1) {
            free_block = i;
            disk_space[i] = 0;
            break;
        }
    }

    return free_block;
}

void empty_directory_entry(directory_entry *entry) {
    strcpy(entry->name, "");
    entry->start_block = -1;
}

void empty_file_entry(file *file) {
    strcpy(file->name, "");
    file->size = 0;
    file->block_count = 0;

    for (int i = 0; i < 10; i++) {
        file->blocks[i] = -1;
    }
}

void initialize() {
    initialize_disk_space();

    for (int i = 0; i < MAX_FILES; i++) {
        empty_directory_entry(&directory[i]);
        empty_file_entry(&files[i]);
    }
}

void save_file_to_disk(file *file) {
    for (int i = 0; i < file->block_count; i++) {
        int block_number = file->blocks[i];
        memcpy(&disk_space[block_number], &file->name[i * BLOCK_SIZE], BLOCK_SIZE);
    }
}

void read_file_from_disk(file *file) {
    for (int i = 0; i < file->block_count; i++) {
        int block_number = file->blocks[i];
        memcpy(&file->name[i * BLOCK_SIZE], &disk_space[block_number], BLOCK_SIZE);
    }
}

void create_file(char *name, int size) {
    int free_blocks[10];
    int block_count = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int i;

    for (i = 0; i < block_count; i++) {
        free_blocks[i] = get_free_block();

        if (free_blocks[i] == -1) {
            printf("Error: not enough disk space for file.\n");
            return;
        }
    }

    int file_index = -1;

    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, "") == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: too many files.\n");
        return;
    }

    file *new_file = &files[file_index];
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->block_count = block_count;

    for (i = 0; i < block_count; i++) {
        new_file->blocks[i] = free_blocks[i];
    }

    save_file_to_disk(new_file);

    int dir_index = -1;

    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(directory[i].name, "") == 0) {
            dir_index = i;
            break;
        }
    }

    if (dir_index == -1) {
        printf("Error: too many files.\n");
        return;
    }

    directory_entry *new_entry = &directory[dir_index];
    strcpy(new_entry->name, name);
    new_entry->start_block = free_blocks[0];
}

void delete_file(char *name) {
    int file_index = -1;

    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: file not found.\n");
        return;
    }

    file *file_to_delete = &files[file_index];
    int block_count = file_to_delete->block_count;

    for (int i = 0; i < block_count; i++) {
        int block_number = file_to_delete->blocks[i];
        disk_space[block_number] = -1;
    }

    empty_file_entry(file_to_delete);

    int dir_index = -1;

    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(directory[i].name, name) == 0) {
            dir_index = i;
            break;
        }
    }

    if (dir_index == -1) {
        printf("Error: file not found.\n");
        return;
    }

    directory_entry *dir_entry_to_delete = &directory[dir_index];
    empty_directory_entry(dir_entry_to_delete);
}

void print_disk_space() {
    printf("Disk Space:\n");

    for (int i = 0; i < BLOCK_SIZE; i++) {
        if (i % 16 == 0) {
            printf("\n");
        }

        if (disk_space[i] == -1) {
            printf(". ");
        } else {
            printf("+ ");
        }
    }

    printf("\n");
}

void print_directory() {
    printf("Directory:\n");

    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(directory[i].name, "") == 0) {
            continue;
        }

        printf("%s (start block %d)\n", directory[i].name, directory[i].start_block);
    }

    printf("\n");
}

void print_file(char *name) {
    int file_index = -1;

    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: file not found.\n");
        return;
    }

    printf("File Name: %s\n", files[file_index].name);
    printf("File Size: %d bytes\n", files[file_index].size);
    printf("Blocks Occupied:\n");

    for (int i = 0; i < files[file_index].block_count; i++) {
        printf("%d ", files[file_index].blocks[i]);
    }

    printf("\nFile Contents:\n");

    read_file_from_disk(&files[file_index]);

    for (int i = 0; i < files[file_index].size; i++) {
        printf("%c", files[file_index].name[i]);
    }

    printf("\n\n");
}

void handle_command(char *command) {
    char *args = strchr(command, ' ');

    if (args != NULL) {
        *args = '\0';
        args += 1;
    }

    if (strcmp(command, "create") == 0) {
        char filename[FILENAME_LENGTH];

        if (sscanf(args, "%s", filename) != 1) {
            printf("Error: invalid create command.\n");
            return;
        }

        int size;

        if (sscanf(args, "%d", &size) != 1) {
            printf("Error: invalid create command.\n");
            return;
        }

        create_file(filename, size);
    } else if (strcmp(command, "delete") == 0) {
        char filename[FILENAME_LENGTH];

        if (sscanf(args, "%s", filename) != 1) {
            printf("Error: invalid delete command.\n");
            return;
        }

        delete_file(filename);
    } else if (strcmp(command, "print-disk-space") == 0) {
        print_disk_space();
    } else if (strcmp(command, "print-directory") == 0) {
        print_directory();
    } else if (strcmp(command, "print-file") == 0) {
        char filename[FILENAME_LENGTH];

        if (sscanf(args, "%s", filename) != 1) {
            printf("Error: invalid print-file command.\n");
            return;
        }

        print_file(filename);
    } else {
        printf("Error: invalid command.\n");
    }
}

int main() {
    char command[128];
    initialize();

    while (1) {
        printf("Enter command: ");
        fgets(command, 128, stdin);

        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';
        }

        handle_command(command);
    }

    return 0;
}