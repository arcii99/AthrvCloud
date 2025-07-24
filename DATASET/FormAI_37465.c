//FormAI DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    if(scanf("%d%d", &num1, &num2) != 2) { // Check if two integers were successfully scanned
        printf("Error: Incorrect input format. Please enter two integers.\n");
        exit(EXIT_FAILURE); // Exit the program with an error code
    }
    if(num2 == 0) { // Check if the second number is zero
        printf("Error: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE); // Exit the program with an error code
    }
    int result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);

    // Error handling example: File I/O
    FILE *fp = fopen("example.txt", "r");
    if(fp == NULL) { // Check if the file was successfully opened
        printf("Error: Failed to open file.\n");
        exit(EXIT_FAILURE); // Exit the program with an error code
    }
    char buffer[1024];
    if(fgets(buffer, 1024, fp) == NULL) { // Check if the first line of the file was successfully read
        printf("Error: Failed to read file.\n");
        fclose(fp); // Close the file
        exit(EXIT_FAILURE); // Exit the program with an error code
    }
    printf("First line of example.txt: %s", buffer);

    fclose(fp); // Close the file
    return 0;
}