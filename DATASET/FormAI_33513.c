//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>

// Function to calculate the sum of two numbers
int sum(int a, int b)
{
    return a + b;
}

// Function to calculate the difference of two numbers
int difference(int a, int b)
{
    return a - b;
}

// Function to calculate the product of two numbers
int product(int a, int b)
{
    return a * b;
}

// Function to calculate the quotient of two numbers
float quotient(int a, int b)
{
    if(b == 0)
    {
        printf("Cannot divide by zero");
        return 0;
    }
    else
    {
        return (float)a / b;
    }
}

int main()
{
    // Creating a file pointer and opening a file in write mode
    FILE *file = fopen("math_results.txt", "w");
    
    // Writing the results of some mathematical operations to the file
    fprintf(file, "Sum of 5 and 7 is %d\n", sum(5, 7));
    fprintf(file, "Difference between 10 and 4 is %d\n", difference(10, 4));
    fprintf(file, "Product of 3 and 9 is %d\n", product(3, 9));
    fprintf(file, "Quotient of 20 and 5 is %.2f\n", quotient(20, 5));
    
    // Closing the file pointer
    fclose(file);
    
    return 0;
}