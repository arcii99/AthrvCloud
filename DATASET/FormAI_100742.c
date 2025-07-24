//FormAI DATASET v1.0 Category: File system simulation ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int fd; //file descriptor
    char name[20]; //file name
    int size; //file size
    char data[100]; //file contents
} File;

void init(File* files, int n)
{
    //initialize all files
    for(int i=0;i<n;i++)
    {
        files[i].fd = i+1; //file descriptor starts at 1
        sprintf(files[i].name, "file_%d",i);
        files[i].size = 0;
        memset(files[i].data, 0, sizeof(files[i].data));
    }
}

void list_files(File* files, int n)
{
    printf("\nFile system contents:\n");
    printf("fd\tname\tsize\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%s\t%d\n",files[i].fd,files[i].name,files[i].size);
    }
}

int find_file_by_name(File* files, int n, char* name)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(files[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int allocate_fd(File* files, int n)
{
    int fd = 0;
    for(int i=0;i<n;i++)
    {
        if(files[i].fd > fd)
        {
            fd = files[i].fd;
        }
    }
    return fd+1;
}

void create_file(File* files, int n, char* name)
{
    int i = find_file_by_name(files, n, name);
    if(i != -1)
    {
        printf("\nFile already exists!");
        return;
    }
    int fd = allocate_fd(files, n);
    files[n].fd = fd;
    strcpy(files[n].name, name);
    files[n].size = 0;
    memset(files[n].data, 0, sizeof(files[n].data));
    printf("\nCreated file with fd %d\n", fd);
}

void delete_file(File* files, int n, char* name)
{
    int i = find_file_by_name(files, n, name);
    if(i == -1)
    {
        printf("\nFile doesn't exist!");
        return;
    }
    files[i].fd = -1;
    printf("\nDeleted file %s\n", name);
}

void write_file(File* files, int n, char* name, char* data)
{
    int i = find_file_by_name(files, n, name);
    if(i == -1)
    {
        printf("\nFile doesn't exist!");
        return;
    }
    strcpy(files[i].data, data);
    files[i].size = strlen(data);
    printf("\nWrote %d bytes to file %s\n", files[i].size, files[i].name);
}

void read_file(File* files, int n, char* name)
{
    int i = find_file_by_name(files, n, name);
    if(i == -1)
    {
        printf("\nFile doesn't exist!");
        return;
    }
    printf("\nContents of file %s:\n", files[i].name);
    printf("%s\n", files[i].data);
}

int main()
{
    int choice;
    File files[10];
    init(files, 10);
    char name[20], data[100];
    do {
        printf("\nFile system simulation:\n");
        printf("1. List files\n");
        printf("2. Create file\n");
        printf("3. Delete file\n");
        printf("4. Write to file\n");
        printf("5. Read from file\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                list_files(files, 10);
                break;
            case 2:
                printf("\nEnter file name: ");
                scanf("%s", name);
                create_file(files, 10, name);
                break;
            case 3:
                printf("\nEnter file name: ");
                scanf("%s", name);
                delete_file(files, 10, name);
                break;
            case 4:
                printf("\nEnter file name: ");
                scanf("%s", name);
                printf("\nEnter data: ");
                scanf("%s", data);
                write_file(files, 10, name, data);
                break;
            case 5:
                printf("\nEnter file name: ");
                scanf("%s", name);
                read_file(files, 10, name);
                break;
            case 6:
                printf("\nExiting..\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 6);
    return 0;
}