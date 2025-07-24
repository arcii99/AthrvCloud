//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[50];

    printf("Enter the filename to backup: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }

    // Determine the file size
    fseek(fp, 0L, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory for the buffer
    char *buffer = (char *) malloc(filesize);

    // Read the file contents into the buffer
    fread(buffer, filesize, 1, fp);

    // Close the input file
    fclose(fp);

    // Open the output file in write mode
    char backupname[50];
    strcpy(backupname, filename);
    strcat(backupname, ".bak");
    fp = fopen(backupname, "w");

    // Write the buffer to the output file
    fwrite(buffer, filesize, 1, fp);

    // Close the output file
    fclose(fp);

    // Free the memory used by the buffer
    free(buffer);

    printf("Backup complete!");
    return 0;
}