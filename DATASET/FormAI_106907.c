//FormAI DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILESIZE 100

typedef struct File
{
    char filename[MAX_FILENAME_LENGTH + 1];
    int size;
    char data[MAX_FILESIZE + 1];
} File;

typedef struct FileSystem
{
    File files[MAX_FILESIZE];
    int fileCount;
    int maxSize;
} FileSystem;

FileSystem* createFileSystem(int maxSize)
{
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->maxSize = maxSize;
    fs->fileCount = 0;
    return fs;
}

void addFile(FileSystem* fs, char* filename, char* data)
{
    if(fs->fileCount >= fs->maxSize)
    {
        printf("File system is full, couldn't add %s\n", filename);
        return;
    }

    File newFile;
    strcpy(newFile.filename, filename);
    newFile.size = strlen(data);
    strcpy(newFile.data, data);
    fs->files[fs->fileCount++] = newFile;

    printf("Added file %s (%d bytes)\n", filename, newFile.size);
}

void deleteFile(FileSystem* fs, char* filename)
{
    for(int i = 0; i < fs->fileCount; i++)
    {
        if(strcmp(fs->files[i].filename, filename) == 0)
        {
            printf("Deleted file %s\n", filename);
            for(int j = i + 1; j < fs->fileCount; j++)
                fs->files[j - 1] = fs->files[j];
            fs->fileCount--;
            return;
        }
    }
    printf("File %s not found\n", filename);
}

void listFiles(FileSystem* fs)
{
    printf("Files in file system:\n");
    for(int i = 0; i < fs->fileCount; i++)
        printf("- %s (%d bytes)\n", fs->files[i].filename, fs->files[i].size);
}

int main()
{
    FileSystem* fs = createFileSystem(5);

    addFile(fs, "file1.txt", "This is file 1");
    addFile(fs, "file2.txt", "This is file 2");
    addFile(fs, "file3.txt", "This is file 3");
    addFile(fs, "file4.txt", "This is file 4");
    addFile(fs, "file5.txt", "This is file 5");
    addFile(fs, "file6.txt", "This is file 6"); // Will not be added as the file system is full

    listFiles(fs);

    deleteFile(fs, "file3.txt");

    listFiles(fs);

    deleteFile(fs, "file7.txt"); // Not found

    free(fs);

    return 0;
}