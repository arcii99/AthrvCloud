//FormAI DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 1024

typedef struct block
{
    int block_num;
    char data[BLOCK_SIZE];
    bool is_free;
} Block;

typedef struct file
{
    char name[20];
    int start_block_num;
    int size;
} File;

Block disk[MAX_BLOCKS];
File files[10];
int num_files = 0;

void init_disk()
{
    for (int i=0; i<MAX_BLOCKS; i++)
    {
        disk[i].block_num = i;
        disk[i].is_free = true;
        memset(disk[i].data, 0, BLOCK_SIZE);
    }
}

int find_free_block()
{
    for (int i=0; i<MAX_BLOCKS; i++)
    {
        if (disk[i].is_free)
            return i;
    }
    return -1;  // No free blocks
}

int create_file(char* name, int size)
{
    int start_block_num = find_free_block();
    if (start_block_num == -1)
        return -1;  // Disk is full

    // Allocate consecutive blocks to the file
    for (int i=start_block_num; i<start_block_num+size; i++)
    {
        if (!disk[i].is_free)  // Another file occupies some of these blocks
            return -1;
    }

    // Update disk information and return the start block number of the file
    strcpy(files[num_files].name, name);
    files[num_files].start_block_num = start_block_num;
    files[num_files].size = size;

    // Mark the blocks as occupied by this file
    for (int i=start_block_num; i<start_block_num+size; i++)
    {
        disk[i].is_free = false;
    }
    num_files++;
    return start_block_num;
}

void delete_file(char* name)
{
    for (int i=0; i<num_files; i++)
    {
        if (strcmp(files[i].name, name) == 0)
        {
            int start_block_num = files[i].start_block_num;
            int size = files[i].size;

            // Free the blocks occupied by this file
            for (int j=start_block_num; j<start_block_num+size; j++)
            {
                disk[j].is_free = true;
                memset(disk[j].data, 0, BLOCK_SIZE);
            }

            // Delete the file from our file list
            for (int j=i; j<num_files-1; j++)
            {
                files[j] = files[j+1];
            }
            num_files--;
            printf("File deleted successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

void read_file(char* name)
{
    for (int i=0; i<num_files; i++)
    {
        if (strcmp(files[i].name, name) == 0)
        {
            int start_block_num = files[i].start_block_num;
            int size = files[i].size;

            // Print the contents of the file
            for (int j=start_block_num; j<start_block_num+size; j++)
            {
                printf("%s", disk[j].data);
            }
            printf("\n");
            return;
        }
    }
    printf("File not found.\n");
}

void write_file(char* name, char* data)
{
    for (int i=0; i<num_files; i++)
    {
        if (strcmp(files[i].name, name) == 0)
        {
            int start_block_num = files[i].start_block_num;
            int size = files[i].size;
            int data_len = strlen(data);

            // Check if data fits in the file
            if (data_len > size * BLOCK_SIZE)
            {
                printf("Not enough space in the file.\n");
                return;
            }

            // Overwrite the file with the new data
            int j = 0;
            for (int k=start_block_num; k<start_block_num+size; k++)
            {
                memset(disk[k].data, 0, BLOCK_SIZE);
                for (int l=0; l<BLOCK_SIZE && j<data_len; l++)
                {
                    disk[k].data[l] = data[j];
                    j++;
                }
            }
            printf("File written successfully.\n");
            return;
        }
    }
    printf("File not found.\n");
}

int main()
{
    init_disk();

    int choice;
    char name[20], data[10];
    int size, start_block_num;

    while (true)
    {
        printf("1. Create file\n2. Delete file\n3. Read file\n4. Write file\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                start_block_num = create_file(name, size);
                if (start_block_num == -1)
                    printf("Unable to create file.\n");
                else
                    printf("File created successfully. Start block number: %d.\n", start_block_num);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(name);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", name);
                read_file(name);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter data to write: ");
                scanf("%s", data);
                write_file(name, data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}