//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

void new_file(){
    FILE *file_ptr = fopen("sample.txt", "r");
    if(file_ptr == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully.\n");
    fclose(file_ptr);
}

int main(){
    errno = 0;
    new_file();
    if(errno){
        printf("Error occurred! Error Code : %d\n", errno);
    }
    else{
        printf("No errors were detected.\n");
    }
    return 0;
}