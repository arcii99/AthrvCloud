//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(){
    FILE *fp;
    int input;
    fp = fopen("test.txt", "r");
    if(fp == NULL){
        printf("Error: %d\n", errno);
        perror("Error Message");
    }else{
        printf("File opened successfully!\n");
        printf("Enter a number: ");
        scanf("%d", &input);
        if(input<0){
            fprintf(stderr, "Input cannot be negative\n");
            exit(EXIT_FAILURE);
        }else{
            printf("Input is %d\n", input);
        }
    }
    fclose(fp);
    return 0;
}