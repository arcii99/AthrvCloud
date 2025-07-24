//FormAI DATASET v1.0 Category: File handling ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp; //declaring file pointer 
    char ch;

    fp = fopen("example.txt", "w"); //opening file in write mode

    if(fp == NULL){ //error handling 
        printf("Error opening file!");
        exit(1); //exiting program if file not found or not readable 
    }
    
    printf("Enter a character to write to the file: ");
    scanf("%c", &ch);
    
    fputc(ch, fp); //writing character to file 
    
    printf("Character written successfully to file.");
    
    fclose(fp); //closing file
    
    fp = fopen("example.txt", "r"); //opening file in read mode 
    
    if(fp == NULL){ //error handling 
        printf("Error opening file!");
        exit(1); //exiting program if file not found or not readable 
    }
    
    printf("\nThe contents of the file are: ");
    
    while((ch = fgetc(fp)) != EOF){ //reading file character by character 
        printf("%c", ch);
    }
    
    fclose(fp); //closing file 
    
    return 0;
}