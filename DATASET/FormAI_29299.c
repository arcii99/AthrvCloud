//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a macro for the maximum disk size
#define MAX_DISK_SIZE 1024

// define a macro for the number of chunks
#define NUM_CHUNKS 10

// define a macro for the size of each chunk
#define CHUNK_SIZE (MAX_DISK_SIZE / NUM_CHUNKS)

// define a struct for the chunk
typedef struct chunk {
  char name[128];
  int size;
} chunk;

// define a struct for the disk
typedef struct disk {
  chunk chunks[NUM_CHUNKS];
  int total_size;
} disk;

// function to initialize the disk
void init_disk(disk* d) {
  // set each chunk to empty
  for (int i = 0; i < NUM_CHUNKS; i++) {
    d->chunks[i].name[0] = '\0';
    d->chunks[i].size = 0;
  }
  // set the total size of the disk to 0
  d->total_size = 0;
}

// function to print the disk
void print_disk(disk* d) {
  printf("Disk contents:\n");
  for (int i = 0; i < NUM_CHUNKS; i++) {
    printf("Chunk %d: %s - %d bytes\n", i, d->chunks[i].name, d->chunks[i].size);
  }
  printf("Total size: %d bytes\n", d->total_size);
}

// function to add a chunk to the disk
void add_chunk(disk* d, char* name, int size) {
  // find the first empty chunk
  int i;
  for (i = 0; i < NUM_CHUNKS; i++) {
    if (d->chunks[i].name[0] == '\0') {
      break;
    }
  }
  // check if there is an empty chunk
  if (i == NUM_CHUNKS) {
    printf("Error: disk is full\n");
    return;
  }
  // add the chunk
  strcpy(d->chunks[i].name, name);
  d->chunks[i].size = size;
  d->total_size += size;
  printf("Added chunk %d: %s - %d bytes\n", i, name, size);
}

// function to remove a chunk from the disk
void rem_chunk(disk* d, int i) {
  // check if the chunk exists
  if (i < 0 || i >= NUM_CHUNKS || d->chunks[i].name[0] == '\0') {
    printf("Error: chunk does not exist\n");
    return;
  }
  // remove the chunk
  printf("Removed chunk %d: %s - %d bytes\n", i, d->chunks[i].name, d->chunks[i].size);
  d->total_size -= d->chunks[i].size;
  d->chunks[i].name[0] = '\0';
  d->chunks[i].size = 0;
}

// main function
int main() {
  disk d;
  init_disk(&d);
  add_chunk(&d, "chunk1", CHUNK_SIZE);
  add_chunk(&d, "chunk2", CHUNK_SIZE * 2);
  add_chunk(&d, "chunk3", CHUNK_SIZE * 3);
  print_disk(&d);
  rem_chunk(&d, 1);
  print_disk(&d);
  return 0;
}