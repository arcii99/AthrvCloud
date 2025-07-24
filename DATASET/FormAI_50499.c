//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024
#define NUM_INODES 64
#define NAME_LENGTH 32

typedef struct {
  char name[NAME_LENGTH];
  int size;
  int direct_blocks[10];
  int single_indirect_block;
  int double_indirect_block;
} inode;

typedef struct {
  char free;
  int next_block;
} block_bitmap;

typedef struct {
  char free;
  inode inodes[NUM_INODES];
} inode_bitmap;

int main() {
  // Initialize file system
  block_bitmap block_map[NUM_BLOCKS];
  inode_bitmap inode_map;
  memset(block_map, 1, sizeof(block_map));
  memset(&inode_map, 0, sizeof(inode_map));
  for (int i = 0; i < NUM_INODES; i++)
    inode_map.free = 1;

  // Create root directory
  inode root;
  root.name[0] = '/';
  root.size = 0;
  root.direct_blocks[0] = 0; // Assume block 0 is reserved for root
  inode_map.free = 0;
  inode_map.inodes[0] = root;

  // Command loop
  char command[NAME_LENGTH];
  printf("Welcome to Genius FileSystem!\n");
  while (1) {
    printf("Please enter a command: ");
    scanf("%s", command);
    if (strcmp(command, "quit") == 0)
      break;
    else if (strcmp(command, "ls") == 0) {
      // List files in current directory
      inode current = inode_map.inodes[0]; // Assume root is current directory
      for (int i = 0; i < current.size; i++) {
        printf("%s\n", current.direct_blocks[i]);
      }
    }
    else if (strcmp(command, "mkdir") == 0) {
      // Create new directory
      char dir_name[NAME_LENGTH];
      scanf("%s", dir_name);

      // Check if directory with same name already exists
      inode current = inode_map.inodes[0]; // Assume root is current directory
      for (int i = 0; i < current.size; i++) {
        inode child = inode_map.inodes[current.direct_blocks[i]];
        if (strcmp(child.name, dir_name) == 0) {
          printf("Directory with name %s already exists", dir_name);
          break;
        }
      }

      // Create new inode for directory
      int inode_index = -1;
      for (int i = 0; i < NUM_INODES; i++) {
        if (inode_map.free) {
          inode_index = i;
          inode_map.free = 0;
          break;
        }
      }
      if (inode_index == -1) {
        printf("No free inodes available");
        break;
      }
      inode new_dir;
      memset(&new_dir, 0, sizeof(new_dir));
      strncpy(new_dir.name, dir_name, NAME_LENGTH);
      inode_map.inodes[inode_index] = new_dir;

      // Add inode to current directory's direct blocks
      int block_index = -1;
      for (int i = 0; i < current.size; i++) {
        if (block_map[current.direct_blocks[i]].free) {
          block_map[current.direct_blocks[i]].free = 0;
          block_index = current.direct_blocks[i];
          break;
        }
      }
      if (block_index == -1) {
        printf("No free blocks available");
        break;
      }
      current.direct_blocks[current.size++] = block_index;
      inode_map.inodes[0] = current;
      printf("Directory %s created", dir_name);
    }
    else if (strcmp(command, "cd") == 0) {
      // Change directory
      char dir_name[NAME_LENGTH];
      scanf("%s", dir_name);

      // Check if directory exists
      inode current = inode_map.inodes[0]; // Assume root is current directory
      int dir_index = -1;
      for (int i = 0; i < current.size; i++) {
        inode child = inode_map.inodes[current.direct_blocks[i]];
        if (strcmp(child.name, dir_name) == 0) {
          dir_index = current.direct_blocks[i];
          break;
        }
      }
      if (dir_index == -1) {
        printf("Directory %s does not exist", dir_name);
        break;
      }

      // Update current directory
      current = inode_map.inodes[dir_index];
      inode_map.inodes[0] = current;
      printf("Changed directory to %s", dir_name);
    }
    else if (strcmp(command, "create") == 0) {
      // Create new file
      char file_name[NAME_LENGTH];
      scanf("%s", file_name);
      int file_size;
      printf("Enter file size in bytes: ");
      scanf("%d", &file_size);

      // Check if file with same name already exists
      inode current = inode_map.inodes[0]; // Assume root is current directory
      for (int i = 0; i < current.size; i++) {
        inode child = inode_map.inodes[current.direct_blocks[i]];
        if (strcmp(child.name, file_name) == 0) {
          printf("File with name %s already exists", file_name);
          break;
        }
      }

      // Create new inode for file
      int inode_index = -1;
      for (int i = 0; i < NUM_INODES; i++) {
        if (inode_map.free) {
          inode_index = i;
          inode_map.free = 0;
          break;
        }
      }
      if (inode_index == -1) {
        printf("No free inodes available");
        break;
      }
      inode new_file;
      memset(&new_file, 0, sizeof(new_file));
      strncpy(new_file.name, file_name, NAME_LENGTH);
      new_file.size = file_size;
      inode_map.inodes[inode_index] = new_file;

      // Allocate blocks for file data
      int num_blocks = (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
      int blocks_allocated = 0;
      for (int i = 0; i < 10 && blocks_allocated < num_blocks; i++) {
        int block_index = -1;
        for (int j = 0; j < NUM_BLOCKS; j++) {
          if (block_map[j].free) {
            block_map[j].free = 0;
            block_index = j;
            break;
          }
        }
        if (block_index == -1) {
          printf("No free blocks available");
          break;
        }
        new_file.direct_blocks[i] = block_index;
        blocks_allocated++;
      }
      if (blocks_allocated < num_blocks) {
        printf("Not enough blocks available for file data");
        // Free allocated blocks to maintain consistency
        for (int i = 0; i < blocks_allocated; i++)
          block_map[new_file.direct_blocks[i]].free = 1;
        inode_map.free = 1;
        break;
      }

      if (num_blocks > 10) {
        // Single indirect block required
        int block_index = -1;
        for (int i = 0; i < NUM_BLOCKS; i++) {
          if (block_map[i].free) {
            block_map[i].free = 0;
            block_index = i;
            break;
          }
        }
        if (block_index == -1) {
          printf("No free blocks available");
          // Free allocated blocks to maintain consistency
          for (int i = 0; i < 10; i++)
            block_map[new_file.direct_blocks[i]].free = 1;
          inode_map.free = 1;
          break;
        }
        new_file.single_indirect_block = block_index;
        int blocks_remaining = num_blocks - 10;
        for (int i = 0; i < blocks_remaining; i++) {
          int indirect_block_index = -1;
          for (int j = 0; j < NUM_BLOCKS; j++) {
            if (block_map[j].free) {
              block_map[j].free = 0;
              indirect_block_index = j;
              break;
            }
          }
          if (indirect_block_index == -1) {
            printf("No free blocks available");
            // Free allocated blocks to maintain consistency
            for (int i = 0; i < 10; i++)
              block_map[new_file.direct_blocks[i]].free = 1;
            block_map[new_file.single_indirect_block].free = 1;
            inode_map.free = 1;
            break;
          }
          int data_block_index = -1;
          for (int j = 0; j < NUM_BLOCKS; j++) {
            if (block_map[j].free) {
              block_map[j].free = 0;
              data_block_index = j;
              break;
            }
          }
          if (data_block_index == -1) {
            printf("No free blocks available");
            // Free allocated blocks to maintain consistency
            for (int i = 0; i < 10; i++)
              block_map[new_file.direct_blocks[i]].free = 1;
            block_map[new_file.single_indirect_block].free = 1;
            for (int i = 0; i < i; i++)
              block_map[indirect_block_index].free = 1;
            inode_map.free = 1;
            break;
          }
          block_bitmap *single_indirect_block = &block_map[block_index];
          single_indirect_block->next_block = indirect_block_index;
          block_bitmap *indirect_block = &block_map[indirect_block_index];
          indirect_block->next_block = data_block_index;
          blocks_allocated++;
        }
        if (blocks_allocated < num_blocks) {
          // Free allocated blocks to maintain consistency
          for (int i = 0; i < 10; i++)
            block_map[new_file.direct_blocks[i]].free = 1;
          block_map[new_file.single_indirect_block].free = 1;
          inode_map.free = 1;
          break;
        }
      }

      if (num_blocks > 10 + 256) {
        // Double indirect block required
        int block_index = -1;
        for (int i = 0; i < NUM_BLOCKS; i++) {
          if (block_map[i].free) {
            block_map[i].free = 0;
            block_index = i;
            break;
          }
        }
        if (block_index == -1) {
          printf("No free blocks available");
          // Free allocated blocks to maintain consistency
          for (int i = 0; i < 10; i++)
            block_map[new_file.direct_blocks[i]].free = 1;
          block_map[new_file.single_indirect_block].free = 1;
          inode_map.free = 1;
          break;
        }
        new_file.double_indirect_block = block_index;
        int blocks_remaining = num_blocks - 10 - 256;
        for (int i = 0; i < 256; i++) {
          int indirect_block_index = -1;
          for (int j = 0; j < NUM_BLOCKS; j++) {
            if (block_map[j].free) {
              block_map[j].free = 0;
              indirect_block_index = j;
              break;
            }
          }
          if (indirect_block_index == -1) {
            printf("No free blocks available");
            // Free allocated blocks to maintain consistency
            for (int i = 0; i < 10; i++)
              block_map[new_file.direct_blocks[i]].free = 1;
            block_map[new_file.single_indirect_block].free = 1;
            block_map[new_file.double_indirect_block].free = 1;
            inode_map.free = 1;
            break;
          }
          int remaining_blocks = num_blocks - 10 - 256 - i * 256;
          if (remaining_blocks <= 0)
            break;
          int num_indirect_blocks = remaining_blocks < 256 ? remaining_blocks : 256;
          int *indirect_block_indices = malloc(num_indirect_blocks * sizeof(int));
          int data_blocks_allocated = 0;
          for (int k = 0; k < num_indirect_blocks; k++) {
            int data_block_index = -1;
            for (int l = 0; l < NUM_BLOCKS; l++) {
              if (block_map[l].free) {
                block_map[l].free = 0;
                data_block_index = l;
                break;
              }
            }
            if (data_block_index == -1) {
              printf("No free blocks available");
              // Free allocated blocks to maintain consistency
              for (int i = 0; i < 10; i++)
                block_map[new_file.direct_blocks[i]].free = 1;
              block_map[new_file.single_indirect_block].free = 1;
              block_map[new_file.double_indirect_block].free = 1;
              for (int i = 0; i < i; i++)
                block_map[indirect_block_index].free = 1;
              for (int i = 0; i < k; i++)
                block_map[indirect_block_indices[i]].free = 1;
              free(indirect_block_indices);
              inode_map.free = 1;
              break;
            }
            block_bitmap *indirect_block = &block_map[indirect_block_index];
            indirect_block->next_block = data_block_index;
            indirect_block_indices[k] = data_block_index;
            data_blocks_allocated++;
          }
          if (data_blocks_allocated < num_indirect_blocks) {
            // Free allocated blocks to maintain consistency
            for (int i = 0; i < 10; i++)
              block_map[new_file.direct_blocks[i]].free = 1;
            block_map[new_file.single_indirect_block].free = 1;
            block_map[new_file.double_indirect_block].free = 1;
            for (int i = 0; i < i; i++)
              block_map[indirect_block_index].free = 1;
            for (int i = 0; i < data_blocks_allocated; i++)
              block_map[indirect_block_indices[i]].free = 1;
            free(indirect_block_indices);
            inode_map.free = 1;
            break;
          }
          block_bitmap *double_indirect_block = &block_map[block_index];
          double_indirect_block->next_block = indirect_block_index;
        }
        if (blocks_remaining > 0) {
          // Free allocated blocks to maintain consistency
          for (int i = 0; i < 10; i++)
            block_map[new_file.direct_blocks[i]].free = 1;
          block_map[new_file.single_indirect_block].free = 1;
          block_map[new_file.double_indirect_block].free = 1;
          inode_map.free = 1;
          break;
        }
      }

      // Update inode map
      inode_map.inodes[inode_index] = new_file;
      inode_map.inodes[0] = current;
      printf("File %s created with size %d bytes", file_name, file_size);
    }
    else if (strcmp(command, "cat") == 0) {
      // Print contents of file
      char file_name[NAME_LENGTH];
      scanf("%s", file_name);

      // Check if file exists
      inode current = inode_map.inodes[0]; // Assume root is current directory
      int file_index = -1;
      for (int i = 0; i < current.size; i++) {
        inode child = inode_map.inodes[current.direct_blocks[i]];
        if (strcmp(child.name, file_name) == 0) {
          file_index = current.direct_blocks[i];
          break;
        }
      }
      if (file_index == -1) {
        printf("File %s does not exist", file_name);
        break;
      }

      // Print contents of file
      inode file = inode_map.inodes[file_index];
      for (int i = 0; i < 10; i++) {
        int block_index = file.direct_blocks[i];
        printf("%s\n", (char *) &block_map[block_index]);
      }
      if (file.single_indirect_block != 0) {
        int *indirect_blocks = (int *) &block_map[file.single_indirect_block];
        for (int i = 0; i < 256; i++) {
          if (indirect_blocks[i] == 0)
            break;
          printf("%s\n", (char *) &block_map[indirect_blocks[i]]);
        }
      }
      if (file.double_indirect_block != 0) {
        int *first_indirect_blocks = (int *) &block_map[file.double_indirect_block];
        for (int i = 0; i < 256; i++) {
          if (first_indirect_blocks[i] == 0)
            break;
          int *second_indirect_blocks = (int *) &block_map[first_indirect_blocks[i]];
          for (int j = 0; j < 256; j++) {
            if (second_indirect_blocks[j] == 0)
              break;
            printf("%s\n", (char *) &block_map[second_indirect_blocks[j]]);
          }
        }
      }
    }
  }
  printf("Goodbye!\n");
  return 0;
}