//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void wordCount(char* str);

int main(){

    char* inputString = (char*)malloc(sizeof(char)*100);
    printf("Enter a string : ");
    gets(inputString);

    wordCount(inputString);

    return 0;
}

void wordCount(char* str){

    int count = 0;
    char* tempString = (char*)malloc(sizeof(char)*100);
    strcpy(tempString, str);

    char* token = strtok(tempString, " ");

    while(token != NULL){
        count++;
        token = strtok(NULL, " ");
    }

    printf("Total words in the entered string : %d", count);
}