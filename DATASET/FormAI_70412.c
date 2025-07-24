//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BLOCKS 100
#define BLOCK_SIZE 512
#define FILE_NAME_LENGTH 20

typedef struct {
    int block_num;
    int next_block;
} Block;

typedef struct {
    char name[FILE_NAME_LENGTH];
    int first_block;
    int file_size;
} File;

void write_to_block(int block_num, char* data) {
    // code for writing data to a block goes here
}

void read_from_block(int block_num, char* buffer) {
    // code for reading data from a block goes here
}

int main() {
    Block blocks[NUM_BLOCKS];
    File files[NUM_BLOCKS];
    char buffer[BLOCK_SIZE];
    int i, j, num_files = 0;

    // initialize blocks as free
    for (i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].block_num = i;
        blocks[i].next_block = -1;
    }

    // main loop
    while (1) {
        printf("\nAvailable commands: create, delete, read, write, list, exit \n");
        printf("Enter a command: ");
        char command[10];
        scanf("%s", command);
        
        if (strcmp(command, "create") == 0) {
            // create a new file
            char file_name[FILE_NAME_LENGTH];
            printf("Enter file name (max length %d): ", FILE_NAME_LENGTH);
            scanf("%s", file_name);

            // check if file with same name exists
            for (i = 0; i < num_files; i++) {
                if (strcmp(files[i].name, file_name) == 0) {
                    printf("Error: file already exists\n");
                    break;
                }
            }

            // find free block to allocate to file
            int free_block = -1;
            for (i = 0; i < NUM_BLOCKS; i++) {
                if (blocks[i].next_block == -1) {
                    free_block = i;
                    break;
                }
            }

            // add new file to file list
            if (i == num_files && free_block != -1) {
                strncpy(files[i].name, file_name, FILE_NAME_LENGTH);
                files[i].first_block = free_block;
                files[i].file_size = 0;
                blocks[free_block].next_block = -2;  // mark block as allocated
                printf("File created successfully, first block %d allocated\n", free_block);
                num_files++;
            } else if (free_block == -1) {
                printf("Error: no free blocks\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            // delete a file
            char file_name[FILE_NAME_LENGTH];
            printf("Enter file name to delete: ");
            scanf("%s", file_name);
            
            for (i = 0; i < num_files; i++) {
                if (strcmp(files[i].name, file_name) == 0) {
                    // remove file
                    int block_num = files[i].first_block;
                    while (block_num != -1 && block_num != -2) {
                        blocks[block_num].next_block = -1;
                        block_num = blocks[block_num].next_block;
                    }
                    files[i] = files[num_files-1];
                    num_files--;
                    printf("File deleted successfully\n");
                    break;
                }
            }

            if (i == num_files) {
                printf("Error: file not found\n");
            }
        } else if (strcmp(command, "read") == 0) {
            // read from a file
            char file_name[FILE_NAME_LENGTH];
            printf("Enter file name to read: ");
            scanf("%s", file_name);
            int found_file = 0;

            for (i = 0; i < num_files; i++) {
                if (strcmp(files[i].name, file_name) == 0) {
                    found_file = 1;
                    int block_num = files[i].first_block;
                    while (block_num != -1) {
                        read_from_block(block_num, buffer);
                        printf("%s", buffer);
                        block_num = blocks[block_num].next_block;
                    }
                    break;
                }
            }

            if (!found_file) {
                printf("Error: file not found\n");
            }
        } else if (strcmp(command, "write") == 0) {
            // write to a file
            char file_name[FILE_NAME_LENGTH];
            printf("Enter file name to write: ");
            scanf("%s", file_name);
            int found_file = 0;

            for (i = 0; i < num_files; i++) {
                if (strcmp(files[i].name, file_name) == 0) {
                    found_file = 1;
                    int block_num = files[i].first_block;
                    FILE* fp = tmpfile();
                    char c;
                    while ((c = getchar()) != EOF && c != '\n');  // clear input buffer
                    printf("Enter text to write (max %d characters): ", BLOCK_SIZE);
                    fgets(buffer, BLOCK_SIZE, stdin);
                    buffer[strnlen(buffer, BLOCK_SIZE)-1] = '\0';  // remove trailing newline
                    int bytes_written = 0;

                    // write first block
                    strncpy(&buffer[bytes_written], &buffer[0], BLOCK_SIZE-bytes_written);
                    write_to_block(block_num, buffer);
                    bytes_written += BLOCK_SIZE;
                    block_num = blocks[block_num].next_block;

                    // write subsequent blocks
                    while (block_num != -1 && bytes_written < files[i].file_size) {
                        strncpy(&buffer[0], &buffer[bytes_written], BLOCK_SIZE);
                        write_to_block(block_num, buffer);
                        bytes_written += BLOCK_SIZE;
                        block_num = blocks[block_num].next_block;
                    }

                    // allocate additional blocks if necessary
                    while (bytes_written < strnlen(buffer, BLOCK_SIZE)) {
                        int free_block = -1;
                        for (j = 0; j < NUM_BLOCKS; j++) {
                            if (blocks[j].next_block == -1) {
                                free_block = j;
                                break;
                            }
                        }

                        if (free_block != -1) {
                            blocks[block_num].next_block = free_block;
                            files[i].file_size += BLOCK_SIZE;
                            block_num = free_block;
                            blocks[block_num].next_block = -2;  // mark block as allocated

                            if (bytes_written + BLOCK_SIZE <= strnlen(buffer, BLOCK_SIZE)) {
                                strncpy(&buffer[0], &buffer[bytes_written], BLOCK_SIZE);
                                write_to_block(block_num, buffer);
                                bytes_written += BLOCK_SIZE;
                            } else {
                                strncpy(&buffer[0], &buffer[bytes_written], strnlen(buffer, BLOCK_SIZE)-bytes_written);
                                buffer[strnlen(buffer, BLOCK_SIZE)-bytes_written] = '\0';  // remove trailing newline
                                write_to_block(block_num, buffer);
                                bytes_written += strnlen(buffer, BLOCK_SIZE)-bytes_written;
                            }
                        } else {
                            printf("Error: no free blocks\n");
                            break;
                        }
                    }

                    printf("Text written successfully\n");
                    break;
                }
            }

            if (!found_file) {
                printf("Error: file not found\n");
            }
        } else if (strcmp(command, "list") == 0) {
            // list all files
            if (num_files == 0) {
                printf("No files found\n");
            } else {
                printf("File list:\n");
                for (i = 0; i < num_files; i++) {
                    printf("%s\n", files[i].name);
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            // exit program
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}