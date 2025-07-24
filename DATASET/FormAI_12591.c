//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 100 // maximum length of file name/path
#define BUFLEN 1024 // maximum buffer length

void backup(char* original_file, char* backup_file);

int main(){
    char original_file[MAXLEN], backup_file[MAXLEN];
    printf("Enter the name or path of the file to be backed up: ");
    scanf("%s", original_file);
    
    printf("Enter the name or path of the backup file: ");
    scanf("%s", backup_file);
    
    backup(original_file, backup_file);
    
    return 0;
}


void backup(char* original_file, char* backup_file){
    FILE* fptr_src;
    FILE* fptr_dest;
    char buffer[BUFLEN];
    size_t len;
    
    fptr_src = fopen(original_file, "rb");
    if(fptr_src == NULL){
        printf("Error opening file: %s", original_file);
        exit(1);
    }
    
    fptr_dest = fopen(backup_file, "wb");
    if(fptr_dest == NULL){
        printf("Error opening file: %s", backup_file);
        exit(1);
    }
    
    while((len = fread(buffer, sizeof(char), BUFLEN, fptr_src)) > 0){
        fwrite(buffer, sizeof(char), len, fptr_dest);
    }
    
    printf("File backed up successfully.");
    fclose(fptr_src);
    fclose(fptr_dest);
}