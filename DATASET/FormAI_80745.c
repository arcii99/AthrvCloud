//FormAI DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILENAME 20
#define MAX_BLOCKS 100

int freeBlocks[MAX_BLOCKS]; // array to keep track of free blocks in the system
int filesCount = 0; // count of number of files in the system

struct File {
  char name[MAX_FILENAME];
  int blocks[10]; // array to store the block numbers that the file occupies
  int size; // size of the file
};

struct File files[MAX_FILES]; // array to store the files

// function to initialize the freeBlocks array
void initialize() {
  int i;
  for(i=0; i<MAX_BLOCKS; i++) {
    freeBlocks[i] = 1;
  }
}

// function to allocate blocks for a file
int allocate(int blocksRequired) {
  int i, j, count, start, totalBlocks, flag = 0;

  for(i=0; i<MAX_BLOCKS; i++) {
    if(freeBlocks[i] == 1) {
      count = 0;
      start = i;
      for(j=i; j<MAX_BLOCKS; j++) {
        if(freeBlocks[j] == 1) {
          count++;
          if(count == blocksRequired) {
            totalBlocks = count;
            flag = 1;
            break;
          }
        }
        else {
          break;
        }
      }
      if(flag) {
        break;
      }
    }
  }

  if(flag) {
    for(i=start; i<start+totalBlocks; i++) {
      freeBlocks[i] = 0;
    }
    return start;
  }
  else {
    return -1;
  }
}

// function to create a file
int createFile(char* name, int size) {
  int blocksRequired, firstBlock, i;

  // check if file with same name already exists
  for(i=0; i<filesCount; i++) {
    if(strcmp(name, files[i].name) == 0) {
      return -1;
    }
  }

  // calculate number of blocks required for the file
  blocksRequired = (size-1) / 10 + 1;

  // allocate blocks for the file
  firstBlock = allocate(blocksRequired);
  if(firstBlock == -1) {
    return -2;
  }

  // update info for the file
  strcpy(files[filesCount].name, name);
  files[filesCount].size = size;
  for(i=0; i<blocksRequired; i++) {
    files[filesCount].blocks[i] = firstBlock + i;
  }
  filesCount++;

  return 0;
}

// function to delete a file
int deleteFile(char* name) {
  int blocksOccupied[MAX_BLOCKS], blocksCount = 0, i, j;

  // check if file exists
  for(i=0; i<filesCount; i++) {
    if(strcmp(name, files[i].name) == 0) {
      // get blocks occupied by the file
      for(j=0; j<(files[i].size-1)/10+1; j++) {
        blocksOccupied[blocksCount++] = files[i].blocks[j];
      }
      // update file storage data
      for(j=0; j<blocksCount; j++) {
        freeBlocks[blocksOccupied[j]] = 1;
      }
      for(j=i; j<filesCount-1; j++) {
        strcpy(files[j].name, files[j+1].name);
        for(int k=0; k<10; k++) {
          files[j].blocks[k] = files[j+1].blocks[k];
        }
        files[j].size = files[j+1].size;
      }
      filesCount--;
      return 0;
    }
  }

  return -1;
}

int main() {
  initialize();

  createFile("file1", 200);
  createFile("file2", 50);
  createFile("file3", 120);
  createFile("file4", 80);

  deleteFile("file2");

  createFile("file5", 300);

  for(int i=0; i<filesCount; i++) {
    printf("Name: %s, Size: %d, Blocks: ", files[i].name, files[i].size);
    for(int j=0; j<10 && files[i].blocks[j]!=-1; j++) {
      printf("%d ", files[i].blocks[j]);
    }
    printf("\n");
  }

  return 0;
}