//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000   //Max file size set to 1 Mb

int main()
{
    char file_name[100];
    char virus_signature[100] = "bad_code";   //Virus signature, can be changed as needed
    char buffer[MAX_FILE_SIZE];      //Buffer to store file contents

    printf("Enter the name of the file to scan: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "rb");    //Open file in binary mode

    if(file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    //Read file contents to buffer
    size_t bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);

    //Check if file is too big
    if(bytes_read >= MAX_FILE_SIZE)
    {
        printf("File too big to scan!\n");
        return 1;
    }

    //Scan for virus signature in file contents
    if(strstr(buffer, virus_signature) != NULL)
    {
        printf("File contains virus!\n");
    }
    else
    {
        printf("File is clean!\n");
    }

    return 0;
}