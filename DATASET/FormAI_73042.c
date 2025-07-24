//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>

// Function to print the table of a number
void printTable(int num, int times, int current)
{
    // Base case: if current is greater than times, exit the function
    if(current > times)
        return;

    // Print the multiplication table of the given number
    printf("%d x %d = %d\n", num, current, num * current);

    // Recursively call the printTable function with incremented current value
    printTable(num, times, current + 1);
}

// Main function
int main()
{
    int num, times;

    // Prompt user to enter a number and the range of table
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the range of table: ");
    scanf("%d", &times);

    // Display multiplication table of entered number using recursive function call
    printTable(num, times, 1);

    return 0;
}