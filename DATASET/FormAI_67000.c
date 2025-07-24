//FormAI DATASET v1.0 Category: File Encyptor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char*);

void main(){
    char filename[20];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    encrypt(filename);

    printf("File encrypted successfully!\n");
}

void encrypt(char* filename){
    FILE *fp;
    fp = fopen(filename, "r+");

    if(fp == NULL){
        printf("File does not exist.");
        exit(1);
    }

    char ch;
    while((ch = fgetc(fp)) != EOF){
        ch = ~ch;
        fseek(fp, -1L, SEEK_CUR);
        fputc(ch, fp);
    }

    fclose(fp);
}