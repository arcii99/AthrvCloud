//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    char filename[] = "data.txt";
    int data;

    fp = fopen(filename, "r");

    if(fp == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully.\n");

    while(fscanf(fp, "%d", &data) != EOF){
        printf("%d\n", data);
    }

    if(ferror(fp)){
        printf("Error reading file.\n");
    }
    else if(feof(fp)){
        printf("End of file reached.\n");
    }

    fclose(fp);

    return 0;
}