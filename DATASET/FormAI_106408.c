//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    /*Declare necessary variables*/
    int i, j, count=0, flag=0;
    char log[50][100], temp[100];

    /*Read the log file*/
    FILE *file = fopen("log.txt", "r");
    if (file == NULL){
        printf("Error: Unable to open file.");
        exit(1);
    }

    /*Store each line in an array*/
    while (fgets(log[count], 100, file)){
        count++;
    }

    /*Sort the log*/
    for (i=0; i<count-1; i++){
        for (j=i+1; j<count; j++){
            if (strcmp(log[i], log[j])>0){
                strcpy(temp, log[i]);
                strcpy(log[i], log[j]);
                strcpy(log[j], temp);
            }
        }
    }

    /*Remove duplicates*/
    for (i=0; i<count-1; i++){
        if (strcmp(log[i], log[i+1])==0){
            for (j=i; j<count-1; j++){
                strcpy(log[j], log[j+1]);
            }
            count--;
            i--;
        }
    }

    /*Search for a specific error*/
    printf("Enter the error to search for: ");
    char error[100];
    scanf("%s", error);
    for (i=0; i<count; i++){
        if (strstr(log[i], error)!=NULL){
            printf("%s", log[i]);
            flag=1;
        }
    }
    if (flag==0){
        printf("Error not found!");
    }

    fclose(file);
    return 0;

}