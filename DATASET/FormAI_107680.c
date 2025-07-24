//FormAI DATASET v1.0 Category: File system simulation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_NAME_LENGTH 100 //max length of file name
#define NUM_BLOCKS 100 //number of blocks in file system
#define BLOCK_SIZE 512 //size of each block in bytes

struct file {
    char name[MAX_NAME_LENGTH]; //file name
    int start_block; //starting block of file
    int num_blocks; //number of blocks file spans
};

struct block {
    int id; //unique block identifier
    char data[BLOCK_SIZE]; //data contained in block
};

int main() {
    struct file files[NUM_BLOCKS]; //array of files in system
    struct block blocks[NUM_BLOCKS]; //array of blocks in system
    int free_blocks[NUM_BLOCKS]; //array of free blocks in system
    int num_used_blocks = 0; //number of used blocks in system
    int num_free_blocks = NUM_BLOCKS; //number of free blocks in system
    int file_index = 0; //index of current file in files array

    //initialize free block array
    for(int i=0; i<NUM_BLOCKS; i++) {
        free_blocks[i] = i; //block ids start at 0 and increase by 1
    }

    //user interface loop
    while(1) {
        //display options to user
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");

        //get user's choice
        int choice;
        printf("Please choose an option: ");
        scanf("%d", &choice);

        //process user's choice
        switch(choice) {
            case 1:
                //create file
                printf("Please enter the file name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                //check if file with this name already exists
                int file_exists = 0;
                for(int i=0; i<file_index; i++) {
                    if(strcmp(files[i].name, name) == 0) {
                        file_exists = 1;
                        break;
                    }
                }

                if(file_exists == 1) {
                    printf("Error: File with this name already exists.\n");
                }
                else {
                    //check if there are enough free blocks to create the file
                    int num_blocks_needed;
                    printf("Please enter the number of blocks needed: ");
                    scanf("%d", &num_blocks_needed);

                    if(num_blocks_needed <= num_free_blocks) {
                        //allocate blocks for file
                        int start_block = free_blocks[0];
                        for(int i=start_block; i<(start_block+num_blocks_needed); i++) {
                            blocks[i].id = i;
                            free_blocks[i] = -1;
                        }

                        //update file information
                        strcpy(files[file_index].name, name);
                        files[file_index].start_block = start_block;
                        files[file_index].num_blocks = num_blocks_needed;
                        file_index++;

                        //update free block count
                        num_used_blocks += num_blocks_needed;
                        num_free_blocks -= num_blocks_needed;

                        printf("File created successfully.\n");
                    }
                    else {
                        printf("Error: Not enough free space in file system.\n");
                    }
                }
                break;
            case 2:
                //delete file
                printf("Please enter the file name: ");
                char file_name[MAX_NAME_LENGTH];
                scanf("%s", file_name);

                //find file with this name and deallocate its blocks
                int file_deleted = 0;
                for(int i=0; i<file_index; i++) {
                    if(strcmp(files[i].name, file_name) == 0) {
                        int start_block = files[i].start_block;
                        int num_blocks = files[i].num_blocks;

                        for(int j=start_block; j<(start_block+num_blocks); j++) {
                            free_blocks[j] = j;
                            memset(&blocks[j], 0, sizeof(struct block));
                        }

                        //update file information
                        memset(&files[i], 0, sizeof(struct file));
                        file_index--;

                        //update free block count
                        num_used_blocks -= num_blocks;
                        num_free_blocks += num_blocks;

                        file_deleted = 1;
                        printf("File deleted successfully.\n");
                        break;
                    }
                }

                if(file_deleted == 0) {
                    printf("Error: File with this name does not exist.\n");
                }
                break;
            case 3:
                //list files
                printf("Name\t\tStart block\tNumber of blocks\n");
                for(int i=0; i<file_index; i++) {
                    printf("%s\t\t%d\t\t%d\n", files[i].name, files[i].start_block, files[i].num_blocks);
                }
                break;
            case 4:
                //exit program
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
                break;
        }

        //print free block list for debugging
        printf("Free blocks: ");
        for(int i=0; i<NUM_BLOCKS; i++) {
            if(free_blocks[i] != -1) {
                printf("%d, ", free_blocks[i]);
            }
        }
        printf("\n");
    }

    return 0;
}