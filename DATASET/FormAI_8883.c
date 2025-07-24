//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LENGTH 100 

int main(){
    FILE *file = fopen("testfile.csv", "r");
    if(file == NULL){
        printf("Failed to open file.\n");
        exit(1);
    }   

    char row[MAX_STR_LENGTH];
    char* field;
    int i = 0;
    while(fgets(row, MAX_STR_LENGTH, file)){
        i++;
        printf("Row %d: ", i);

        field = strtok(row, ",");
        while(field != NULL){
            printf("%s ", field);
            field = strtok(NULL, ",");
        }    
        printf("\n");
    }   

    fclose(file);

    return 0;
}