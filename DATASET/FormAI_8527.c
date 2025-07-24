//FormAI DATASET v1.0 Category: System administration ; Style: inquisitive
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

char message[100];

int main()
{
    // Open the file for writing permission only
    int file_des = open("example.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if(file_des == -1)
    {
        printf("Error opening file\n");
        return 1;
    }
    
    // Set file permission to 640
    int permissions = fchmod(file_des, S_IRUSR | S_IWUSR | S_IRGRP);
    if(permissions == -1)
    {
        printf("Error setting permissions for file\n");
        return 1;
    }
    
    // Write a message to the file
    strcpy(message, "This is a message written to the example.txt file\n");
    int bytes_written = write(file_des, message, strlen(message));
    if(bytes_written == -1)
    {
        printf("Error writing to file\n");
        return 1;
    }
    
    // Close the file descriptor
    int close_status = close(file_des);
    if(close_status == -1)
    {
        printf("Error closing file\n");
        return 1;
    }
    
    printf("Successfully wrote to file\n");
    
    return 0;
}