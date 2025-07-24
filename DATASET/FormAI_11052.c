//FormAI DATASET v1.0 Category: File system simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000       // Maximum file size
#define MAX_FILENAME_LENGTH 100  // Maximum filename length
#define MAX_FILES 10             // Maximum number of files that can be stored in the system
#define MAX_COMMAND_LENGTH 100   // Maximum length of user command

typedef enum {
    TYPE_FILE,
    TYPE_FOLDER,
    TYPE_LINK
} FileType;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_SIZE];
    FileType type;
} File;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    File files[MAX_FILES];
    int count_files;
} Folder;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char target[MAX_FILENAME_LENGTH];
    FileType type;
} Link;

typedef struct {
    Folder root;
    Link links[MAX_FILES];
    int count_links;
} FileSystem;

FileSystem fs;

void initializeFileSystem() {
    strcpy(fs.root.name, "root");
    fs.root.count_files = 0;
    fs.count_links = 0;
}

void createFile(char* filename) {
    File file;
    file.type = TYPE_FILE;
    strcpy(file.name, filename);
    strcpy(file.content, "");
    fs.root.files[fs.root.count_files++] = file;
    printf("File %s created successfully!\n", filename);
}

void createFolder(char* foldername) {
    Folder folder;
    folder.count_files = 0;
    strcpy(folder.name, foldername);
    fs.root.files[fs.root.count_files++] = (File){foldername, "", TYPE_FOLDER};
    printf("Folder %s created successfully!\n", foldername);
}

void createLink(char* linkname, char* targetname) {
    int i, found = 0;
    for (i = 0; i < fs.root.count_files; i++) {
        if (fs.root.files[i].type == TYPE_FOLDER && strcmp(fs.root.files[i].name, targetname) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        Link link;
        link.type = TYPE_LINK;
        strcpy(link.name, linkname);
        strcpy(link.target, targetname);
        fs.links[fs.count_links++] = link;
        printf("Link %s created successfully!\n", linkname);
    } else {
        printf("Error: Folder %s does not exist!\n", targetname);
    }
}

File* getFile(char* filename) {
    int i;
    for (i = 0; i < fs.root.count_files; i++) {
        if (fs.root.files[i].type == TYPE_FILE && strcmp(fs.root.files[i].name, filename) == 0) {
            return &fs.root.files[i];
        }
    }
    return NULL;
}

Folder* getFolder(char* foldername) {
    int i;
    for (i = 0; i < fs.root.count_files; i++) {
        if (fs.root.files[i].type == TYPE_FOLDER && strcmp(fs.root.files[i].name, foldername) == 0) {
            return (Folder*) &fs.root.files[i];
        }
    }
    return NULL;
}

void deleteFile(char* filename) {
    int i;
    for (i = 0; i < fs.root.count_files; i++) {
        if (fs.root.files[i].type == TYPE_FILE && strcmp(fs.root.files[i].name, filename) == 0) {
            int j;
            for (j = i; j < fs.root.count_files - 1; j++) {
                fs.root.files[j] = fs.root.files[j + 1];
            }
            fs.root.count_files--;
            printf("File %s deleted successfully!\n", filename);
            return;
        }
    }
    printf("Error: File %s does not exist!\n", filename);
}

void deleteFolder(char* foldername) {
    int i;
    for (i = 0; i < fs.root.count_files; i++) {
        if (fs.root.files[i].type == TYPE_FOLDER && strcmp(fs.root.files[i].name, foldername) == 0) {
            int j;
            for (j = i; j < fs.root.count_files - 1; j++) {
                fs.root.files[j] = fs.root.files[j + 1];
            }
            fs.root.count_files--;
            printf("Folder %s deleted successfully!\n", foldername);
            return;
        }
    }
    printf("Error: Folder %s does not exist!\n", foldername);
}

void displayMenu() {
    printf("\n\n\n");
    printf("Welcome to the C File System Simulation!\n");
    printf("==================================\n");
    printf("[1] List Files and Folders\n");
    printf("[2] Create File\n");
    printf("[3] Create Folder\n");
    printf("[4] Create Link\n");
    printf("[5] Delete File\n");
    printf("[6] Delete Folder\n");
    printf("[7] Exit\n");
    printf("==================================\n");
    printf("Enter command: ");
}

int main() {
    initializeFileSystem();
    while (1) {
        char command[MAX_COMMAND_LENGTH];
        displayMenu();
        scanf("%s", command);
        if (strcmp(command, "1") == 0) {
            int i;
            printf("Folders:\n");
            for (i = 0; i < fs.root.count_files; i++) {
                File file = fs.root.files[i];
                if (file.type == TYPE_FOLDER) {
                    printf("%s\n", file.name);
                }
            }
            printf("Files:\n");
            for (i = 0; i < fs.root.count_files; i++) {
                File file = fs.root.files[i];
                if (file.type == TYPE_FILE) {
                    printf("%s\n", file.name);
                }
            }
            printf("Links:\n");
            for (i = 0; i < fs.count_links; i++) {
                Link link = fs.links[i];
                printf("%s (-> %s)\n", link.name, link.target);
            }
        } else if (strcmp(command, "2") == 0) {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            createFile(filename);
        } else if (strcmp(command, "3") == 0) {
            char foldername[MAX_FILENAME_LENGTH];
            printf("Enter foldername: ");
            scanf("%s", foldername);
            createFolder(foldername);
        } else if (strcmp(command, "4") == 0) {
            char linkname[MAX_FILENAME_LENGTH], targetname[MAX_FILENAME_LENGTH];
            printf("Enter linkname: ");
            scanf("%s", linkname);
            printf("Enter targetname: ");
            scanf("%s", targetname);
            createLink(linkname, targetname);
        } else if (strcmp(command, "5") == 0) {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter filename: ");
            scanf("%s", filename);
            deleteFile(filename);
        } else if (strcmp(command, "6") == 0) {
            char foldername[MAX_FILENAME_LENGTH];
            printf("Enter foldername: ");
            scanf("%s", foldername);
            deleteFolder(foldername);
        } else if (strcmp(command, "7") == 0) {
            printf("Thank you for using the C File System Simulation!\n");
            return 0;
        }
    }
}