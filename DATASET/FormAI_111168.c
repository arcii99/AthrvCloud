//FormAI DATASET v1.0 Category: File system simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char content[100];
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Oops! You already have the maximum number of files.\n");
        return;
    }

    // Check if file with same name already exists
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Oops! A file with the same name already exists.\n");
            return;
        }
    }

    // Create new file
    File f;
    strcpy(f.name, name);
    f.size = size;
    memset(f.content, 'a', size);
    files[num_files++] = f;

    printf("Hooray! The file '%s' has been created with size %d.\n", name, size);
}

void read_file(char *name) {
    // Find file with corresponding name
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("The content of file '%s' is:\n%s\n", name, files[i].content);
            return;
        }
    }

    printf("Oops! No such file exists with the name '%s'.\n", name);
}

int main() {
    printf("Welcome to the Happy C File System!\n");

    // Create some files
    create_file("happy.txt", 20);
    create_file("unicorn.jpg", 50);
    create_file("rainbow.png", 30);
    create_file("smiley.gif", 15);

    // Read the content of the files
    read_file("happy.txt");
    read_file("unicorn.jpg");
    read_file("rainbow.png");
    read_file("smiley.gif");

    printf("Thank you for using the Happy C File System! Have a great day!\n");

    return 0;
}