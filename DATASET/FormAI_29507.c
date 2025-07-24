//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 1024

struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
};

struct file_system {
    int num_files;
    struct file files[10];
};

int find_file(struct file_system *fs, char *name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file(struct file_system *fs, char *name, char *data) {
    if (fs->num_files >= 10) {
        printf("Error: filesystem full\n");
        return;
    }
    if (find_file(fs, name) != -1) {
        printf("Error: file already exists\n");
        return;
    }
    struct file new_file;
    strncpy(new_file.name, name, MAX_FILENAME_LENGTH);
    new_file.size = strlen(data);
    strncpy(new_file.data, data, MAX_FILE_SIZE);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
}

void read_file(struct file_system *fs, char *name) {
    int index = find_file(fs, name);
    if (index == -1) {
        printf("Error: file not found\n");
        return;
    }
    printf("%s\n", fs->files[index].data);
}

void delete_file(struct file_system *fs, char *name) {
    int index = find_file(fs, name);
    if (index == -1) {
        printf("Error: file not found\n");
        return;
    }
    fs->num_files--;
    for (int i = index; i < fs->num_files; i++) {
        fs->files[i] = fs->files[i + 1];
    }
}

int main() {
    struct file_system fs;
    fs.num_files = 0;
    while (1) {
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[MAX_FILENAME_LENGTH];
            char data[MAX_FILE_SIZE];
            scanf("%s", name);
            scanf("%s", data);
            create_file(&fs, name, data);
        } else if (strcmp(command, "read") == 0) {
            char name[MAX_FILENAME_LENGTH];
            scanf("%s", name);
            read_file(&fs, name);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILENAME_LENGTH];
            scanf("%s", name);
            delete_file(&fs, name);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}