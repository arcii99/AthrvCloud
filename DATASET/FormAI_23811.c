//FormAI DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int size;
    char type[10];
} File;

int main() {
    FILE *fp;
    File file;
    char filename[50];
    int num_files = 0;

    // Ask user for input filename
    printf("Enter input filename: ");
    scanf("%s", filename);

    // Open input file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read number of files
    fread(&num_files, sizeof(int), 1, fp);
    printf("Number of files: %d\n", num_files);

    // Read each file data
    for (int i = 0; i < num_files; i++) {
        fread(&file, sizeof(File), 1, fp);
        printf("File %d:\n", i+1);
        printf("Name: %s\n", file.name);
        printf("Size: %d bytes\n", file.size);
        printf("Type: %s\n", file.type);
        printf("\n");
    }

    fclose(fp);
    return 0;
}