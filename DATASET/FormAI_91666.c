//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char file_name[100], path[100];
    printf("Enter the file name you want to scan (with full path):\n");
    fgets(file_name, 100, stdin);  // get file name with full path
    file_name[strcspn(file_name, "\n")] = 0;  // remove new line character from the end
    
    strcpy(path, file_name);  // duplicate file path 
    
    int i, len = strlen(path);
    char *extension = strrchr(path, '.');
    char *slash = strrchr(path, '/');
    char *backslash = strrchr(path, '\\');

    if(extension == NULL || (slash != NULL && extension < slash) || (backslash != NULL && extension < backslash))
    {
        printf("File extension not found. This doesn't appear to be a valid file.\n");
        exit(0);
    }
    
    printf("Scanning file for potential viruses...\n");
    
    char buffer[100];
    
    FILE *fp = fopen(file_name, "r");
    while(fgets(buffer, 100, fp))
    {
        if(strstr(buffer, "system(") != NULL || strstr(buffer, "rm -rf") || strstr(buffer, "chmod") ||
           strstr(buffer, "/bin/bash") || strstr(buffer, ".sh") || strstr(buffer, "sudo"))
        {
            printf("This file may contain malicious code! Virus detected!\n");
            fclose(fp);
            exit(0);
        }
    }
    
    printf("The file is clean. No virus detected.\n");
    
    fclose(fp);
    
    return 0;
}