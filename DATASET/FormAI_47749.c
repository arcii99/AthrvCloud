//FormAI DATASET v1.0 Category: File system simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_SIZE 20
#define MAX_FILE_SIZE 1024

struct file {
    char name[MAX_FILE_NAME_SIZE];
    char data[MAX_FILE_SIZE];
    int size;
};

struct directory {
    char name[MAX_FILE_NAME_SIZE];
    int file_count;
    struct file* files;
};

struct file_system {
    int directory_count;
    struct directory* directories;
};

int main() {
    int choice;
    struct file_system fs;
    fs.directory_count = 0;
    fs.directories = NULL;

    while(1) {
        printf("1. Create a directory \n");
        printf("2. Add file to directory \n");
        printf("3. Delete file from directory \n");
        printf("4. Display all files in directory \n");
        printf("5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                create_directory(&fs);
                break;
            case 2: 
                add_file(&fs);
                break;
            case 3: 
                delete_file(&fs);
                break;
            case 4: 
                display_directory(&fs);
                break;
            case 5: 
                exit(0);
            default:
                printf("Invalid choice \n");
       }
    }

    return 0;
}

void create_directory(struct file_system* fs) {
    char dir_name[MAX_FILE_NAME_SIZE];
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    // Check if directory already exists
    for(int i=0; i<fs->directory_count; i++) {
        if(strcmp(fs->directories[i].name, dir_name) == 0) {
            printf("Directory already exists! \n");
            return;
        }
    }
    
    // Create a new directory
    struct directory new_dir;
    strcpy(new_dir.name, dir_name);
    new_dir.file_count = 0;
    new_dir.files = NULL;
   
    fs->directory_count++;
    fs->directories = realloc(fs->directories, sizeof(struct directory) * fs->directory_count);
    fs->directories[fs->directory_count - 1] = new_dir;

    printf("Directory created successfully! \n");
}

void add_file(struct file_system* fs) {
    if(fs->directory_count == 0) {
        printf("No directories created yet! \n");
        return;
    }

    char file_name[MAX_FILE_NAME_SIZE], file_data[MAX_FILE_SIZE], dir_name[MAX_FILE_NAME_SIZE];
    int file_size;
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter file data: ");
    scanf("%s", file_data);
    file_size = strlen(file_data);
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    // Find the directory
    int dir_index = -1;
    for(int i=0; i<fs->directory_count; i++) {
        if(strcmp(fs->directories[i].name, dir_name) == 0) {
            dir_index = i;
            break;
        }
    }

    if(dir_index == -1) {
        printf("Directory not found! \n");
        return;
    }

    // Check if file already exists
    for(int i=0; i<fs->directories[dir_index].file_count; i++) {
        if(strcmp(fs->directories[dir_index].files[i].name, file_name) == 0) {
            printf("File already exists! \n");
            return;
        }
    }

    // Create a new file
    struct file new_file;
    strcpy(new_file.name, file_name);
    strcpy(new_file.data, file_data);
    new_file.size = file_size;

    fs->directories[dir_index].file_count++;
    fs->directories[dir_index].files = realloc(fs->directories[dir_index].files, sizeof(struct file) * fs->directories[dir_index].file_count);
    fs->directories[dir_index].files[fs->directories[dir_index].file_count - 1] = new_file;

    printf("File added successfully! \n");
}

void delete_file(struct file_system* fs) {
    if(fs->directory_count == 0) {
        printf("No directories created yet! \n");
        return;
    }

    char file_name[MAX_FILE_NAME_SIZE], dir_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    // Find the directory
    int dir_index = -1;
    for(int i=0; i<fs->directory_count; i++) {
        if(strcmp(fs->directories[i].name, dir_name) == 0) {
            dir_index = i;
            break;
        }
    }

    if(dir_index == -1) {
        printf("Directory not found! \n");
        return;
    }

    // Find the file
    int file_index = -1;
    for(int i=0; i<fs->directories[dir_index].file_count; i++) {
        if(strcmp(fs->directories[dir_index].files[i].name, file_name) == 0) {
            file_index = i;
            break;
        }
    }

    if(file_index == -1) {
        printf("File not found! \n");
        return;
    }

    // Delete the file
    for(int i=file_index; i<fs->directories[dir_index].file_count-1; i++) {
        fs->directories[dir_index].files[i] = fs->directories[dir_index].files[i+1];
    }
    fs->directories[dir_index].file_count--;
    fs->directories[dir_index].files = realloc(fs->directories[dir_index].files, sizeof(struct file) * fs->directories[dir_index].file_count);

    printf("File deleted successfully! \n");
}

void display_directory(struct file_system* fs) {
    if(fs->directory_count == 0) {
        printf("No directories created yet! \n");
        return;
    }

    char dir_name[MAX_FILE_NAME_SIZE];
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    // Find the directory
    int dir_index = -1;
    for(int i=0; i<fs->directory_count; i++) {
        if(strcmp(fs->directories[i].name, dir_name) == 0) {
            dir_index = i;
            break;
        }
    }

    if(dir_index == -1) {
        printf("Directory not found! \n");
        return;
    }

    printf("Directory Name: %s \n", fs->directories[dir_index].name);
    printf("Number of files: %d \n", fs->directories[dir_index].file_count);
    printf("Files: \n");

    for(int i=0; i<fs->directories[dir_index].file_count; i++) {
        printf("%s - %d bytes \n", fs->directories[dir_index].files[i].name, fs->directories[dir_index].files[i].size);
    }
}