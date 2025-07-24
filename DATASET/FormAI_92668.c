//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 1000 

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    int count = 0;
    char file_name[MAX_CHARS];

    if (argc != 2){
        printf("C Word Count Tool Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }
    strcpy(file_name, argv[1]);
    fp = fopen(file_name, "r");

    if (fp == NULL){
        printf("Error Occured: File Not Found\n");
        exit(1);
    }
    else {
        while((ch = fgetc(fp)) != EOF){
            if(ch == ' ' || ch == '\t' || ch == '\n' || ch== '\0'){
                count++;
            }
        }
    }
    printf("Total Number of Words: %d\n", count);
    fclose(fp);
    return 0;
}