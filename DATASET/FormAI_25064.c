//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 100 //maximum files in the system
#define MAX_NAME_LENGTH 20 //maximum length of name of file

//structure for keeping file information
typedef struct{
    char name[MAX_NAME_LENGTH];
    int size;
} File;

//structure for keeping directory information
typedef struct{
    char name[MAX_NAME_LENGTH];
    int num_files;
    File files[MAX_FILES];
} Directory;

//function to create a new file
void create_file(Directory* dir){
    if(dir->num_files >= MAX_FILES){
        printf("Maximum number of files reached!\n");
        return;
    }

    printf("Enter name of file: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for(int i=0;i<dir->num_files;i++){
        if(strcmp(dir->files[i].name, name)==0){
            printf("A file with this name already exists!\n");
            return;
        }
    }

    printf("Enter size of file: ");
    int size;
    scanf("%d", &size);

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    dir->files[dir->num_files] = new_file;
    dir->num_files++;

    printf("File created successfully!\n");
}

//function to delete a file
void delete_file(Directory* dir){
    if(dir->num_files == 0){
        printf("No files to delete!\n");
        return;
    }

    printf("Enter name of file to be deleted: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for(int i=0;i<dir->num_files;i++){
        if(strcmp(dir->files[i].name, name)==0){
            //file found, delete it
            for(int j=i;j<dir->num_files-1;j++){
                dir->files[j] = dir->files[j+1];
            }
            dir->num_files--;
            printf("File deleted successfully!\n");
            return;
        }
    }

    printf("File not found!\n");
}

int main(){
    Directory dir;
    strcpy(dir.name, "Main");
    dir.num_files = 0;

    while(1){
        printf("\nMenu:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_file(&dir);
                break;
            case 2:
                delete_file(&dir);
                break;
            case 3:
                printf("Files:\n");
                if(dir.num_files == 0){
                    printf("No files in directory.\n");
                }
                else{
                    for(int i=0;i<dir.num_files;i++){
                        printf("%d. %s (%d bytes)\n", i+1, dir.files[i].name, dir.files[i].size);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}