//FormAI DATASET v1.0 Category: File handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

int main()
{
    FILE *fp;
    char str[MAX_SIZE];

    /* Opening file in write mode */
    fp = fopen("file_handling_example.txt","w");
    
    /* Writing content to the file */
    fprintf(fp, "This is a file handling example program\n");
    fprintf(fp, "where we demonstrate how to write to a file\n");
    fprintf(fp, "and how to read from a file.\n");

    /* Closing file after writing */
    fclose(fp);

    /* Opening file in read mode */
    fp = fopen("file_handling_example.txt", "r");

    /* Checking if file exists or not */
    if (fp == NULL) {
        printf("File does not exist!");
        exit(1);
    }

    /* Reading content from the file */
    while (fgets(str, MAX_SIZE, fp) != NULL)
        printf("%s", str);

    /* Closing file after reading */
    fclose(fp);
    return 0;
}