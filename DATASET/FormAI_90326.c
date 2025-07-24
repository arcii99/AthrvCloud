//FormAI DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 1000

struct file {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
    int size;
};

struct backup_system {
    struct file *files;
    int count;
    int capacity;
};

struct backup_system* create_backup_system() {
    struct backup_system *system = malloc(sizeof(struct backup_system));
    system->count = 0;
    system->capacity = 10;
    system->files = malloc(sizeof(struct file) * system->capacity);
    return system;
}

void add_file(struct backup_system *system, char *name, char *content, int size) {
    if(system->count == system->capacity) {
        system->capacity *= 2;
        system->files = realloc(system->files, sizeof(struct file) * system->capacity);
    }
    struct file f;
    strcpy(f.name, name);
    strcpy(f.content, content);
    f.size = size;
    system->files[system->count++] = f;
}

void delete_file(struct backup_system *system, char *name) {
    int i;
    for(i = 0; i < system->count; i++) {
        if(strcmp(system->files[i].name, name) == 0) {
            system->count--;
            system->files[i] = system->files[system->count];
            return;
        }
    }
}

void list_files(struct backup_system *system) {
    printf("Backup System Contents:\n");
    int i;
    for(i = 0; i < system->count; i++) {
        printf("%s (%d bytes)\n", system->files[i].name, system->files[i].size);
    }
}

int main() {
    struct backup_system *system = create_backup_system();
    
    add_file(system, "file1.txt", "This is file 1", 14);
    add_file(system, "file2.txt", "This is file 2", 14);
    add_file(system, "file3.txt", "This is file 3", 14);
    list_files(system);
    
    delete_file(system, "file2.txt");
    list_files(system);
    
    return 0;
}