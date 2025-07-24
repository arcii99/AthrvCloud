//FormAI DATASET v1.0 Category: File system simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int size;
    int is_directory;
    int parent_index;
    int child_index;
} File;

typedef struct {
    File* files;
    int num_files;
    int max_files;
} FileSystem;

void introduce(FileSystem fs) {
    printf("This is the C File System, where all your files live.\n");
    printf("Meet our current residents:\n");
    for (int i = 0; i < fs.num_files; i++) {
        printf("%s\n", fs.files[i].name);
    }
    printf("What would you like to do?\n");
}

void list_files(FileSystem fs, int index) {
    printf("In directory: %s\n", fs.files[index].name);
    printf("Contents:\n");
    for (int i = 0; i < fs.num_files; i++) {
        if (fs.files[i].parent_index == index) {
            printf("%s", fs.files[i].is_directory ? "[DIR] " : "");
            printf("%s\n", fs.files[i].name);
        }
    }
}

void create_file(FileSystem* fs, char* name, int size, int is_directory, int parent_index) {
    if (fs->num_files >= fs->max_files) {
        printf("Sorry, no more files can be created.\n");
        return;
    }
    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.is_directory = is_directory;
    new_file.parent_index = parent_index;
    new_file.child_index = -1;
    fs->files[fs->num_files] = new_file;
    if (parent_index != -1) {
        fs->files[parent_index].child_index = fs->num_files;
    }
    fs->num_files++;
    printf("%s was successfully created.\n", name);
}

void delete_file(FileSystem* fs, int index) {
    if (fs->files[index].child_index != -1) {
        printf("Sorry, this directory is not empty.\n");
        return;
    }
    for (int i = index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;
    printf("%s was successfully deleted.\n", fs->files[index].name);
}

void move_file(FileSystem* fs, int file_index, int new_parent_index) {
    int old_parent_index = fs->files[file_index].parent_index;
    if (old_parent_index == new_parent_index) {
        printf("File is already in that directory.\n");
        return;
    }
    fs->files[file_index].parent_index = new_parent_index;
    fs->files[file_index].child_index = -1;
    if (new_parent_index != -1) {
        fs->files[file_index].child_index = fs->files[new_parent_index].child_index;
        fs->files[new_parent_index].child_index = file_index;
    }
    if (old_parent_index != -1 && fs->files[old_parent_index].child_index == file_index) {
        fs->files[old_parent_index].child_index = -1;
    }
    printf("%s was successfully moved.\n", fs->files[file_index].name);
}

int main() {
    FileSystem fs;
    fs.files = malloc(50 * sizeof(File));
    fs.num_files = 0;
    fs.max_files = 50;

    create_file(&fs, "root", 0, 1, -1); // Create root directory

    introduce(fs);

    int current_directory = 0; // start in root directory

    while (1) {
        printf("> ");
        char input[100];
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character from input
        if (strcmp(input, "ls") == 0) {
            list_files(fs, current_directory);
        } else if (strncmp(input, "mkdir ", 6) == 0) {
            char* folder_name = input + 6;
            create_file(&fs, folder_name, 0, 1, current_directory);
        } else if (strncmp(input, "touch ", 6) == 0) {
            char* file_name = input + 6;
            create_file(&fs, file_name, 0, 0, current_directory);
        } else if (strncmp(input, "delete ", 7) == 0) {
            char* file_name = input + 7;
            int found_file = -1;
            for (int i = 0; i < fs.num_files; i++) {
                if (strcmp(fs.files[i].name, file_name) == 0 && fs.files[i].parent_index == current_directory) {
                    found_file = i;
                    break;
                }
            }
            if (found_file == -1) {
                printf("File not found.\n");
            } else {
                delete_file(&fs, found_file);
            }
        } else if (strncmp(input, "cd ", 3) == 0) {
            char* folder_name = input + 3;
            int found_folder = -1;
            for (int i = 0; i < fs.num_files; i++) {
                if (strcmp(fs.files[i].name, folder_name) == 0 && fs.files[i].parent_index == current_directory && fs.files[i].is_directory) {
                    found_folder = i;
                    break;
                }
            }
            if (found_folder == -1) {
                printf("Directory not found.\n");
            } else {
                current_directory = found_folder;
            }
        } else if (strncmp(input, "mv ", 3) == 0) {
            char* file_name = input + 3;
            int found_file = -1;
            for (int i = 0; i < fs.num_files; i++) {
                if (strcmp(fs.files[i].name, file_name) == 0 && fs.files[i].parent_index == current_directory) {
                    found_file = i;
                    break;
                }
            }
            if (found_file == -1) {
                printf("File not found.\n");
            } else {
                printf("Enter destination directory: ");
                char destination[50];
                fgets(destination, 50, stdin);
                destination[strcspn(destination, "\n")] = 0;
                int found_destination = -1;
                for (int i = 0; i < fs.num_files; i++) {
                    if (strcmp(fs.files[i].name, destination) == 0 && fs.files[i].parent_index == current_directory && fs.files[i].is_directory) {
                        found_destination = i;
                        break;
                    }
                }
                if (found_destination == -1) {
                    printf("Destination directory not found.\n");
                } else {
                    move_file(&fs, found_file, found_destination);
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    free(fs.files);
    return 0;
}