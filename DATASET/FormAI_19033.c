//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEY 13

int main(){
    FILE *file_in, *file_out;
    char filename_in[50], filename_out[60], temp;
    printf("Enter the input filename: ");
    scanf("%s", filename_in);

    file_in = fopen(filename_in, "r"); // Open file for reading
    if(!file_in){
        printf("Unable to open the file!");
        return 1;
    }

    printf("Enter the output filename: ");
    scanf("%s", filename_out);

    file_out = fopen(filename_out, "w"); // Open file for writing
    if(!file_out){
        printf("Unable to open the file!");
        return 1;
    }

    while((temp = fgetc(file_in)) != EOF){
        fputc(temp + KEY, file_out);
    }

    printf("Successfully encrypted file!");

    fclose(file_in);
    fclose(file_out);

    return 0;
}