//FormAI DATASET v1.0 Category: Error handling ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

void print_error(char* message){
    printf("ERROR: %s\nAborting...\n", message);
    exit(EXIT_FAILURE);
}

int main(){

    int num1, num2;

    printf("Enter two numbers to be divided: ");
    scanf("%d %d", &num1, &num2);

    if(num2 == 0){
        print_error("Division by zero");
    }

    int result = num1/num2;

    printf("%d divided by %d is %d\n", num1, num2, result);

    return 0;
}