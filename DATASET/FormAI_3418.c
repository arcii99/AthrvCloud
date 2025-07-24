//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char file[100];
    char virus[] = "malware";
    int virus_size = strlen(virus);
    int i,j;
    printf("Enter file name: "); //ask user for input
    gets(file); 
    FILE *fp = fopen(file, "rb"); //open file in binary mode
    if(fp == NULL) 
    {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END); //go to end of file
    int size = ftell(fp); //get size of file
    fseek(fp, 0, SEEK_SET); //go back to start of file
    char *buffer = (char*)malloc(size); //allocate memory of size of file
    if(buffer == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    fread(buffer, size, 1, fp); //read file into buffer
    fclose(fp); //close the file
    for(i=0; i<size-virus_size; i++) //loop through buffer
    {
        for(j=0; j<virus_size; j++) //loop through virus string
        {
            if(buffer[i+j] != virus[j]) //if characters don't match
                break; //exit inner loop
        }
        if(j == virus_size) //if inner loop completed without breaking early
        {
            printf("Virus found in file\n");
            exit(0); //exit program
        }
    }
    printf("File is clean of viruses\n"); //if loop completed without finding virus
    return 0; //exit program
}