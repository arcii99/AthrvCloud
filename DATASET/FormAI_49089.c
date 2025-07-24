//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *filePtr, *backupPtr; //pointer variables for the original file and backup file
    char fileName[20], backupName[20], buffer[100]; //character arrays for file names and buffer to store the data
    int fileLength; //integer variable to store the length of the file

    printf("Enter the name of the file to backup: ");
    scanf("%s", fileName);

    printf("Enter the name of the backup file: ");
    scanf("%s", backupName);

    filePtr = fopen(fileName, "r"); //open the original file in read mode

    if(filePtr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    backupPtr = fopen(backupName, "w"); //open the backup file in write mode

    if(backupPtr == NULL)
    {
        printf("Error creating backup file!");
        exit(1);
    }

    fseek(filePtr, 0L, SEEK_END); //move the file pointer to the end of the file
    fileLength = ftell(filePtr); //get the length of the file in bytes
    rewind(filePtr); //move the file pointer back to the beginning of the file

    fread(buffer, fileLength, 1, filePtr); //read the contents of the file into the buffer

    fwrite(buffer, fileLength, 1, backupPtr); //write the contents of the buffer to the backup file

    fclose(filePtr); //close the original file
    fclose(backupPtr); //close the backup file

    printf("Backup successfull!");

    return 0;
}