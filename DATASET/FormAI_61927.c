//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Determine file size
    fseek(fp, 0L, SEEK_END); 
    long int filesize = ftell(fp); 
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory for file data
    char *filedata = (char*) malloc(filesize*sizeof(char));
    if (filedata == NULL) {
        printf("Error: Could not allocate memory\n");
        return 1;
    }

    // Read file data into memory
    fread(filedata, sizeof(char), filesize, fp);
    fclose(fp);

    // Create new file and write recovered data
    char newfilename[100];
    printf("Enter name for recovered file: ");
    scanf("%s", newfilename);
    FILE *newfp = fopen(newfilename, "wb");
    if (newfp == NULL) {
        printf("Error: Could not create file\n");
        free(filedata);
        return 1;
    }
    fwrite(filedata, sizeof(char), filesize, newfp);
    fclose(newfp);
    free(filedata);

    printf("Data recovered successfully!\n");
    return 0;
}