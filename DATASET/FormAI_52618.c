//FormAI DATASET v1.0 Category: Memory management ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); //seeding the random number generator with the current time
    int mem_size = 100; //total memory size
    int num_blocks = 5; //number of memory blocks
    int block_size[num_blocks]; //size of each memory block
    int* ptr[num_blocks]; //an array of pointers to each memory block
    
    //randomly allocating memory to each block
    for(int i=0; i<num_blocks; i++){
        block_size[i] = rand() % (mem_size / num_blocks) + 1; //generating a random block size between 1 and total memory size divided by number of blocks
        ptr[i] = (int*)malloc(block_size[i]); //allocating the memory block using malloc and storing the pointer to the block in the array of pointers
    }
    
    //printing the allocated memory blocks' sizes and addresses
    printf("Allocated Memory Blocks:\n");
    for(int i=0; i<num_blocks; i++){
        printf("Block %d: %d bytes, address: %p\n", i+1, block_size[i], ptr[i]);
    }
    
    //deallocating a random memory block
    int block_num = rand() % num_blocks + 1; //choosing a random block number to deallocate
    free(ptr[block_num-1]); //deallocating the memory block using free
    printf("Deallocated Block %d\n", block_num);
    
    //reallocating a memory block with a larger size
    block_num = rand() % num_blocks + 1; //choosing a random block number to reallocate
    int old_size = block_size[block_num-1]; //storing the old block size
    block_size[block_num-1] = rand() % (mem_size / num_blocks) + old_size; //generating a new block size that is larger than the old size
    ptr[block_num-1] = (int*)realloc(ptr[block_num-1], block_size[block_num-1]); //re-allocating the memory block with the new size using realloc
    printf("Reallocated Block %d: new size: %d bytes, new address: %p\n", block_num, block_size[block_num-1], ptr[block_num-1]);
    
    //deallocating all memory blocks
    for(int i=0; i<num_blocks; i++){
        free(ptr[i]); //deallocating each memory block using free
    }
    
    return 0;
}