//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 1024
#define BLOCK_COUNT 1024
#define FILE_NAME_SIZE 20

struct Block {
    char data[BLOCK_SIZE];
};

struct File {
    char name[FILE_NAME_SIZE];
    int blockIds[10];
    int size;
};

struct DirectoryEntry {
    struct File file;
    struct DirectoryEntry *next;
};

struct FileSystem {
    struct Block blocks[BLOCK_COUNT];
    struct DirectoryEntry *root;
};

void initializeFileSystem(struct FileSystem *);
void displayMenu();
void createFile(struct FileSystem *);
void writeFile(struct FileSystem *);
void readFile(struct FileSystem *);
void deleteFile(struct FileSystem *);
void displayFileSystemStatus(struct FileSystem *);

int main() {
    struct FileSystem fileSystem;
    int choice;

    initializeFileSystem(&fileSystem);

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile(&fileSystem);
                break;

            case 2:
                writeFile(&fileSystem);
                break;

            case 3:
                readFile(&fileSystem);
                break;

            case 4:
                deleteFile(&fileSystem);
                break;

            case 5:
                displayFileSystemStatus(&fileSystem);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, Please enter a valid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void initializeFileSystem(struct FileSystem *fileSystem) {
    int i, j;
    fileSystem->root = NULL;

    for (i = 0; i < BLOCK_COUNT; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            fileSystem->blocks[i].data[j] = '\0';
        }
    }
}

void displayMenu() {
    printf("\n*** File System Simulation ***\n\n");
    printf("1. Create a file\n");
    printf("2. Write to a file\n");
    printf("3. Read from a file\n");
    printf("4. Delete a file\n");
    printf("5. Display file system status\n");
    printf("6. Exit the program\n");
    printf("\nEnter your choice: ");
}

void createFile(struct FileSystem *fileSystem) {
    char fileName[FILE_NAME_SIZE];
    int i;
    struct DirectoryEntry *currentNode;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    currentNode = fileSystem->root;

    while (currentNode != NULL) {
        if (strcmp(currentNode->file.name, fileName) == 0) {
            printf("A file with the same name already exists.\n");
            return;
        }

        currentNode = currentNode->next;
    }

    struct DirectoryEntry *newEntry = (struct DirectoryEntry *) malloc(sizeof(struct DirectoryEntry));
    struct File newFile;

    strcpy(newFile.name, fileName);
    newFile.size = 0;

    for (i = 0; i < 10; i++) {
        newFile.blockIds[i] = -1;
    }

    newEntry->file = newFile;
    newEntry->next = NULL;

    if (fileSystem->root == NULL) {
        fileSystem->root = newEntry;
    } else {
        currentNode = fileSystem->root;

        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        currentNode->next = newEntry;
    }

    printf("File created successfully.\n");
}

void writeFile(struct FileSystem *fileSystem) {
    char fileName[FILE_NAME_SIZE];
    int i, j, blockId, blockCount, fileSize;
    struct DirectoryEntry *currentNode;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    currentNode = fileSystem->root;

    while (currentNode != NULL) {
        if (strcmp(currentNode->file.name, fileName) == 0) {
            printf("Enter the data to be written to the file (Enter a dot(.) to terminate):\n");

            FILE *fp;
            fp = fopen("temp.txt", "w");

            char c;
            scanf("%c", &c);

            while (1) {
                scanf("%c", &c);
                fputc(c, fp);

                if (c == '.') {
                    break;
                }
            }

            fileSize = ftell(fp);

            if (fileSize > (BLOCK_SIZE * 10)) {
                printf("File size exceeded the maximum limit.\n");
                fclose(fp);
                return;
            }

            blockCount = fileSize / BLOCK_SIZE;

            if (fileSize % BLOCK_SIZE != 0) {
                blockCount++;
            }

            int *blockIds = (int *) malloc(blockCount * sizeof(int));

            for (i = 0; i < blockCount; i++) {
                blockIds[i] = -1;
            }

            i = 0;

            while (i < blockCount) {
                blockId = rand() % BLOCK_COUNT;

                if (fileSystem->blocks[blockId].data[0] == '\0') {
                    blockIds[i] = blockId;

                    for (j = 0; j < BLOCK_SIZE; j++) {
                        c = fgetc(fp);

                        if (c == EOF) {
                            fileSystem->blocks[blockId].data[j] = '\0';
                            break;
                        }

                        fileSystem->blocks[blockId].data[j] = c;
                    }

                    i++;
                }
            }

            fclose(fp);

            currentNode->file.size = fileSize;

            for (i = 0; i < blockCount; i++) {
                currentNode->file.blockIds[i] = blockIds[i];
            }

            printf("Data written to file successfully.\n");

            return;
        }

        currentNode = currentNode->next;
    }

    printf("File not found.\n");
}

void readFile(struct FileSystem *fileSystem) {
    char fileName[FILE_NAME_SIZE];
    int i, j, blockId, fileSize;
    struct DirectoryEntry *currentNode;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    currentNode = fileSystem->root;

    while (currentNode != NULL) {
        if (strcmp(currentNode->file.name, fileName) == 0) {
            FILE *fp;
            fp = fopen("output.txt", "w");

            fileSize = currentNode->file.size;

            for (i = 0; i < fileSize; i++) {
                blockId = currentNode->file.blockIds[i / BLOCK_SIZE];

                if (blockId == -1) {
                    break;
                }

                fputc(fileSystem->blocks[blockId].data[i % BLOCK_SIZE], fp);
            }

            fclose(fp);

            printf("Data read from file successfully.\n");

            return;
        }

        currentNode = currentNode->next;
    }

    printf("File not found.\n");
}

void deleteFile(struct FileSystem *fileSystem) {
    char fileName[FILE_NAME_SIZE];
    int i, blockId;
    struct DirectoryEntry *currentNode, *previousNode;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    currentNode = fileSystem->root;
    previousNode = NULL;

    while (currentNode != NULL) {
        if (strcmp(currentNode->file.name, fileName) == 0) {
            if (currentNode == fileSystem->root) {
                fileSystem->root = currentNode->next;
            } else {
                previousNode->next = currentNode->next;
            }

            for (i = 0; i < 10; i++) {
                blockId = currentNode->file.blockIds[i];

                if (blockId != -1) {
                    fileSystem->blocks[blockId].data[0] = '\0';
                }
            }

            free(currentNode);

            printf("File deleted successfully.\n");

            return;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("File not found.\n");
}

void displayFileSystemStatus(struct FileSystem *fileSystem) {
    int i, j, blockId, fileSize;
    struct DirectoryEntry *currentNode;

    printf("\n*** File System Status ***\n\n");

    currentNode = fileSystem->root;

    if (currentNode == NULL) {
        printf("The file system is empty.\n");
        return;
    }

    while (currentNode != NULL) {
        printf("Name: %s\n", currentNode->file.name);
        fileSize = currentNode->file.size;

        printf("Size: %d\n", fileSize);

        printf("Block IDs:");

        for (i = 0; i < fileSize / BLOCK_SIZE; i++) {
            printf(" %d", currentNode->file.blockIds[i]);
        }

        if (fileSize % BLOCK_SIZE != 0) {
            printf(" %d", currentNode->file.blockIds[i]);
        }

        printf("\n");

        for (i = 0; i < fileSize; i++) {
            blockId = currentNode->file.blockIds[i / BLOCK_SIZE];

            if (blockId == -1) {
                break;
            }

            printf("%c", fileSystem->blocks[blockId].data[i % BLOCK_SIZE]);
        }

        printf("\n\n");

        currentNode = currentNode->next;
    }
}