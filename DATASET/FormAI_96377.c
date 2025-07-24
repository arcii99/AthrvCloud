//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int num1, num2, sum, difference, product, quotient;
    char fileName[20];
    FILE *file;
    
    // Ask for user input of two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    // Perform mathematical operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    
    // Ask for file name and create a file
    printf("Enter the file name: ");
    scanf("%s", fileName);
    file = fopen(fileName, "w");
    
    // Write mathematical results to the file
    fprintf(file, "Sum: %d\n", sum);
    fprintf(file, "Difference: %d\n", difference);
    fprintf(file, "Product: %d\n", product);
    fprintf(file, "Quotient: %d\n", quotient);
    
    // Print the mathematical results on the console
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    
    // Close the file
    fclose(file);
    
    return 0;
}