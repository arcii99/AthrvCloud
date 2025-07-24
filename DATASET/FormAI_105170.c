//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 1024
#define MAX_BLOCKS 4096

typedef struct{
    char filename[100];
    int start_block;
    int num_blocks;
}file_map;

int free_blocks[MAX_BLOCKS];
file_map dir[MAX_BLOCKS];
int total_blocks = MAX_BLOCKS;
int num_free_blocks = MAX_BLOCKS;

int get_free_block(){
    for(int i=0;i<total_blocks;i++){
        if(free_blocks[i]==0){
            free_blocks[i] = 1;
            num_free_blocks--;
            return i;
        }
    }
    return -1;
}

void release_blocks(int start_block, int num_blocks){
    for(int i=start_block;i<start_block+num_blocks;i++){
        free_blocks[i] = 0;
        num_free_blocks++;
    }
}

void init_file_system(){
    memset(free_blocks, 0, sizeof(free_blocks));
    for(int i=0;i<total_blocks;i++){
        dir[i].filename[0] = '\0';
        dir[i].start_block = -1;
        dir[i].num_blocks = 0;
    }
}

void format_file_system(){
    init_file_system();
    num_free_blocks = total_blocks;
    for(int i=0;i<total_blocks;i++){
        free_blocks[i] = 0;
    }
}

void create_file(char* filename, int num_blocks){
    if(num_blocks > num_free_blocks){
        printf("Not enough space.\n");
        return;
    }
    int start_block = get_free_block();
    if(start_block == -1){
        printf("Not enough space.\n");
        return;
    }
    strcpy(dir[start_block].filename, filename);
    dir[start_block].start_block = start_block;
    dir[start_block].num_blocks = num_blocks;
    for(int i=start_block+1;i<start_block+num_blocks;i++){
        int block = get_free_block();
        if(block == -1){
            release_blocks(start_block, i-start_block);
            printf("Not enough space.\n");
            return;
        }
        else{
            dir[block].filename[0] = '#';
            dir[block].start_block = start_block;
            dir[block].num_blocks = num_blocks;
        }
    }
    printf("File created.\n");
}

void delete_file(char* filename){
    int deleted = 0;
    for(int i=0;i<total_blocks;i++){
        if(strcmp(dir[i].filename,filename)==0){
            release_blocks(i,dir[i].num_blocks);
            dir[i].filename[0] = '\0';
            dir[i].start_block = -1;
            dir[i].num_blocks = 0;
            deleted = 1;
        }
    }
    if(deleted == 0){
        printf("Could not find the file.\n");
    }
    else{
        printf("File deleted.\n");
    }
}

void display_file_list(){
    printf("Filename\tStart Block\t#Blocks\n");
    for(int i=0;i<total_blocks;i++){
        if(dir[i].filename[0]!='\0' && dir[i].filename[0] != '#'){
            printf("%s\t\t%d\t\t%d\n",dir[i].filename,dir[i].start_block,dir[i].num_blocks);
        }
    }
}

int main(){
    format_file_system();
    create_file("file1.txt",5);
    create_file("file2.txt",2);
    create_file("file3.txt",4);
    display_file_list();
    delete_file("file2.txt");
    display_file_list();
    create_file("file4.txt",3);
    create_file("file5.txt",2);
    return 0;
}