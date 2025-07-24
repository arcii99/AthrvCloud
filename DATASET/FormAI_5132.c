//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    FILE *fp;
    char filename[50], line[1024], *token;
    int row = 0, col = 0;
    char *data[1024][1024];
 
    printf("Enter CSV filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error opening file!\n");
        return 0;
    }

    while(fgets(line, 1024, fp) != NULL){
        col = 0;
        token = strtok(line, ",");
        while(token != NULL){
            data[row][col++] = strdup(token);
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(fp);

    // Print CSV data
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            free(data[i][j]);
        }
    }

    return 0;
}