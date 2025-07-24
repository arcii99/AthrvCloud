//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILE_SIZE 1024

struct File
{
    char name[20];
    char content[FILE_SIZE];
    int size;
    int isOpen;
};

struct Directory
{
    char name[20];
    struct File files[MAX_FILES];
    int numberOfFiles;
};

struct Directory root;

void initializeFileSystem()
{
    strcpy(root.name, "root");
    root.numberOfFiles = 0;
}

void listFiles(struct Directory dir)
{
    printf("\nFiles in directory '%s':\n", dir.name);
    if (dir.numberOfFiles == 0)
    {
        printf("No Files\n");
    }
    else
    {
        for (int i = 0; i < dir.numberOfFiles; ++i)
        {
            printf("%s\n", dir.files[i].name);
        }
    }
}

void createFile(char name[], struct Directory *dir)
{
    if (dir->numberOfFiles >= MAX_FILES)
    {
        printf("Cannot create file. Maximum number of files reached.\n");
        return;
    }

    for (int i = 0; i < dir->numberOfFiles; ++i)
    {
        if (strcmp(dir->files[i].name, name) == 0)
        {
            printf("File '%s' already exists.\n", name);
            return;
        }
    }

    struct File newFile;
    strcpy(newFile.name, name);
    newFile.size = 0;
    newFile.isOpen = 0;
    dir->files[dir->numberOfFiles] = newFile;
    dir->numberOfFiles++;

    printf("File '%s' created.\n", name);
}

void readFile(char name[], struct Directory *dir)
{
    for (int i = 0; i < dir->numberOfFiles; ++i)
    {
        if (strcmp(dir->files[i].name, name) == 0)
        {
            if (dir->files[i].isOpen == 1)
            {
                printf("File '%s' is already open.\n", name);
                return;
            }

            printf("\nContents of file '%s':\n", name);
            printf("%s\n", dir->files[i].content);
            return;
        }
    }

    printf("File '%s' not found.\n", name);
}

void writeFile(char name[], char content[], struct Directory *dir)
{
    for (int i = 0; i < dir->numberOfFiles; ++i)
    {
        if (strcmp(dir->files[i].name, name) == 0)
        {
            if (dir->files[i].isOpen == 1)
            {
                printf("File '%s' is already open.\n", name);
                return;
            }

            strcpy(dir->files[i].content, content);
            dir->files[i].size = strlen(content);
            printf("File '%s' updated.\n", name);
            return;
        }
    }

    printf("File '%s' not found.\n", name);
}

void openFile(char name[], struct Directory *dir)
{
    for (int i = 0; i < dir->numberOfFiles; ++i)
    {
        if (strcmp(dir->files[i].name, name) == 0)
        {
            if (dir->files[i].isOpen == 1)
            {
                printf("File '%s' is already open.\n", name);
                return;
            }

            dir->files[i].isOpen = 1;
            printf("File '%s' opened.\n", name);
            return;
        }
    }

    printf("File '%s' not found.\n", name);
}

void closeFile(char name[], struct Directory *dir)
{
    for (int i = 0; i < dir->numberOfFiles; ++i)
    {
        if (strcmp(dir->files[i].name, name) == 0)
        {
            if (dir->files[i].isOpen == 0)
            {
                printf("File '%s' is already closed.\n", name);
                return;
            }

            dir->files[i].isOpen = 0;
            printf("File '%s' closed.\n", name);
            return;
        }
    }

    printf("File '%s' not found.\n", name);
}

int main()
{
    initializeFileSystem();
    createFile("file1.txt", &root);
    createFile("file2.txt", &root);
    createFile("file3.txt", &root);
    listFiles(root);
    openFile("file1.txt", &root);
    readFile("file1.txt", &root);
    writeFile("file1.txt", "This is the new content of file1.txt", &root);
    readFile("file1.txt", &root);
    closeFile("file1.txt", &root);

    return 0;
}