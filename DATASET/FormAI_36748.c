//FormAI DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 50
#define MAX_BLOCKS 20
#define BLOCK_SIZE 512

typedef struct {
    char name[MAX_FILENAME];
    int size;
    int blocks[MAX_BLOCKS];
} File;

int main() {
    File file_table[MAX_BLOCKS];
    int free_blocks[MAX_BLOCKS];
    int num_files = 0;
    int num_free_blocks = MAX_BLOCKS;
    char command[30];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char filename[MAX_FILENAME];
            int size;

            scanf("%s %d", filename, &size);

            if (num_free_blocks >= size) {
                int file_blocks[size];

                for (int i = 0; i < size; i++) {
                    file_blocks[i] = free_blocks[num_free_blocks-1];
                    num_free_blocks--;
                }

                strcpy(file_table[num_files].name, filename);
                file_table[num_files].size = size;
                memcpy(file_table[num_files].blocks, file_blocks, sizeof(file_blocks));

                printf("File created: %s. Size: %d\n", filename, size);
                num_files++;
            } else {
                printf("Error: not enough disk space.\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            char filename[MAX_FILENAME];
            scanf("%s", filename);

            int i;
            for (i = 0; i < num_files; i++) {
                if (strcmp(filename, file_table[i].name) == 0) {
                    for (int j = 0; j < file_table[i].size; j++) {
                        free_blocks[num_free_blocks] = file_table[i].blocks[j];
                        num_free_blocks++;
                    }

                    printf("File deleted: %s\n", filename);
                    num_files--;

                    for (; i < num_files; i++) {
                        file_table[i] = file_table[i+1];
                    }

                    break;
                }
            }

            if (i == num_files) {
                printf("Error: file not found.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            printf("%-20s %-8s %-30s\n", "File Name", "Size", "Blocks");

            for (int i = 0; i < num_files; i++) {
                printf("%-20s %-8d ", file_table[i].name, file_table[i].size);
                printf("[ ");
                for (int j = 0; j < file_table[i].size; j++) {
                    printf("%d ", file_table[i].blocks[j]);
                }
                printf("]\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Error: command not recognized.\n");
        }
    }
}