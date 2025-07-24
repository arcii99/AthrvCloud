//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

void digitalWatermarking(char *fileName, char *watermarkData) {
    FILE *fp;
    fp = fopen(fileName, "r+");

    if(fp == NULL) {
        printf("Error: File not found!");
        return;
    }

    char *fileContents = (char *) malloc(MAX_SIZE);
    fread(fileContents, MAX_SIZE, 1, fp);
    fclose(fp);

    char *digitalWatermark = (char *) malloc(MAX_SIZE);
    strcpy(digitalWatermark, watermarkData);

    int n = strlen(fileContents);
    int m = strlen(digitalWatermark);
    int k = 0;

    for(int i = 0; i < n; i++) {
        if(k < m && fileContents[i] != '\n') {
            fileContents[i] = digitalWatermark[k];
            k++;
        }
    }

    fp = fopen(fileName, "w");
    fwrite(fileContents, n, 1, fp);
    fclose(fp);

    printf("Digital Watermarking successfully completed!");
}

int main() {
    char fileName[] = "cyberpunk.txt";
    char watermarkData[] = "This file is digitally watermarked!";

    digitalWatermarking(fileName, watermarkData);

    return 0;
}