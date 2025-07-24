//FormAI DATASET v1.0 Category: File handling ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    int ch, count = 0;
    char filename[20];

    printf("Enter the file name: ");
    scanf("%s",filename);

    fp = fopen(filename,"r");

    if(fp == NULL){
        printf("Error opening the file.");
        exit(1);
    }

    printf("File content:\n");

    while((ch=fgetc(fp)) != EOF){
        printf("%c",ch);
        if(ch == '\n'){
            count++;
        }
    }

    printf("\nNumber of lines in the file: %d", count);

    fclose(fp);

    return 0;
}