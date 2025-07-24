//FormAI DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char filename[100], ch;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    fp = fopen(filename, "r"); // Open file in read mode

    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of %s file are: \n", filename);

    while ((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }

    fclose(fp);

    return 0;
}