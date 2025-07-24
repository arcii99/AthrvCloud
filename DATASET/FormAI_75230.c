//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[1000];
    printf("Enter a C program to parse: ");
    fgets(input,1000,stdin);
    
    //remove newline character from input
    int len = strlen(input);
    input[len-1] = '\0';
    
    //check if input is a valid C program
    if(strstr(input,"#include") == NULL){
        printf("Invalid C program!\n");
        exit(0);
    }
    
    //parse function names
    char* ptr = strtok(input," ");
    while(ptr != NULL){
        if(strcmp(ptr,"int") == 0 || strcmp(ptr,"void") == 0){
            ptr = strtok(NULL," ");
            printf("Function name: %s()\n", ptr);
        }
        else{
            ptr = strtok(NULL," ");
        }
    }
    
    //parse variable names
    ptr = strtok(input," ");
    while(ptr != NULL){
        if(strcmp(ptr,"int") == 0 || strcmp(ptr,"float") == 0 || strcmp(ptr,"double") == 0 || strcmp(ptr,"char") == 0){
            ptr = strtok(NULL," ");
            char* var_ptr = strtok(ptr,",;");
            while(var_ptr != NULL){
                printf("Variable name: %s\n",var_ptr);
                var_ptr = strtok(NULL,",;");
            }
        }
        else{
            ptr = strtok(NULL," ");
        }
    }
    
    return 0;
}