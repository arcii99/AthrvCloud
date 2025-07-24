//FormAI DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function to create backup copies of files
void backupFile(char* fileName){
    //Get current timestamp
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char backupFileName[100];
    sprintf(backupFileName, "%s_%d-%02d-%02d_%02d-%02d-%02d.bak", fileName, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    //Create backup file
    FILE *originalFile, *backupFile;
    char c;
    originalFile = fopen(fileName, "r");
    backupFile = fopen(backupFileName, "w");
    if (originalFile == NULL || backupFile == NULL){
        printf("Error: Unable to create backup file!\n");
        exit(1);
    }
    while ((c = fgetc(originalFile)) != EOF){
        fputc(c, backupFile);
    }
    fclose(originalFile);
    fclose(backupFile); 
    printf("Backup file created successfully!\n");
}

int main(){
    int choice;
    printf("*** Welcome to the Cyberpunk File Backup System ***\n");
    printf("Enter the file name you want to backup: ");
    char fileName[100];
    scanf("%s", fileName);
    backupFile(fileName);
    return 0;
}