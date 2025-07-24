//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

#define MAX_FILES 100
#define FILENAME_SIZE 20

typedef struct {
    int nodes[10];
    int size;
    char filename[FILENAME_SIZE];
} File;

File files[MAX_FILES];
int totalFiles = 0;

int disk[1000]; // total blocks in disk
int freeBlocks = 1000;

void initializeDisk() {
    for(int i=0; i<1000; i++) {
        disk[i] = -1; // initialize blocks with null values
    }
}

int allocateBlocks(int numBlocks) {
    if(freeBlocks < numBlocks) {
        printf("Error: Not enough space in the disk!\n");
        return -1;
    }

    int allocatedBlock = -1;
    int blocksFound = 0;
    for(int i=0; i<1000; i++) {
        if(disk[i] == -1) {
            if(allocatedBlock == -1) {
                allocatedBlock = i;
            }
            blocksFound++;
            if(blocksFound == numBlocks) {
                break;
            }
        }
    }

    // mark allocated blocks as used
    for(int i=allocatedBlock; i<allocatedBlock+numBlocks; i++) {
        disk[i] = 0;
    }

    freeBlocks -= numBlocks;
    return allocatedBlock;
}

void deallocateBlocks(int startBlock, int numBlocks) {
    for(int i=startBlock; i<startBlock+numBlocks; i++) {
        disk[i] = -1;
    }

    freeBlocks += numBlocks;
}

void writeToFile(int fileIndex, char data[]) {
    int startBlock = allocateBlocks(files[fileIndex].size);
    if(startBlock == -1) {
        return;
    }

    for(int i=0; i<files[fileIndex].size; i++) {
        disk[startBlock + i] = data[i];
    }

    files[fileIndex].nodes[0] = startBlock;
    printf("Successfully written to file %s!\n", files[fileIndex].filename);
}

void readFile(int fileIndex) {
    printf("Reading file %s:\n", files[fileIndex].filename);

    int startBlock = files[fileIndex].nodes[0];
    for(int i=startBlock; i<startBlock+files[fileIndex].size; i++) {
        printf("%c", disk[i]);
    }

    printf("\n");
}

void deleteFile(int fileIndex) {
    deallocateBlocks(files[fileIndex].nodes[0], files[fileIndex].size);
    for(int i=fileIndex; i<totalFiles; i++) {
        files[i] = files[i+1];
    }
    totalFiles--;
    printf("File %s deleted successfully!\n", files[fileIndex].filename);
}

void displayFiles() {
    printf("Total files in the system: %d\n", totalFiles);
    if(totalFiles == 0) {
        printf("No files to display!\n");
        return;
    }

    printf("File Name\tSize\n");
    for(int i=0; i<totalFiles; i++) {
        printf("%s\t\t%d Bytes\n", files[i].filename, files[i].size);
    }

    printf("\n");
}

int main() {
    initializeDisk();
    printf("Welcome to the Cyberpunk File System Simulation!\n\n");

    while(1) {
        printf("Enter a command (a: add file, w: write to file, r: read file, d: delete file, l: list files, q: quit): ");
        char ch;
        scanf(" %c", &ch);

        if(ch == 'q') {
            break;
        }

        switch(ch) {
            case 'a': {
                File newFile;
                printf("Enter file name: ");
                scanf("%s", newFile.filename);
                printf("Enter file size (in blocks): ");
                scanf("%d", &newFile.size);
                newFile.nodes[0] = allocateBlocks(newFile.size);

                if(newFile.nodes[0] == -1) {
                    break;
                }

                files[totalFiles++] = newFile;
                printf("File %s created successfully!\n", newFile.filename);
                break;
            }
            case 'w': {
                char filename[20];
                printf("Enter file name: ");
                scanf("%s", filename);

                int fileIndex = -1;
                for(int i=0; i<totalFiles; i++) {
                    if(strcmp(files[i].filename, filename) == 0) {
                        fileIndex = i;
                        break;
                    }
                }

                if(fileIndex == -1) {
                    printf("Error: File not found!\n");
                    break;
                }

                printf("Enter data to write (of size %d bytes): ", files[fileIndex].size);
                char data[files[fileIndex].size];
                scanf(" %[^\n]s", data);

                writeToFile(fileIndex, data);
                break;
            }
            case 'r': {
                char filename[20];
                printf("Enter file name: ");
                scanf("%s", filename);

                int fileIndex = -1;
                for(int i=0; i<totalFiles; i++) {
                    if(strcmp(files[i].filename, filename) == 0) {
                        fileIndex = i;
                        break;
                    }
                }

                if(fileIndex == -1) {
                    printf("Error: File not found!\n");
                    break;
                }

                readFile(fileIndex);
                break;
            }
            case 'd': {
                char filename[20];
                printf("Enter file name: ");
                scanf("%s", filename);

                int fileIndex = -1;
                for(int i=0; i<totalFiles; i++) {
                    if(strcmp(files[i].filename, filename) == 0) {
                        fileIndex = i;
                        break;
                    }
                }

                if(fileIndex == -1) {
                    printf("Error: File not found!\n");
                    break;
                }

                deleteFile(fileIndex);
                break;
            }
            case 'l': {
                displayFiles();
                break;
            }
            default: {
                printf("Invalid command entered!\n");
            }
        }
    }

    printf("Exiting the Cyberpunk File System Simulation!\n");
    return 0;
}