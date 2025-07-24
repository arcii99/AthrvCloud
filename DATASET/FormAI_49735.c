//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    char filename[30], content[50];
    
    printf("Please enter the name of the file you wish to create: ");
    scanf("%s", filename);
    
    fp = fopen(filename, "w+");
    
    if(fp == NULL)
    {
        printf("Error: Unable to open file.");
        exit(1);
    }
    
    printf("\nFile created successfully!");
    printf("\nPlease enter some text to write in the file (maximum 50 characters): ");
    scanf("%s", content);
    
    fputs(content, fp);
    
    printf("\nText written successfully!");
    
    rewind(fp);
    
    char read[50];
    fgets(read, 50, fp);
    
    printf("\nThe content of the file is: %s", read);

    fclose(fp);

    return 0;
}