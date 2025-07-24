//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filepath[100];
    printf("Enter the path to your file: ");
    scanf("%s",filepath);

    //Open file in read mode
    FILE *fp = fopen(filepath,"r");

    if(fp == NULL){
        printf("Error opening the file!");
        exit(1);
    }

    //Initialize variables
    char line[200];
    char keyword[20] = "Metadata:";
    char metadata[200] = "";

    //Read the file line by line
    while(fgets(line, sizeof(line), fp)){

        //Check if keyword is present in the line
        if(strstr(line, keyword) != NULL){

            //Extract the metadata from the line
            char *ptr = strchr(line, ':');
            strcpy(metadata, ptr+2);
            metadata[strlen(metadata)-1] = '\0'; //Remove trailing newline character
        }
    }

    //Close the file
    fclose(fp);

    //Print the extracted metadata
    printf("Metadata: %s\n", metadata);

    return 0;
}