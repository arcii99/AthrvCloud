//FormAI DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

int main(){
    char input[100];
    printf("Enter a mathematical expression: ");
    scanf("%s", input);
    int i = 0;
    while(input[i] != '\0'){
        if(input[i] == '(' || input[i] == ')'){
            printf("Parenthese found at index %d\n", i);
        }else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            printf("Operator found at index %d\n", i);
        }else if(input[i] >= '0' && input[i] <= '9'){
            printf("Number found at index %d\n", i);
        }else{
            printf("Invalid character found at index %d\n", i);
            exit(0);
        }
        i++;
    }
    printf("The input was correctly parsed!\n");
    return 0;
}