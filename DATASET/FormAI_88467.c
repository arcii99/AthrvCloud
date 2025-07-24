//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);

    //Error handling for division by zero
    if (num2 == 0) {
        printf("Error: Cannot divide by zero.\n");
        exit(1);
    } else {
        result = num1 / num2;
        printf("%d divided by %d is %d\n", num1, num2, result);
    }

    //Error handling for invalid input
    char str[10];
    printf("Enter a number: ");
    scanf("%s", str);
    num1 = atoi(str); //converts string input to integer type

    if (num1 == 0) {
        printf("Error: Invalid input.\n");
        exit(1);
    } else {
        printf("The number entered is %d.\n", num1);
    }

    //Error handling for file opening
    FILE *fp;
    fp = fopen("nonexistent.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    } else {
        printf("File opened successfully.\n");
        fclose(fp);
    }

    return 0;
}