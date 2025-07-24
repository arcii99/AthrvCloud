//FormAI DATASET v1.0 Category: File system simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// File system parameters
#define BLOCK_SIZE 4096
#define NUM_BLOCKS 1000
#define NUM_INODES 100
#define NUM_THREADS 10

// File system structures
typedef struct {
    char* data;
    int size;
    pthread_mutex_t lock;
} Block;

typedef struct {
    int block_ptrs[10];
    int size;
    pthread_mutex_t lock;
} Inode;

typedef struct {
    Block blocks[NUM_BLOCKS];
    Inode inodes[NUM_INODES];
    int free_blocks[NUM_BLOCKS];
    int free_inodes[NUM_INODES];
    int next_free_block;
    int next_free_inode;
} FileSystem;

FileSystem fs;

// Helper functions
void* write_data(void* arg);
void* read_data(void* arg);
void write_block(int block_num, char* data);
void read_block(int block_num, char* buffer);

int main() {
    // Initialize file system
    for (int i = 0; i < NUM_BLOCKS; i++) {
        fs.free_blocks[i] = 1;
        fs.blocks[i].data = calloc(BLOCK_SIZE, sizeof(char));
        pthread_mutex_init(&fs.blocks[i].lock, NULL);
    }
    for (int i = 0; i < NUM_INODES; i++) {
        fs.free_inodes[i] = 1;
        pthread_mutex_init(&fs.inodes[i].lock, NULL);
    }
    fs.next_free_block = 0;
    fs.next_free_inode = 0;

    // Start threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, write_data, NULL);
        } else {
            pthread_create(&threads[i], NULL, read_data, NULL);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up file system resources
    for (int i = 0; i < NUM_BLOCKS; i++) {
        pthread_mutex_destroy(&fs.blocks[i].lock);
        free(fs.blocks[i].data);
    }
    for (int i = 0; i < NUM_INODES; i++) {
        pthread_mutex_destroy(&fs.inodes[i].lock);
    }

    return 0;
}

void* write_data(void* arg) {
    char data[BLOCK_SIZE] = "Hello, world!";
    int inode_num = fs.next_free_inode++;
    int block_num = fs.next_free_block++;
    for (int i = 0; i < 10; i++) {
        int free_block_num = fs.next_free_block++;
        fs.inodes[inode_num].block_ptrs[i] = free_block_num;
        fs.free_blocks[free_block_num] = 0;
    }
    fs.inodes[inode_num].size = BLOCK_SIZE * 10;
    fs.free_inodes[inode_num] = 0;
    write_block(block_num, data);
    return NULL;
}

void* read_data(void* arg) {
    int inode_num = rand() % NUM_INODES;
    char buffer[BLOCK_SIZE];
    for (int i = 0; i < 10; i++) {
        int block_num = fs.inodes[inode_num].block_ptrs[i];
        read_block(block_num, buffer);
    }
    return NULL;
}

void write_block(int block_num, char* data) {
    pthread_mutex_lock(&fs.blocks[block_num].lock);
    strcpy(fs.blocks[block_num].data, data);
    pthread_mutex_unlock(&fs.blocks[block_num].lock);
}

void read_block(int block_num, char* buffer) {
    pthread_mutex_lock(&fs.blocks[block_num].lock);
    strcpy(buffer, fs.blocks[block_num].data);
    pthread_mutex_unlock(&fs.blocks[block_num].lock);
}