//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

int main(){

    char input[100];
    printf("Enter C code statement:\n");
    fgets(input, 100, stdin); //takes in user input
    
    //parsing starts here
    int semicolons = 0;
    int brackets = 0;
    int i;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';') {
            semicolons++;
        }

        if (input[i] == '{' || input[i] == '}') {
            brackets++;
        }
    }

    //output based on parsing results
    if(semicolons == 0 && brackets == 0){
        printf("This is not a valid C code statement.\n");
        return 0;
    }

    if(semicolons == 1 && brackets == 0){
        printf("This is a valid C code statement.\n");
        return 0;
    }

    if(semicolons > 1 && brackets == 0){
        printf("This is a valid C code block.\n");
        return 0;
    }

    if(semicolons == 0 && brackets == 2){
        printf("This is a valid C code block.\n");
        return 0;
    }

    printf("This is not a valid C code statement.\n");

    return 0;
}