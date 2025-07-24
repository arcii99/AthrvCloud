//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to count frequency of a keyword in a log file
int countFreq(FILE* fp,char* keyword){
    int count=0;
    char temp[1000];
    while(!feof(fp)){
        fgets(temp,1000,fp);
        if(strstr(temp,keyword)){
            count++;
        }
    }
    return count;
}

int main(){
    char filename[100];
    char keyword[100];
    printf("Enter the name of the log file: ");
    scanf("%s",filename);
    FILE* fp=fopen(filename,"r");
    if(fp==NULL){
        printf("File not found\n");
        return 0;
    }
    printf("Enter the keyword to search: ");
    scanf("%s",keyword);
    printf("\nThe frequency of keyword '%s' is %d\n",keyword,countFreq(fp,keyword));
    fclose(fp);
    return 0;
}