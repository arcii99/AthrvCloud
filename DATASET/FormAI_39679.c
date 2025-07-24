//FormAI DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void handle_error(char *error_message){
    printf("Error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

int main(){
    FILE *fp;
    char *filename = "test_file.txt";

    fp = fopen(filename, "r");
    if(fp == NULL){
        handle_error("Unable to open file");
    }

    int num1, num2, result;
    printf("Enter two numbers to be divided: ");
    scanf("%d %d", &num1, &num2);

    if(num2 == 0){
        handle_error("Division by zero error");
    }

    result = num1 / num2;
    printf("%d divided by %d is %d\n", num1, num2, result);

    fclose(fp);
    return 0;
}