//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 512
#define DISKSIZE 20971520

struct superblock {
    int total_blocks, free_blocks;
    char bitmap[DISKSIZE / BLOCKSIZE]; 
};

struct directory {
    char filename[16];
    int start_block;
    int size;
};

int file_count = 0;

int get_bit(char bitmap[], int block_number) {
    int byte_number = block_number / 8;
    int bit_number = 7 - (block_number % 8);
    char byte = bitmap[byte_number];
    return (byte >> bit_number) & 1;
}

void set_bit(char bitmap[], int block_number, int bit_value) {
    int byte_number = block_number / 8;
    int bit_number = 7 - (block_number % 8);
    char byte = bitmap[byte_number];
    
    if(bit_value == 1) {
        byte = byte | (1 << bit_number);
    } else {
        byte = byte & ~(1 << bit_number);
    }
    
    bitmap[byte_number] = byte;
}

int allocate_block(struct superblock *sb) {
    for(int i = 0; i < sb->total_blocks; i++) {
        if(get_bit(sb->bitmap, i) == 0) {
            set_bit(sb->bitmap, i, 1);
            sb->free_blocks--;
            
            return i;
        }
    }
    return -1; 
}

int deallocate_block(struct superblock *sb, int block_number) {
    if(get_bit(sb->bitmap, block_number) == 1) {
        set_bit(sb->bitmap, block_number, 0);
        sb->free_blocks++;
        
        return 1;
    }
    return 0;
}

void init_superblock(struct superblock *sb) {
    sb->total_blocks = DISKSIZE / BLOCKSIZE;
    sb->free_blocks = sb->total_blocks - 1;
    memset(sb->bitmap, 0, sizeof(sb->bitmap));
    
    for(int i = 0; i < sb->total_blocks; i++) {
        if(i == 0) {
            set_bit(sb->bitmap, i, 1);
            sb->free_blocks--;
        }
    }
}

int create_file(struct directory *dir, struct superblock *sb, char *filename, int size) {
    if(sb->free_blocks < (size / BLOCKSIZE) + 1) {
        printf("Not enough space.\n");
        return -2;
    }
    
    for(int i = 0; i < file_count; i++) {
        if(strcmp(dir[i].filename, filename) == 0) {
            printf("File already exists.\n");
            return -1;
        }
    }
    
    int start_block = allocate_block(sb);
    if(start_block == -1) {
        printf("Unable to allocate block.\n");
        return -3;
    }
    
    dir[file_count].start_block = start_block;
    dir[file_count].size = size;
    strcpy(dir[file_count].filename, filename);
    file_count++;
    
    int blocks_required = size / BLOCKSIZE;
    
    if(size % BLOCKSIZE != 0) {
        blocks_required++;
    }
    
    for(int i = 0; i < blocks_required; i++) {
        int block_number = allocate_block(sb);
        
        if(block_number == -1) {
            for(int j = 0; j < i; j++) {
                deallocate_block(sb, dir[file_count - 1].start_block + j);
            }
            
            file_count--;
            printf("Unable to allocate block.\n");
            return -3;
        }
    }
    
    return 1;
}

void print_directory(struct directory *dir) {
    printf("Directory\n");
    printf("-----------------\n");
    
    for(int i = 0; i < file_count; i++) {
        printf("%s (%d bytes) - block %d\n", dir[i].filename, dir[i].size, dir[i].start_block);
    }
    
    printf("\n");
}

int main() {
    struct superblock sb;
    struct directory dir[16];
    
    init_superblock(&sb);
    
    int result = create_file(dir, &sb, "file1.txt", 1025);
    if(result < 0) {
        printf("Error creating file.\n");
    }
    
    result = create_file(dir, &sb, "file2.txt", 4096);
    if(result < 0) {
        printf("Error creating file.\n");
    }
    
    result = create_file(dir, &sb, "file3.txt", 6000);
    if(result < 0) {
        printf("Error creating file.\n");
    }
    
    print_directory(dir);
    
    return 0;
}