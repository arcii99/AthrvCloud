//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include<stdio.h>
#include<string.h>

int main(){
    printf("Welcome to C Antivirus Scanner!\n");

    char name[50];
    printf("\nEnter the name of the file you want to scan: ");
    scanf("%s", name);

    int len = strlen(name);
    char extension[len - 3];
    strncpy(extension, &name[len-3], 3);

    if(strcmp(extension, "exe") == 0){
        printf("File is not safe! It contains an executable.\n");
    }
    else if(strcmp(extension, "txt") == 0 || strcmp(extension, "pdf") == 0 || strcmp(extension, "doc") == 0){
        printf("File is safe to open.\n");
    }
    else{
        printf("File type not recognized. Scanning further...\n");

        char data[10000];
        FILE *fp;

        fp = fopen(name, "r");
        if(fp == NULL){
            printf("File could not be opened!\n");
            return 1;
        }

        fgets(data, 10000, fp);
        fclose(fp);

        if(strstr(data, "virus") != NULL){
            printf("File is infected with virus!\n");
        }
        else{
            printf("File is safe to open.\n");
        }
    }

    return 0;
}