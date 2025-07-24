//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

#define BLOCK_SIZE 512

typedef struct{
    int file_id;
    char* file_name;
    int file_size;
    int start_block;
    int end_block;
}file;

typedef struct node{
    int block_num;
    struct node* next;
}node;

typedef struct{
    int block_num;
    int is_allocated;
    node* file_list;
}block;

block blocks[1024];
file files[1024];

int total_blocks = 1024;
int free_blocks = 1024;

void init_block_arr(){
    for(int i=0; i<total_blocks; i++){
        blocks[i].block_num = i;
        blocks[i].is_allocated = 0;
        blocks[i].file_list = NULL;
    }
}

int allocate_block(){
    if(free_blocks == 0){
        printf("Unable to allocate block. Memory Full\n");
        return -1;
    }

    for(int i=0; i<total_blocks; i++){
        if(blocks[i].is_allocated == 0){
            node* head = malloc(sizeof(node));
            head->block_num = i;
            head->next = NULL;

            blocks[i].file_list = head;
            blocks[i].is_allocated = 1;
            free_blocks--;
            return i;
        }
    }

    return -1;
}

void deallocate_block(int block_num){
    if(block_num>=total_blocks){
        printf("Invalid block number\n");
        return;
    }

    if(blocks[block_num].is_allocated == 0){
        printf("Block already deallocated\n");
        return;
    }

    blocks[block_num].is_allocated = 0;
    free_blocks++;

    node* curr = blocks[block_num].file_list;
    node* prev = NULL;

    while(curr!=NULL){
        if(prev==NULL){
            blocks[block_num].file_list = blocks[block_num].file_list->next;
            free(curr);
            curr = blocks[block_num].file_list;
        }
        else{
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
    }

    printf("Block deallocated successfully\n");
}

void create_file(){
    if(free_blocks == 0){
        printf("Unable to create file. Memory Full\n");
        return;
    }

    file new_file;
    new_file.file_id = rand()%10000;
    new_file.file_name = malloc(sizeof(char)*50);
    new_file.file_size = rand()%1000;
    new_file.start_block = allocate_block();
    new_file.end_block = new_file.start_block;

    printf("Enter filename: ");
    scanf("%s", new_file.file_name);

    files[new_file.file_id] = new_file;
}

void write_to_file(){
    int file_id, block_num;
    char buf[BLOCK_SIZE];

    printf("Enter file id: ");
    scanf("%d", &file_id);

    if(file_id>1000){
        printf("Invalid file id\n");
        return;
    }

    if(files[file_id].file_size==0){
        printf("File does not exist\n");
        return;
    }

    printf("Enter block number to write to: ");
    scanf("%d", &block_num);

    if(block_num>=total_blocks){
        printf("Invalid block number\n");
        return;
    }

    if(blocks[block_num].is_allocated == 0){
        printf("Block not allocated to any file\n");
        return;
    }

    if(blocks[block_num].file_list->block_num != block_num){
        printf("Block not a part of file\n");
        return;
    }

    printf("Enter text to write: ");
    fflush(stdin);
    gets(buf);

    if(strlen(buf)>BLOCK_SIZE){
        printf("Text too long to fit in block\n");
        return;
    }

    printf("Writing to block number %d\n", block_num);

    // Writing to block
    FILE* fp = fopen("disk.txt", "r+");
    fseek(fp, block_num*BLOCK_SIZE, SEEK_SET);
    fwrite(buf, strlen(buf), 1, fp);
    fclose(fp);
}

void read_from_file(){
    int file_id, block_num;
    char buf[BLOCK_SIZE];

    printf("Enter file id: ");
    scanf("%d", &file_id);

    if(file_id>1000){
        printf("Invalid file id\n");
        return;
    }

    if(files[file_id].file_size==0){
        printf("File does not exist\n");
        return;
    }

    printf("Enter block number to read from: ");
    scanf("%d", &block_num);

    if(block_num>=total_blocks){
        printf("Invalid block number\n");
        return;
    }

    if(blocks[block_num].is_allocated == 0){
        printf("Block not allocated to any file\n");
        return;
    }

    if(blocks[block_num].file_list->block_num != block_num){
        printf("Block not a part of file\n");
        return;
    }

    // Reading from block
    FILE* fp = fopen("disk.txt", "r");
    fseek(fp, block_num*BLOCK_SIZE, SEEK_SET);
    fread(buf, BLOCK_SIZE, 1, fp);
    fclose(fp);

    printf("Data read from block number %d: %s\n", block_num, buf);
}

void delete_file(){
    int file_id;

    printf("Enter file id: ");
    scanf("%d", &file_id);

    if(file_id>1000){
        printf("Invalid file id\n");
        return;
    }

    if(files[file_id].file_size==0){
        printf("File does not exist\n");
        return;
    }

    // Deallocating blocks
    int curr_block = files[file_id].start_block;

    for(int i=0; i<files[file_id].file_size/BLOCK_SIZE; i++){
        deallocate_block(curr_block);
        curr_block = blocks[curr_block].file_list->next->block_num;
    }

    deallocate_block(curr_block);

    // Updating file arr
    files[file_id].file_id = -1;
    files[file_id].file_name = NULL;
    files[file_id].file_size = 0;
    files[file_id].start_block = -1;
    files[file_id].end_block = -1;

    printf("File deleted successfully\n");
}

void display_disk_state(){
    printf("Disk Information\n");
    printf("Total Blocks: %d\n", total_blocks);
    printf("Free Blocks: %d\n", free_blocks);

    for(int i=0; i<total_blocks; i++){
        if(blocks[i].is_allocated){
            printf("Block %d is allocated to file with id %d\n", blocks[i].block_num, blocks[i].file_list->block_num);
        }
    }
}

int main(){
    init_block_arr();

    while(1){
        int option;

        printf("Menu\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. Delete File\n");
        printf("5. Display Disk State\n");
        printf("6. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option){
            case 1: create_file();
                    break;
            case 2: write_to_file();
                    break;
            case 3: read_from_file();
                    break;
            case 4: delete_file();
                    break;
            case 5: display_disk_state();
                    break;
            case 6: exit(0);
                    break;
            default: printf("Invalid option\n");
        }
    }

    return 0;
}