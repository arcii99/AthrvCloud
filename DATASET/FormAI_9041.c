//FormAI DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp;
    fp = fopen("example.txt", "w+");
    char str[50];

    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }

    printf("Enter a string to write to file: ");
    fgets(str, sizeof(str), stdin);

    fprintf(fp, "%s", str);

    fseek(fp, 0, SEEK_SET);

    char c;
    printf("The contents of the file are: ");
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}