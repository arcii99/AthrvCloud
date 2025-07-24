//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp; // Pointer to file
    char ch, filename[20]; // character variable and filename.

    printf("Enter the filename: "); // user input for filename
    scanf("%s", filename);

    fp = fopen(filename, "r"); // open file in read mode

    if(fp == NULL){ //checking if file exists
        printf("File does not exist or unable to open the file.\n"); // if file does not exist or unable to open file
        exit(0);
    }

    printf("\nContents of %s file are:\n", filename);

    while((ch = fgetc(fp)) != EOF){ // read from file
        printf("%c", ch); // print characters present in the file
    }

    fclose(fp); // close the file
    return 0;
}