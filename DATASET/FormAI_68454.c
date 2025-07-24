//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main(){

    char filename[100];
    printf("Enter the file name with .txt extension: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error opening the file\n");
        exit(1);
    }

    int count = 0, n;
    float sum = 0.0, average;

    while(fscanf(fp, "%d", &n) == 1){
        count++;
        sum += n;
    }

    fclose(fp);

    if(count > 0){
        average = sum / count;
        printf("The sum of numbers in the file is: %.2f\n", sum);
        printf("The average of numbers in the file is: %.2f\n", average);
    }
    else{
        printf("There are no numbers in the file\n");
    }

    return 0;
}