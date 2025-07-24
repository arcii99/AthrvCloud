//FormAI DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INODE 100
#define FS_SIZE 5000

typedef struct {
    int id;
    char name[100];
    int parent_id;
    int child_id;
    int size;
} Inode;

typedef struct {
    char data[FS_SIZE];
    int used_size;
} FS;

Inode inodes[MAX_INODE];
FS file_system;

int current_dir_id;

void init_inodes() {
    for (int i = 0; i < MAX_INODE; i++) {
        inodes[i].id = -1;
    }
}

int get_next_inode_id() {
    for (int i = 0; i < MAX_INODE; i++) {
        if (inodes[i].id == -1) {
            return i;
        }
    }

    return -1;
}

void create_file(char* name, int parent_id, int size) {
    int id = get_next_inode_id();

    strcpy(inodes[id].name, name);
    inodes[id].id = id;
    inodes[id].parent_id = parent_id;
    inodes[id].size = size;

    if (inodes[parent_id].child_id == -1) {
        inodes[parent_id].child_id = id;
    } else {
        int child_id = inodes[parent_id].child_id;

        while (inodes[child_id].child_id != -1) {
            child_id = inodes[child_id].child_id;
        }

        inodes[child_id].child_id = id;
    }
}

void init_fs() {
    for (int i = 0; i < FS_SIZE; i++) {
        file_system.data[i] = '\0';
    }

    file_system.used_size = 0;
    current_dir_id = 0;
    create_file("usr", current_dir_id, 0);
    create_file("bin", current_dir_id, 0);
}

void print_files(int parent_id) {
    if (inodes[parent_id].child_id != -1) {
        int child_id = inodes[parent_id].child_id;

        printf("\n");

        while (child_id != -1) {
            printf("%s\n", inodes[child_id].name);

            child_id = inodes[child_id].child_id;
        }
    } else {
        printf("No files found.\n");
    }
}

void cd(char* name) {
    if (strcmp(name, "..") == 0) {
        int parent_id = inodes[current_dir_id].parent_id;

        if (parent_id != -1) {
            current_dir_id = parent_id;
        }
    } else {
        int child_id = inodes[current_dir_id].child_id;

        while (child_id != -1) {
            if (strcmp(inodes[child_id].name, name) == 0) {
                current_dir_id = child_id;
                return;
            }

            child_id = inodes[child_id].child_id;
        }

        printf("Directory not found.\n");
    }
}

void append_to_fs(char* data, int size) {
    int free_space = FS_SIZE - file_system.used_size;

    if (free_space < size) {
        printf("Not enough space.\n");
        return;
    }

    strcat(file_system.data, data);
    file_system.used_size += size;
}

void write_file_to_fs(int id, char* data) {
    int size = strlen(data);

    if (size > inodes[id].size) {
        printf("Not enough space.\n");
        return;
    }

    char buffer[FS_SIZE];
    sprintf(buffer, "[%s|%d|%d-%d]", inodes[id].name, size, file_system.used_size, file_system.used_size + size - 1);
    append_to_fs(buffer, strlen(buffer));
    append_to_fs(data, size);
}

void write_file(char* name, char* data) {
    int child_id = inodes[current_dir_id].child_id;

    while (child_id != -1) {
        if (strcmp(inodes[child_id].name, name) == 0) {
            write_file_to_fs(child_id, data);
            return;
        }

        child_id = inodes[child_id].child_id;
    }

    printf("File not found.\n");
}

void print_file_contents(int id) {
    int start_index = -1;
    int end_index = -1;

    char buffer[strlen(file_system.data)];

    sprintf(buffer, "[%s|%d|%d-%d]", inodes[id].name, inodes[id].size, 0, 0);
    char* index = strstr(file_system.data, buffer);

    if (index) {
        start_index = index - file_system.data + strlen(buffer);
        end_index = start_index + inodes[id].size - 1;
        printf("%.*s\n", inodes[id].size, file_system.data + start_index);
    }
}

int main() {
    init_inodes();
    init_fs();

    create_file("text_files", current_dir_id, 0);
    create_file("assignments", current_dir_id, 0);

    printf("Current directory: /\n");

    char command[100];
    char arg1[100];
    char arg2[100];

    while (1) {
        printf("> ");

        scanf("%s", command);

        if (strcmp(command, "ls") == 0) {
            print_files(current_dir_id);
        } else if (strcmp(command, "cd") == 0) {
            scanf("%s", arg1);
            cd(arg1);

            printf("Current directory: %s\n", inodes[current_dir_id].name);
        } else if (strcmp(command, "touch") == 0) {
            scanf("%s", arg1);
            create_file(arg1, current_dir_id, 0);
        } else if (strcmp(command, "write") == 0) {
            scanf("%s%s", arg1, arg2);
            write_file(arg1, arg2);
        } else if (strcmp(command, "cat") == 0) {
            scanf("%s", arg1);

            int child_id = inodes[current_dir_id].child_id;

            while (child_id != -1) {
                if (strcmp(inodes[child_id].name, arg1) == 0) {
                    print_file_contents(child_id);
                    break;
                }

                child_id = inodes[child_id].child_id;
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}