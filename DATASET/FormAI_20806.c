//FormAI DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main(){
    char input[50];
    int num1, num2, result = 0;

    printf("Enter two numbers: ");
    fgets(input, 50, stdin);
    if(sscanf(input, "%d%d", &num1, &num2) != 2){
        printf("Invalid input format\n");
        exit(1);
    }

    if(num2 == 0){
        printf("Cannot divide by zero\n");
        exit(1);
    }

    result = num1 / num2;

    printf("%d divided by %d is %d\n", num1, num2, result);

    return 0;
}