//FormAI DATASET v1.0 Category: Data recovery tool ; Style: configurable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_CHAR 100000

//function to convert string to uppercase
void toUpperCase(char* str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
   }
}

//function to recover data from file
void dataRecovery(char* fileName) {
    FILE* file_ptr;
    file_ptr = fopen(fileName, "r");
    if (file_ptr == NULL) {
        printf("File not found!\n");
        return;
    }
    char data[MAX_CHAR] = "";
    fgets(data, MAX_CHAR, file_ptr);
    fclose(file_ptr);
    //Each data block is separated by semicolon
    char* dataBlock = strtok(data, ";");
    while (dataBlock != NULL) {
        //Check if the data block has "ERROR" keyword
        if (strstr(dataBlock, "ERROR") != NULL) {
            char* temp_data = (char*)malloc(strlen(dataBlock)*sizeof(char));
            strcpy(temp_data, dataBlock);
            //Convert data block to uppercase
            toUpperCase(temp_data);
            //Open file to write the recovered data
            FILE* file = fopen("recoveredData.txt", "a");
            fprintf(file, "%s\n", temp_data);
            fclose(file);
        }
        dataBlock = strtok(NULL, ";");
    }
    printf("Data recovery completed!\n");
}

int main() {
    char fileName[50];
    printf("Enter the name of file to recover data from: ");
    scanf("%s", fileName);
    dataRecovery(fileName);
    return 0;
}