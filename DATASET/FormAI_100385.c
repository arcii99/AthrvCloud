//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 255
#define MAX_FILE_SIZE 1048576 // 1MB
#define BLOCK_SIZE 1024 // 1KB
#define NUM_BLOCKS 1024

typedef struct {
   char name[MAX_FILENAME_LEN+1];
   int size;
   int blocks[10];
} file_t;

int main() {
   file_t files[NUM_BLOCKS];
   char block_bitmap[NUM_BLOCKS];
   char cmd[20];
   char arg[MAX_FILENAME_LEN+1];
   int i, j, k, num_blocks_needed, free_blocks, start_block, found;
   FILE *fd;
   
   // Initialize all the files as unused
   for (i = 0; i < NUM_BLOCKS; i++) {
      strcpy(files[i].name, "");
      files[i].size = 0;
      for (j = 0; j < 10; j++) {
         files[i].blocks[j] = -1;
      }
   }
   
   // Initialize the block bitmap as all free
   memset(block_bitmap, '0', NUM_BLOCKS);
   
   // Main loop to accept commands from the user
   while (1) {
      // Display prompt and get command from user
      printf("> ");
      scanf("%s", cmd);
      
      // "quit" command to exit program
      if (strcmp(cmd, "quit") == 0) {
         break;
      }
      
      // "ls" command to list all files
      else if (strcmp(cmd, "ls") == 0) {
         printf("Filename\tSize\n");
         for (i = 0; i < NUM_BLOCKS; i++) {
            if (strcmp(files[i].name, "") != 0) {
               printf("%s\t%d\n", files[i].name, files[i].size);
            }
         }
      }
      
      // "create" command to create a new file
      else if (strcmp(cmd, "create") == 0) {
         // Get filename and size from user
         scanf("%s %d", arg, &files[i].size);
         
         // Calculate how many blocks the file needs
         num_blocks_needed = (files[i].size + BLOCK_SIZE - 1) / BLOCK_SIZE;
         
         // Check if there are enough free blocks
         free_blocks = 0;
         for (j = 0; j < NUM_BLOCKS; j++) {
            if (block_bitmap[j] == '0') {
               free_blocks++;
               if (free_blocks == num_blocks_needed) {
                  start_block = j - num_blocks_needed + 1;
                  break;
               }
            }
            else {
               free_blocks = 0;
            }
         }
         
         // If there aren't enough free blocks, print an error message
         if (free_blocks < num_blocks_needed) {
            printf("Error: not enough space\n");
         }
         
         // If there are enough free blocks, create the file
         else {
            strcpy(files[i].name, arg);
            for (k = 0; k < num_blocks_needed; k++) {
               files[i].blocks[k] = start_block + k;
               block_bitmap[start_block + k] = '1';
            }
            // Open file for writing and write the initial contents
            fd = fopen(files[i].name, "wb");
            for (k = 0; k < BLOCK_SIZE; k++) {
               fwrite("0", 1, 1, fd);
            }
            fclose(fd);
            printf("File created\n");
         }
      }
      
      // "delete" command to delete a file
      else if (strcmp(cmd, "delete") == 0) {
         // Get filename from user
         scanf("%s", arg);
         
         // Find the file and mark its blocks as free
         found = 0;
         for (i = 0; i < NUM_BLOCKS; i++) {
            if (strcmp(files[i].name, arg) == 0) {
               found = 1;
               for (j = 0; j < 10 && files[i].blocks[j] != -1; j++) {
                  block_bitmap[files[i].blocks[j]] = '0';
               }
               strcpy(files[i].name, "");
               files[i].size = 0;
               for (j = 0; j < 10; j++) {
                  files[i].blocks[j] = -1;
               }
               // Delete the file from the filesystem
               remove(arg);
               printf("File deleted\n");
               break;
            }
         }
         
         // Print an error message if the file wasn't found
         if (!found) {
            printf("Error: file not found\n");
         }
      }
      
      // "read" command to read the contents of a file
      else if (strcmp(cmd, "read") == 0) {
         // Get filename from user
         scanf("%s", arg);
         
         // Find the file and read its contents
         found = 0;
         for (i = 0; i < NUM_BLOCKS; i++) {
            if (strcmp(files[i].name, arg) == 0) {
               found = 1;
               fd = fopen(arg, "rb");
               for (j = 0; j < files[i].size; j++) {
                  printf("%c", fgetc(fd));
               }
               fclose(fd);
               printf("\n");
               break;
            }
         }
         
         // Print an error message if the file wasn't found
         if (!found) {
            printf("Error: file not found\n");
         }
      }
      
      // "write" command to write to a file
      else if (strcmp(cmd, "write") == 0) {
         // Get filename from user
         scanf("%s", arg);
         
         // Find the file and open it for writing
         found = 0;
         for (i = 0; i < NUM_BLOCKS; i++) {
            if (strcmp(files[i].name, arg) == 0) {
               found = 1;
               fd = fopen(arg, "wb");
               break;
            }
         }
         
         // Print an error message if the file wasn't found
         if (!found) {
            printf("Error: file not found\n");
         }
         
         // If the file was found, write the new contents to it
         else {
            char buffer[MAX_FILE_SIZE+1];
            int num_bytes, bytes_written;
            printf("(press Ctrl-D to finish writing)\n");
            num_bytes = fread(buffer, 1, MAX_FILE_SIZE, stdin);
            buffer[num_bytes] = '\0';
            bytes_written = fwrite(buffer, 1, num_bytes, fd);
            fclose(fd);
            if (bytes_written == num_bytes) {
               printf("Write successful\n");
            }
            else {
               printf("Error: write unsuccessful\n");
            }
         }
      }
      
      // Unknown command
      else {
         printf("Unknown command: %s\n", cmd);
      }
   }

   return 0;
}