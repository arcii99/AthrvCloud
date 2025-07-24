//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include<stdio.h>
#include<stdlib.h>

struct file{
    char name[10];
    int size;
};

struct directory{
    char name[10];
    struct file files[10];
    int fileCount;
};

struct fileSystem{
    struct directory directories[10];
    int dirCount;
};

void printFile(struct file f){
    printf("\n\t\t<-----File Details---->\n");
    printf("\t\tName: %s\n", f.name);
    printf("\t\tSize: %d KB\n", f.size);
}

void printDirectory(struct directory d){
    printf("\n\t<-----Directory Details---->\n");
    printf("\tName: %s\n", d.name);
    printf("\tNumber of Files: %d\n", d.fileCount);
    int i;
    for(i=0; i<d.fileCount; i++){
        printFile(d.files[i]);
    }
}

void printFileSystem(struct fileSystem fs){
    printf("<===== Welcome to File System =====>\n");
    printf("Number of Directories: %d\n", fs.dirCount);
    int i;
    for(i=0; i<fs.dirCount; i++){
        printDirectory(fs.directories[i]);
    }
    printf("<===== End of File System =======>\n");
}

int main(){
    struct fileSystem fs;
    fs.dirCount = 0;

    // Adding Directory 1
    struct directory dir1;
    strcpy(dir1.name, "Directory 1");
    dir1.fileCount = 2;

    struct file f1;
    strcpy(f1.name, "File 1");
    f1.size = 50;

    struct file f2;
    strcpy(f2.name, "File 2");
    f2.size = 85;

    dir1.files[0] = f1;
    dir1.files[1] = f2;

    fs.directories[0] = dir1;
    fs.dirCount++;

    // Adding Directory 2
    struct directory dir2;
    strcpy(dir2.name, "Directory 2");
    dir2.fileCount = 3;

    struct file f3;
    strcpy(f3.name, "File 3");
    f3.size = 20;

    struct file f4;
    strcpy(f4.name, "File 4");
    f4.size = 30;

    struct file f5;
    strcpy(f5.name, "File 5");
    f5.size = 10;

    dir2.files[0] = f3;
    dir2.files[1] = f4;
    dir2.files[2] = f5;

    fs.directories[1] = dir2;
    fs.dirCount++;

    // Printing File System Details
    printFileSystem(fs);

    return 0;
}