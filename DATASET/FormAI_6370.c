//FormAI DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[20], ch;
    int count = 0;
    
    printf("Enter the name of file: ");
    scanf("%s", filename);
    
    // open the file
    fp = fopen(filename, "r");
    if(fp == NULL) // if file not found, exit the program
    {
        printf("File not found!\n");
        exit(0);
    }
    
    // read the file character by character and count the number of lines
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            count++;
    }
    
    // close the file
    fclose(fp);
    
    printf("The file %s has %d lines.\n", filename, count);
    
    return 0;
}