//FormAI DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int main(void)
{
    // Open file for writing
    FILE *fp = fopen("output.txt", "w");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    
    // Write some data to the file
    fprintf(fp, "Hello, world!\n");
    fputs("This is a test.\n", fp);
    
    // Close the file
    fclose(fp);
    
    // Open file for reading
    fp = fopen("output.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    
    // Read data from the file and print it to stdout
    char buffer[MAX_SIZE];
    while(fgets(buffer, MAX_SIZE, fp) != NULL)
    {
        printf("%s", buffer);
    }
    
    // Close the file and exit
    fclose(fp);
    return 0;
}