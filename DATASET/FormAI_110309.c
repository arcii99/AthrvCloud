//FormAI DATASET v1.0 Category: File system simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILE_SYSTEM_SIZE 100

struct file {
    char name[MAX_NAME_LENGTH];
    int size;
};

struct file_system {
    struct file files[MAX_FILE_SYSTEM_SIZE];
    int total_size;
};

void initialize_file_system(struct file_system *f_sys) {
    f_sys->total_size = 0;
}

void create_file(struct file_system *f_sys, char *name, int size) {
    if(f_sys->total_size + size <= MAX_FILE_SYSTEM_SIZE) {
        struct file new_file;
        strncpy(new_file.name, name, MAX_NAME_LENGTH - 1);
        new_file.size = size;
        f_sys->files[f_sys->total_size] = new_file;
        f_sys->total_size += 1;
        printf("%s created successfully!\n", name);
    }
    else {
        printf("Not enough space.\n");
    }
}

void delete_file(struct file_system *f_sys, char *name) {
    int i;
    for(i = 0; i < f_sys->total_size; i++) {
        if(strcmp(f_sys->files[i].name, name) == 0) {
            f_sys->total_size -= 1;
            f_sys->files[i] = f_sys->files[f_sys->total_size];
            printf("%s deleted successfully!\n", name);
            return;
        }
    }
    printf("File not found.\n");
}

void print_file_system(struct file_system *f_sys) {
    printf("Total size of file system: %d\n", f_sys->total_size);
    int i;
    for(i = 0; i < f_sys->total_size; i++) {
        printf("%s: %d bytes\n", f_sys->files[i].name, f_sys->files[i].size);
    }
}

int main() {
    struct file_system my_fs;
    initialize_file_system(&my_fs);

    create_file(&my_fs, "hello.txt", 10);
    create_file(&my_fs, "world.txt", 20);
    create_file(&my_fs, "foo.txt", 15);

    delete_file(&my_fs, "world.txt");

    print_file_system(&my_fs);

    return 0;
}