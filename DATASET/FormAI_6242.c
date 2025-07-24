//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum size of each record */
#define MAX_RECORD_SIZE 128

/* Define the structure of our records */
typedef struct {
    char key[16];
    char data[MAX_RECORD_SIZE];
} Record;

/* Define the structure of our index */
typedef struct {
    char key[16];
    long int offset;
} Index;

/* Define the maximum number of records that can be stored in each block */
#define BLOCK_SIZE 1024

/* Define the structure of our blocks */
typedef struct {
    Index index[BLOCK_SIZE];
    int num_records;
    long int next_block;
} Block;

/* Define the maximum number of blocks that can be stored in memory */
#define MAX_MEM_BLOCKS 16

/* Define the structure of our memory buffer */
typedef struct {
    Block blocks[MAX_MEM_BLOCKS];
    int num_blocks;
} Buffer;

/* Define the size of our disk */
#define DISK_SIZE 1024 * 1024

/* Define the fp of our disk */
FILE *fp;

/* Define the current position of the free block pointer */
long int free_block_ptr;

/* Define the current position of the free index pointer */
long int free_index_ptr;

/* Open the file with the specified mode */
void open_file(char *filename, char *mode) {
    fp = fopen(filename, mode);
    if(fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }
}

/* Close the file */
void close_file() {
    fclose(fp);
}

/* Write a block to disk */
void write_block(Block *b, long int block_ptr) {
    fseek(fp, block_ptr, SEEK_SET);
    fwrite(b, sizeof(Block), 1, fp);
}

/* Read a block from disk */
void read_block(Block *b, long int block_ptr) {
    fseek(fp, block_ptr, SEEK_SET);
    fread(b, sizeof(Block), 1, fp);
}

/* Initialize a new block */
void init_block(Block *b) {
    b->num_records = 0;
    b->next_block = -1;
}

/* Get the next free block pointer */
long int get_free_block_ptr() {
    long int ptr = free_block_ptr;
    free_block_ptr += sizeof(Block);
    return ptr;
}

/* Get the next free index pointer */
long int get_free_index_ptr() {
    long int ptr = free_index_ptr;
    free_index_ptr += sizeof(Index);
    return ptr;
}

/* Add a record to the specified block */
void add_record(Block *b, char *key, char *data) {
    /* Check if there is enough space in the block */
    if(b->num_records == BLOCK_SIZE) {
        /* The block is full so we must add a new block */
        if(b->next_block == -1) {
            /* No more blocks are linked so we must create a new block */
            b->next_block = get_free_block_ptr();
            Block new_block;
            init_block(&new_block);
            write_block(&new_block, b->next_block);
        }
        /* Load the next block and add the record */
        Block next_block;
        read_block(&next_block, b->next_block);
        add_record(&next_block, key, data);
    }
    else {
        /* Add the record */
        Index *index = &b->index[b->num_records];
        strncpy(index->key, key, 15);
        index->offset = get_free_index_ptr();
        strcpy((char *)(&b->index[b->num_records] + sizeof(Index)), data);
        b->num_records++;
    }
}

/* Find a record with the specified key */
Index *find_record(Buffer *buf, char *key) {
    /* Check if the record is in memory */
    for(int i = 0; i < buf->num_blocks; i++) {
        for(int j = 0; j < buf->blocks[i].num_records; j++) {
            if(strcmp(buf->blocks[i].index[j].key, key) == 0) {
                return &buf->blocks[i].index[j];
            }
        }
    }
    /* Check if the record is on disk */
    long int curr_block = free_index_ptr;
    while(curr_block != -1) {
        Block block;
        read_block(&block, curr_block);
        for(int i = 0; i < block.num_records; i++) {
            if(strcmp(block.index[i].key, key) == 0) {
                /* Add the block to the buffer */
                if(buf->num_blocks == MAX_MEM_BLOCKS) {
                    buf->num_blocks = 1;
                }
                else {
                    buf->num_blocks++;
                }
                buf->blocks[buf->num_blocks - 1] = block;
                /* Return the index */
                return &block.index[i];
            }
        }
        curr_block = block.next_block;
    }
    /* The record does not exist */
    return NULL;
}

