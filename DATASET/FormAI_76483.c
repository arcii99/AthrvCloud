//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

#define MAX_FILES 100
#define BLOCK_SIZE 512

struct file{
    char name[20];
    int start_block;
    int size;
};

struct block{
    int next_block;
    char data[BLOCK_SIZE];
};

struct file_system{
    int free_block;
    struct block blocks[1000];
    struct file files[MAX_FILES];
    int file_count;
};

struct file_system fs;

//function to initialize the file system
void init_file_system(){
    fs.free_block = 0;
    fs.file_count = 0;
    for(int i=0;i<1000;i++){
        fs.blocks[i].next_block = -1;
        for(int j=0;j<BLOCK_SIZE;j++){
            fs.blocks[i].data[j] = '\0';
        }
    }
}

//function to allocate a new block
int allocate_block(){
    int block_num = fs.free_block;
    fs.free_block++;
    fs.blocks[block_num].next_block = -1;
    return block_num;
}

//function to create a new file
void create_file(char name[20]){
    int start_block = allocate_block();
    if(start_block == -1){
        printf("Error: Filesystem full");
        return;
    }
    int file_size;
    printf("Enter file size: ");
    scanf("%d",&file_size);
    int num_blocks = (file_size + BLOCK_SIZE - 1)/BLOCK_SIZE;
    fs.files[fs.file_count].start_block = start_block;
    fs.files[fs.file_count].size = file_size;
    for(int i=0;i<num_blocks;i++){
        int cur_block = allocate_block();
        if(cur_block == -1){
            printf("Error: Filesystem full");
            return;
        }
        fs.blocks[start_block].next_block = cur_block;
        start_block = cur_block;
    }
    fs.file_count++;
    printf("File created successfully\n");
}

//function to write to a file
void write_file(char name[20]){
    int file_found = 0, block_num;
    for(int i=0;i<fs.file_count;i++){
        if(strcmp(fs.files[i].name,name) == 0){
            file_found = 1;
            block_num = fs.files[i].start_block;
        }
    }
    if(file_found == 0){
        printf("Error: File not found\n");
        return;
    }
    int bytes_written = 0, cur_block = block_num;
    printf("Enter data to be written to file %s:\n",name);
    while(cur_block != -1){
        fgets(fs.blocks[cur_block].data,BLOCK_SIZE,stdin);
        bytes_written += strlen(fs.blocks[cur_block].data);
        cur_block = fs.blocks[cur_block].next_block;
        if(bytes_written >= fs.files[block_num].size){
            break;
        }
    }
    printf("Data written successfully\n");
}

//function to read from a file
void read_file(char name[20]){
    int file_found = 0, block_num;
    for(int i=0;i<fs.file_count;i++){
        if(strcmp(fs.files[i].name,name) == 0){
            file_found = 1;
            block_num = fs.files[i].start_block;
        }
    }
    if(file_found == 0){
        printf("Error: File not found\n");
        return;
    }
    int bytes_read = 0, cur_block = block_num;
    printf("Data in file %s:\n",name);
    while(cur_block != -1){
        printf("%s",fs.blocks[cur_block].data);
        bytes_read += strlen(fs.blocks[cur_block].data);
        cur_block = fs.blocks[cur_block].next_block;
        if(bytes_read >= fs.files[block_num].size){
            break;
        }
    }
}

int main(){
    int choice;
    char name[20];
    init_file_system();
    do{
        printf("\n--------------------------------\n");
        printf("File System Simulation\n");
        printf("--------------------------------\n");
        printf("1. Create file\n2. Write to file\n3. Read from file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter file name: ");
                    scanf("%s",name);
                    create_file(name);
                    break;
            case 2: printf("Enter file name: ");
                    scanf("%s",name);
                    write_file(name);
                    break;
            case 3: printf("Enter file name: ");
                    scanf("%s",name);
                    read_file(name);
                    break;
            case 4: printf("Exiting...\n");
                    exit(0);
            default: printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}