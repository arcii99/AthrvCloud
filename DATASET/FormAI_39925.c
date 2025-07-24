//FormAI DATASET v1.0 Category: File system simulation ; Style: brave
#include<stdio.h>

// Define a structure for representing a file
struct File {
    char name[50];
    int size;
    char content[100];
};

// Define a structure for representing a directory
struct Directory {
    char name[50];
    struct File files[50];
    int num_files;
};

// Define a structure for representing the file system
struct FileSystem {
    struct Directory root_dir;
};

// Helper function to print the contents of a file
void print_file(struct File f) {
    printf("File Name: %s\n", f.name);
    printf("File Size: %d bytes\n", f.size);
    printf("File Contents: %s\n", f.content);
}

// Helper function to print the contents of a directory
void print_directory(struct Directory dir) {
    printf("Directory Name: %s\n", dir.name);
    printf("Directory Contents:\n");
    for (int i = 0; i < dir.num_files; i++) {
        printf("===== File %d =====\n", i+1);
        print_file(dir.files[i]);
    }
}

// Create a new file
struct File create_file(char name[], char content[]) {
    struct File f;
    strcpy(f.name, name);
    f.size = strlen(content);
    strcpy(f.content, content);
    return f;
}

// Add a file to a directory
void add_file(struct Directory *dir, struct File f) {
    dir->files[dir->num_files] = f;
    dir->num_files++;
}

// Initialize the file system
struct FileSystem init_file_system() {
    struct FileSystem fs;
    struct Directory root_dir = {"root", {}, 0};
    fs.root_dir = root_dir;
    return fs;
}

int main() {
    // Initialize the file system
    struct FileSystem fs = init_file_system();
    
    // Create some files and add them to the root directory
    struct File f1 = create_file("file1.txt", "This is the contents of file 1.");
    add_file(&fs.root_dir, f1);
    struct File f2 = create_file("file2.txt", "This is the contents of file 2.");
    add_file(&fs.root_dir, f2);
    struct File f3 = create_file("file3.txt", "This is the contents of file 3.");
    add_file(&fs.root_dir, f3);
    
    // Print the contents of the root directory
    print_directory(fs.root_dir);
    
    return 0;
}