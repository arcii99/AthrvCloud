//FormAI DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_FILE_SIZE 1000

typedef struct file {
    char name[MAX_FILENAME_LEN];
    char data[MAX_FILE_SIZE];
    int size;
    struct file *next;
} File;

void save_file(File *head, char *filename) {
    FILE *f = fopen(filename, "w");
    if (f) {
        File *cur = head;
        while (cur) {
            fprintf(f, "%s\n%d\n%s", cur->name, cur->size, cur->data);
            cur = cur->next;
        }
        fclose(f);
        printf("Files successfully saved to %s!\n", filename);
    } else {
        printf("Error: Could not open %s for writing.\n", filename);
    }
}

void backup_files(char *dirname, char *backup_filename) {
    printf("Backing up files in %s...\n", dirname);
    // code to recursively read files in directory and add to linked list
    File *head = malloc(sizeof(File));
    head->next = NULL;
    save_file(head, backup_filename);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <directory_name> <backup_filename>\n", argv[0]);
        return 1;
    }
    char *dirname = argv[1];
    char *backup_filename = argv[2];
    backup_files(dirname, backup_filename);
    return 0;
}