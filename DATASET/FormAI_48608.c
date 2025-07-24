//FormAI DATASET v1.0 Category: File system simulation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100000
// defining the maximum size of the file system
struct inode{
    char filename[50];
    int file_size;
    int block_num;
    int block[10];
};
// defining inode struct datatype
struct super_block{
    int block_size;
    int total_blocks;
    float available_blocks;
};
// defining superblock struct datatype
struct directory{
    char dir_name[50];
    int file_count;
    struct inode files[50];
};
// defining directory struct datatype
struct block{
    char data[1024];
};
// defining file block struct datatype
int main(){
    int i,j,k;
    int flag=0;
    struct super_block sb;
    // creating the superblock
    sb.block_size=1024;
    sb.total_blocks=MAXSIZE/sb.block_size;
    sb.available_blocks=sb.total_blocks;
    int blocks[sb.total_blocks];
    for(i=0; i<sb.total_blocks; i++){
        blocks[i]=0;
    }
    // creating a block array with initial notation of zeros
    struct directory root;
    // creating the root directory
    printf("Enter the name of root directory: ");
    fflush(stdin);
    scanf("%[^\n]",root.dir_name);
    root.file_count=0;
    // accepting input from user for root directory name and initializing file count to zero
    for(i=0; i<sb.total_blocks; i++){
        blocks[i]=0;
    }
    printf("\n\n");
    while(1){
        // simulating the file system using a while loop
        printf("\nEnter\n1 to create new file\n2 to delete a file\n3 to view the contents of a file\n4 to see root directory\n5 to exit\n\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                // creating new file in the file system
                if(sb.available_blocks==0){
                    printf("\nFile system is full!! Cannot add new file.\n");
                    break;
                }
                else{
                    struct inode new_file;
                    printf("\nEnter file name: ");
                    fflush(stdin);
                    scanf("%[^\n]",new_file.filename);
                    printf("Enter file size: ");
                    scanf("%d",&new_file.file_size);
                    if(new_file.file_size%sb.block_size==0){
                        new_file.block_num=new_file.file_size/sb.block_size;
                    }
                    else{
                        new_file.block_num=new_file.file_size/sb.block_size+1;
                    }
                    if(new_file.block_num>sb.available_blocks){
                        printf("\nCannot add file! Not enough space available.\n");
                        break;
                    }
                    else{
                        int count=0;
                        for(i=0; i<sb.total_blocks; i++){
                            if(blocks[i]==0){
                                new_file.block[count]=i;
                                count++;
                                if(count==new_file.block_num){
                                    break;
                                }
                            }
                        }
                        printf("\nFile created successfully!!\n\n");
                        root.files[root.file_count]=new_file;
                        root.file_count++;
                        sb.available_blocks=sb.available_blocks - new_file.block_num;
                        break;
                    }
                }
            }
            case 2:{
                // deleting a file from the file system
                if(root.file_count==0){
                    printf("\nNo files found in directory.\n");
                    break;
                }
                else{
                    char file_name[50];
                    printf("\nEnter the name of file to be deleted: ");
                    fflush(stdin);
                    scanf("%[^\n]",file_name);
                    for(i=0; i<root.file_count; i++){
                        if(strcmp(file_name,root.files[i].filename)==0){
                            for(j=0; j<root.files[i].block_num; j++){
                                blocks[root.files[i].block[j]]=0;
                            }
                            root.files[i]=root.files[root.file_count-1];
                            root.file_count--;
                            sb.available_blocks=sb.available_blocks + root.files[i].block_num;
                            printf("\nFile deletion successful!!\n\n");
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        printf("\nNo such file found in directory.\n\n");
                    }
                    break;
                }
            }
            case 3:{
                // displaying contents of a file
                char read_file[50];
                printf("\nEnter the file name to be read: ");
                fflush(stdin);
                scanf("%[^\n]",read_file);
                for(i=0; i<root.file_count; i++){
                    if(strcmp(read_file,root.files[i].filename)==0){
                        printf("\nContents of %s are:\n",read_file);
                        for(j=0; j<root.files[i].block_num; j++){
                            struct block *file_block;
                            file_block=(struct block *)malloc(sizeof(struct block));
                            int block_number=root.files[i].block[j];
                            FILE *fp;
                            fp=fopen("root","rb");
                            fseek(fp, block_number*sb.block_size, SEEK_SET);
                            fread(file_block, sb.block_size, 1, fp);
                            printf("%s\n",file_block->data);
                            fclose(fp);
                        }
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("\nNo such file found in directory.\n\n");
                }
                break;
            }
            case 4:{
                // displaying root directory
                printf("\nRoot directory name: %s\n\n",root.dir_name);
                printf("\n %s has following files:\n",root.dir_name);
                for(i=0; i<root.file_count; i++){
                    printf("\n%d. %s\t Size: %d\t Number of blocks used: %d\n\n",i+1,root.files[i].filename,root.files[i].file_size,root.files[i].block_num);
                }
                break;
            }
            case 5:{
                // exiting the program
                printf("\nExiting program...\n");
                exit(0);
                break;
            }
            default:{
                printf("\nInvalid input!! Please try again.\n");
                break;
            }
        }
    }
    return 0;
}