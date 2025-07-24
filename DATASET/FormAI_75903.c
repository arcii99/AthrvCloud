//FormAI DATASET v1.0 Category: File system simulation ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BLOCK_SIZE 512
#define BLOCK_COUNT 1024
#define FILENAME_LENGTH 20

typedef struct{
    int address;
    int size;
}table_entry;

typedef struct{
    char name[FILENAME_LENGTH];
    int block_address;
    int size;
}file_entry;

int memory[BLOCK_SIZE*BLOCK_COUNT];
table_entry table[BLOCK_COUNT];
file_entry file_table[BLOCK_COUNT];
int cur_index = 0;

void init(){
    table_entry empty;
    empty.address = 0;
    empty.size = BLOCK_COUNT;
    for(int i=0;i<BLOCK_COUNT;i++){
        table[i] = empty;
    }
    file_entry dummy;
    memset(dummy.name, 0, FILENAME_LENGTH);
    dummy.block_address = -1;
    dummy.size = -1;
    for(int i=0;i<BLOCK_COUNT;i++){
        file_table[i] = dummy;
    }
}

int allocate(int size){
    if(cur_index>=BLOCK_COUNT){
        return -1;
    }
    int start_index = -1, count = 0;
    for(int i=0;i<BLOCK_COUNT;i++){
        if(table[i].address==-1){
            count++;
            if(start_index==-1){
                start_index = i;
            }
        }
        else{
            count = 0;
            start_index = -1;
        }
        if(count==size){
            table_entry entry;
            entry.address = start_index;
            entry.size = size;
            for(int j=start_index;j<start_index+size;j++){
                table[j] = entry;
            }
            cur_index += size;
            return start_index;
        }
    }
    return -1;
}

void release(int start_index, int size){
    table_entry empty;
    empty.address = -1;
    empty.size = -1;
    for(int i=start_index;i<start_index+size;i++){
        table[i] = empty;
    }
    cur_index -= size;
}

int create_file(char* name, int size){
    int start_index = allocate(size);
    if(start_index==-1){
        printf("Error: Unable to create file.\n");
        return -1;
    }
    for(int i=0;i<BLOCK_COUNT;i++){
        if(strcmp(file_table[i].name, name)==0){
            printf("Error: File already exists.\n");
            release(start_index, size);
            return -1;
        }
    }
    for(int i=0;i<BLOCK_COUNT;i++){
        if(file_table[i].block_address==-1){
            file_table[i].block_address = start_index;
            file_table[i].size = size;
            strcpy(file_table[i].name, name);
            printf("File created successfully.\n");
            return i;
        }
    }
    return -1;
}

void delete_file(char* name){
    int index = -1;
    for(int i=0;i<BLOCK_COUNT;i++){
        if(strcmp(file_table[i].name, name)==0){
            index = i;
            break;
        }
    }
    if(index==-1){
        printf("Error: File does not exist.\n");
        return;
    }
    release(file_table[index].block_address, file_table[index].size);
    file_table[index].block_address = -1;
    file_table[index].size = -1;
    memset(file_table[index].name, 0, FILENAME_LENGTH);
    printf("File deleted successfully.\n");
}

int main(){
    init();
    int file_index = create_file("example.txt", 10);
    if(file_index!=-1){
        printf("File created: %s\n", file_table[file_index].name);
        printf("Block address: %d\n", file_table[file_index].block_address);
        printf("Size: %d\n", file_table[file_index].size);
    }
    else{
        printf("Error: Unable to create file.\n");
    }
    delete_file("example.txt");
    return 0;
}