/* Initialize the buffer */
void init_buffer(Buffer *buf) {
    buf->num_blocks = 0;
}

/* Insert a record */
void insert_record(Buffer *buf, char *key, char *data) {
    /* Find the block the record should be inserted in */
    Index *index = find_record(buf, key);
    if(index == NULL) {
        /* The record does not exist so we must add it */
        long int curr_block = free_index_ptr;
        Block block;
        while(curr_block != -1) {
            read_block(&block, curr_block);
            if(block.num_records != BLOCK_SIZE) {
                /* Add the record to the block */
                add_record(&block, key, data);
                write_block(&block, curr_block);
                break;
            }
            curr_block = block.next_block;
        }
        if(curr_block == -1) {
            /* The record must be added to a new block */
            curr_block = get_free_block_ptr();
            init_block(&block);
            add_record(&block, key, data);
            write_block(&block, curr_block);
            /* Add the block to the end of the linked list */
            Block last_block;
            read_block(&last_block, free_index_ptr);
            while(last_block.next_block != -1) {
                read_block(&last_block, last_block.next_block);
            }
            last_block.next_block = curr_block;
            write_block(&last_block, free_index_ptr);
        }
        /* Add the block to the buffer */
        if(buf->num_blocks == MAX_MEM_BLOCKS) {
            buf->num_blocks = 1;
        }
        else {
            buf->num_blocks++;
        }
        read_block(&buf->blocks[buf->num_blocks - 1], curr_block);
    }
    else {
        /* The record already exists so we must update it */
        strcpy((char *)(&buf->blocks[0].index + index->offset + sizeof(Index)), data);
    }
}

/* Delete a record */
void delete_record(Buffer *buf, char *key) {
    /* Find the block and index of the record */
    Block *block = NULL;
    int index = -1;
    for(int i = 0; i < buf->num_blocks; i++) {
        for(int j = 0; j < buf->blocks[i].num_records; j++) {
            if(strcmp(buf->blocks[i].index[j].key, key) == 0) {
                block = &buf->blocks[i];
                index = j;
                break;
            }
        }
        if(block != NULL) {
            break;
        }
    }
    if(block == NULL) {
        /* The record does not exist */
        return;
    }
    /* Shift all records after the index down one index */
    int num_records = block->num_records;
    for(int i = index; i < num_records - 1; i++) {
        block->index[i] = block->index[i + 1];
        strcpy((char *)(&block->index[i] + block->index[i].offset + sizeof(Index)), (char *)(&block->index[i + 1] + block->index[i + 1].offset + sizeof(Index)));
    }
    /* Clear the last index and data */
    memset(&block->index[num_records - 1], 0, sizeof(Index));
    memset((char *)(&block->index[num_records - 1] + block->index[num_records - 1].offset + sizeof(Index)), 0, MAX_RECORD_SIZE);
    /* Decrement the number of records */
    block->num_records--;
}

int main() {
    /* Open the file */
    open_file("data.bin", "wb+");
    /* Initialize the free block and index pointers */
    free_block_ptr = 0;
    free_index_ptr = sizeof(Block);
    /* Initialize the first block */
    Block first_block;
    init_block(&first_block);
    write_block(&first_block, free_index_ptr);
    /* Insert some records */
    Buffer buf;
    init_buffer(&buf);
    insert_record(&buf, "key1", "data1");
    insert_record(&buf, "key2", "data2");
    insert_record(&buf, "key3", "data3");
    /* Lookup a record */
    Index *index = find_record(&buf, "key2");
    printf("Lookup Result: %s\n", (char *)(&buf.blocks[0].index + index->offset + sizeof(Index)));
    /* Update a record */
    insert_record(&buf, "key2", "updated_data2");
    index = find_record(&buf, "key2");
    printf("Update Result: %s\n", (char *)(&buf.blocks[0].index + index->offset + sizeof(Index)));
    /* Delete a record */
    delete_record(&buf, "key3");
    index = find_record(&buf, "key3");
    if(index == NULL) {
        printf("Delete Successful\n");
    }
    /* Close the file */
    close_file();
    return 0;
}