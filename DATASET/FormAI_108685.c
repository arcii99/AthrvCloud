//FormAI DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 1024

typedef struct file_table{
    char filename[15];
    int block_index[MAX_BLOCKS];
    int size;
    int num_blocks;
} file_table;

typedef struct file_system{
    char blocks[MAX_BLOCKS][BLOCK_SIZE];
    int free_blocks[MAX_BLOCKS];
    int num_free_blocks;
    file_table ft[MAX_BLOCKS];
    int num_files;
} file_system;

int create_file(file_system *fs, char *filename){
    if(fs->num_files >= MAX_BLOCKS){
        printf("Error: Maximum number of files reached.\n");
        return -1;
    }
    if(strlen(filename) > 15){
        printf("Error: Filename too long.\n");
        return -1;
    }
    for(int i = 0; i < fs->num_files; i++){
        if(strcmp(filename, fs->ft[i].filename) == 0){
            printf("Error: File already exists.\n");
            return -1;
        }
    }
    int block_index = fs->free_blocks[0];
    fs->free_blocks[0] = -1;
    fs->num_free_blocks--;
    for(int i = 1; i < fs->num_free_blocks; i++){
        fs->free_blocks[i - 1] = fs->free_blocks[i];
    }
    fs->free_blocks[fs->num_free_blocks - 1] = -1;
    fs->ft[fs->num_files].block_index[0] = block_index;
    fs->num_files++;
    return 0;
}

void delete_file(file_system *fs, char *filename){
    for(int i = 0; i < fs->num_files; i++){
        if(strcmp(filename, fs->ft[i].filename) == 0){
            for(int j = 0; j < fs->ft[i].num_blocks; j++){
                fs->blocks[fs->ft[i].block_index[j]][0] = '\0';
                fs->free_blocks[fs->num_free_blocks] = fs->ft[i].block_index[j];
                fs->num_free_blocks++;
                fs->ft[i].block_index[j] = -1;
            }
            for(int j = i; j < fs->num_files - 1; j++){
                fs->ft[j] = fs->ft[j + 1];
            }
            fs->num_files--;
            return;
        }
    }
    printf("Error: File not found.\n");
}

int write_to_file(file_system *fs, char *filename, char *data){
    for(int i = 0; i < fs->num_files; i++){
        if(strcmp(filename, fs->ft[i].filename) == 0){
            int block_index = fs->ft[i].block_index[fs->ft[i].num_blocks - 1];
            int block_offset = fs->ft[i].size % BLOCK_SIZE;
            if(block_offset + strlen(data) > BLOCK_SIZE){
                if(fs->num_free_blocks == 0){
                    printf("Error: Not enough space.\n");
                    return -1;
                }
                block_index = fs->free_blocks[0];
                fs->free_blocks[0] = -1;
                fs->num_free_blocks--;
                for(int j = 1; j < fs->num_free_blocks; j++){
                    fs->free_blocks[j - 1] = fs->free_blocks[j];
                }
                fs->free_blocks[fs->num_free_blocks] = -1;
                fs->ft[i].block_index[fs->ft[i].num_blocks] = block_index;
                fs->ft[i].num_blocks++;
                block_offset = 0;
            }
            strncpy(fs->blocks[block_index] + block_offset, data, strlen(data));
            fs->ft[i].size += strlen(data);
            return 0;
        }
    }
    printf("Error: File not found.\n");
    return -1;
}

void read_from_file(file_system *fs, char *filename){
    for(int i = 0; i < fs->num_files; i++){
        if(strcmp(filename, fs->ft[i].filename) == 0){
            for(int j = 0; j < fs->ft[i].num_blocks; j++){
                printf("%s", fs->blocks[fs->ft[i].block_index[j]]);
            }
            printf("\n");
            return;
        }
    }
    printf("Error: File not found.\n");
}

int main(){
    file_system fs;
    for(int i = 0; i < MAX_BLOCKS; i++){
        fs.free_blocks[i] = i;
        fs.blocks[i][0] = '\0';
    }
    fs.num_free_blocks = MAX_BLOCKS;
    fs.num_files = 0;
    create_file(&fs, "file1");
    create_file(&fs, "file2");
    write_to_file(&fs, "file1", "This is file 1\n");
    write_to_file(&fs, "file1", "It contains some data.\n");
    write_to_file(&fs, "file2", "This is file 2\n");
    write_to_file(&fs, "file2", "It contains some different data.\n");
    read_from_file(&fs, "file1");
    read_from_file(&fs, "file2");
    delete_file(&fs, "file1");
    delete_file(&fs, "file3");
    create_file(&fs, "file3");
    write_to_file(&fs, "file3", "This is file 3\n");
    write_to_file(&fs, "file3", "It contains even more data.\n");
    read_from_file(&fs, "file3");
    return 0;
}