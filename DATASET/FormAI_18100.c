//FormAI DATASET v1.0 Category: File Backup System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void backup (char* source, char* destination)
{
    int i, source_size = strlen(source), destination_size = strlen(destination);

    for(i = 0; i < source_size; i++)
    {
        destination[destination_size + i] = source[i];
    }
}

int main()
{
    char* source = "C:/Users/UserName/Documents/C Files";
    char* destination = "E:/Backup";
    char* backup_destination = (char*) malloc(sizeof(char) * (strlen(destination) + strlen(source) + 1));

    // Checking if backup_destination is allocated or not
    if(!backup_destination)
    {
        printf("Memory Allocation Error!");
        exit(1);
    }

    // Making backup destination by concatenating the source and destination.
    strcat(backup_destination, destination);
    backup(source, backup_destination);

    printf("Backup Successful. Files backed up from %s to %s", source, backup_destination);

    // Deallocating the memory
    free(backup_destination);
    return 0;
}