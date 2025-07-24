//FormAI DATASET v1.0 Category: File handling ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    char filename[20];
    printf("Enter the filename: ");
    scanf("%s",&filename); //Get the filename from user

    FILE *fp;
    fp = fopen(filename,"r"); //Open the file in read-only mode

    if(fp == NULL){
        printf("Error: file could not be opened.");
        exit(1);
    }

    char buffer[1024];
    int count=0;

    while(fgets(buffer,1024,fp) != NULL){ //Read file line-by-line
        count++;
        printf("%d. %s",count,buffer);
    }

    fclose(fp); //Close the file

    return 0;
}