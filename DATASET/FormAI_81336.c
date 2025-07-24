//FormAI DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

void checkInput(int input){
    if(input > 100){
        int *ptr = malloc(input * sizeof(int));
        if(ptr == NULL){
            printf("Error allocating memory");
            exit(1);
        }
        else{
            checkInput(input-1);
        }
    }
    else{
        printf("Input is safe\n");
        return;
    }
}

int main(){
    int input;
    printf("Enter a number between 1 and 100: ");
    scanf("%d", &input);
    checkInput(input);
    return 0;
}