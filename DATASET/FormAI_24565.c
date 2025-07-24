//FormAI DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INODES 50
#define MAX_FILENAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_FILENAME_LENGTH];
    int size;
    int blocks[10];
} inode;

typedef struct {
    int id;
    int free_blocks[100];
} superblock;

int get_free_block(superblock* sb) {
    int i;
    for (i=0; i<100; i++) {
        if (sb->free_blocks[i]) {
            sb->free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

void free_block(superblock* sb, int block) {
    sb->free_blocks[block] = 1;
}

int main() {
    inode inodes[MAX_INODES];
    superblock sb;
    sb.id = 0;
    int i, j;
    for (i=0; i<100; i++) {
        sb.free_blocks[i] = 1;
    }
    
    int choice;
    do {
        printf("\n1. Create file\n2. Delete file\n3. Read file\n4. Write to file\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            for (i=0; i<MAX_INODES; i++) {
                if (inodes[i].id == 0) {
                    printf("Enter filename (max 20 characters): ");
                    scanf("%s", inodes[i].name);
                    
                    printf("Enter file size (max 100 blocks): ");
                    scanf("%d", &inodes[i].size);
                    
                    if (inodes[i].size > 100) {
                        printf("File size too large");
                        inodes[i].id = 0;
                        break;
                    }
                    
                    for (j=0; j<inodes[i].size; j++) {
                        int block = get_free_block(&sb);
                        
                        if (block == -1) {
                            printf("Error: Disk full\n");
                            free_block(&sb, j);
                            break;
                        }
                        
                        inodes[i].blocks[j] = block;
                    }
                    
                    if (j != inodes[i].size) {
                        // some blocks failed to allocate
                        for (j=0; j<inodes[i].size; j++) {
                            free_block(&sb, inodes[i].blocks[j]);
                        }
                        inodes[i].id = 0;
                    } else {
                        // file created successfully
                        inodes[i].id = i+1;
                        printf("File created successfully. Inode number: %d\n", inodes[i].id);
                    }
                    break;
                }
            }
            if (i == MAX_INODES) {
                printf("Error: Max number of files reached\n");
            }
        } else if (choice == 2) {
            int id;
            printf("Enter inode number to delete: ");
            scanf("%d", &id);
            
            for (i=0; i<MAX_INODES; i++) {
                if (inodes[i].id == id) {
                    for (j=0; j<inodes[i].size; j++) {
                        free_block(&sb, inodes[i].blocks[j]);
                    }
                    inodes[i].id = 0;
                    printf("File deleted successfully\n");
                    break;
                }
            }
            if (i == MAX_INODES) {
                printf("Error: Inode not found\n");
            }
        } else if (choice == 3) {
            int id;
            printf("Enter inode number to read: ");
            scanf("%d", &id);
            
            for (i=0; i<MAX_INODES; i++) {
                if (inodes[i].id == id) {
                    printf("%s:\n", inodes[i].name);
                    for (j=0; j<inodes[i].size; j++) {
                        printf("Block %d: Data\n", inodes[i].blocks[j]);
                    }
                    break;
                }
            }
            if (i == MAX_INODES) {
                printf("Error: Inode not found\n");
            }
        } else if (choice == 4) {
            int id;
            printf("Enter inode number to write to: ");
            scanf("%d", &id);
            
            for (i=0; i<MAX_INODES; i++) {
                if (inodes[i].id == id) {
                    printf("Enter data:");
                    char data[100];
                    scanf("%s", data);
                    int len = strlen(data);
                    if (len > inodes[i].size * 100) {
                        printf("Error: Data too large\n");
                        break;
                    }
                    for (j=0; j<len; j++) {
                        printf("Writing '%c' to block %d\n", data[j], inodes[i].blocks[j/100]);
                    }
                    break;
                }
            }
            if (i == MAX_INODES) {
                printf("Error: Inode not found\n");
            }
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    } while (1);
    
    return 0;
}