//FormAI DATASET v1.0 Category: File system simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_FILE_COUNT 100
#define MAX_DIR_COUNT 50

typedef struct file {
    char filename[MAX_FILENAME_LEN];
    int size_in_bytes;
} File;

typedef struct directory {
    char dirname[MAX_FILENAME_LEN];
    int file_count;
    int sub_dir_count;
    File files[MAX_FILE_COUNT];
    struct directory* sub_dirs[MAX_DIR_COUNT];
} Directory;

Directory root_dir;

void create_file(char* filename, int size) {
    File new_file = { 0 };
    strcpy(new_file.filename, filename);
    new_file.size_in_bytes = size;

    int i;
    for (i = 0; i < root_dir.file_count; i++) {
        if (strcmp(root_dir.files[i].filename, filename) == 0) {
            printf("Error: File already exists\n");
            return;
        }
    }

    if (root_dir.file_count >= MAX_FILE_COUNT) {
        printf("Error: No more space for files\n");
        return;
    }

    root_dir.files[root_dir.file_count++] = new_file;

    printf("File created: %s\n", filename);
}

void delete_file(char* filename) {
    int i, j;
    for (i = 0; i < root_dir.file_count; i++) {
        if (strcmp(root_dir.files[i].filename, filename) == 0) {
            printf("File deleted: %s\n", filename);

            for (j = i; j < root_dir.file_count - 1; j++) {
                root_dir.files[j] = root_dir.files[j + 1];
            }

            root_dir.file_count--;
            return;
        }
    }

    printf("Error: File not found\n");
}

void create_dir(char* dirname) {
    Directory new_dir = { 0 };
    strcpy(new_dir.dirname, dirname);

    int i;
    for (i = 0; i < root_dir.sub_dir_count; i++) {
        if (strcmp(root_dir.sub_dirs[i]->dirname, dirname) == 0) {
            printf("Error: Directory already exists\n");
            return;
        }
    }

    if (root_dir.sub_dir_count >= MAX_DIR_COUNT) {
        printf("Error: No more space for directories\n");
        return;
    }

    root_dir.sub_dirs[root_dir.sub_dir_count++] = (Directory*)malloc(sizeof(Directory));
    *(root_dir.sub_dirs[root_dir.sub_dir_count - 1]) = new_dir;

    printf("Directory created: %s\n", dirname);
}

void delete_dir(char* dirname) {
    int i, j;
    for (i = 0; i < root_dir.sub_dir_count; i++) {
        if (strcmp(root_dir.sub_dirs[i]->dirname, dirname) == 0) {
            printf("Directory deleted: %s\n", dirname);

            for (j = i; j < root_dir.sub_dir_count - 1; j++) {
                root_dir.sub_dirs[j] = root_dir.sub_dirs[j + 1];
            }

            root_dir.sub_dir_count--;
            free(root_dir.sub_dirs[root_dir.sub_dir_count]);
            return;
        }
    }

    printf("Error: Directory not found\n");
}

void list_files() {
    printf("%d file(s):\n", root_dir.file_count);

    int i;
    for (i = 0; i < root_dir.file_count; i++) {
        printf("%s\t%d bytes\n", root_dir.files[i].filename, root_dir.files[i].size_in_bytes);
    }
}

void list_directories() {
    printf("%d directory(ies):\n", root_dir.sub_dir_count);

    int i;
    for (i = 0; i < root_dir.sub_dir_count; i++) {
        printf("%s\n", root_dir.sub_dirs[i]->dirname);
    }
}

void help() {
    printf("Commands:\n");
    printf("  create <filename> <size_in_bytes>\n");
    printf("  delete <filename>\n");
    printf("  mkdir <dirname>\n");
    printf("  rmdir <dirname>\n");
    printf("  ls\n");
    printf("  lsd\n");
    printf("  help\n");
    printf("  exit\n");
}

int main() {
    memset(&root_dir, 0, sizeof(Directory));
    strcpy(root_dir.dirname, "/");

    printf("File system simulator\n");
    printf("---------------------\n");
    help();

    char cmd[100] = { 0 };
    while (1) {
        printf("> ");
        fgets(cmd, sizeof(cmd), stdin);
        if (strlen(cmd) > 1 && cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = 0;
        }

        char* tok = strtok(cmd, " ");
        if (strcmp(tok, "create") == 0) {
            char* filename = strtok(NULL, " ");
            char* size_str = strtok(NULL, " ");
            if (filename == NULL || size_str == NULL) {
                printf("Error: Invalid arguments\n");
            }
            else {
                int size = atoi(size_str);
                create_file(filename, size);
            }
        }
        else if (strcmp(tok, "delete") == 0) {
            char* filename = strtok(NULL, " ");
            if (filename == NULL) {
                printf("Error: Invalid arguments\n");
            }
            else {
                delete_file(filename);
            }
        }
        else if (strcmp(tok, "mkdir") == 0) {
            char* dirname = strtok(NULL, " ");
            if (dirname == NULL) {
                printf("Error: Invalid arguments\n");
            }
            else {
                create_dir(dirname);
            }
        }
        else if (strcmp(tok, "rmdir") == 0) {
            char* dirname = strtok(NULL, " ");
            if (dirname == NULL) {
                printf("Error: Invalid arguments\n");
            }
            else {
                delete_dir(dirname);
            }
        }
        else if (strcmp(tok, "ls") == 0) {
            list_files();
        }
        else if (strcmp(tok, "lsd") == 0) {
            list_directories();
        }
        else if (strcmp(tok, "help") == 0) {
            help();
        }
        else if (strcmp(tok, "exit") == 0) {
            break;
        }
        else {
            printf("Error: Invalid command\n");
        }
    }

    return 0;
}