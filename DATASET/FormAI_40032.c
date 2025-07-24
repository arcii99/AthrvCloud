//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random integer between given range
int generateRandomNumber(int min, int max)
{
    int randomNum = (rand() % (max - min + 1)) + min;
    return randomNum;
}

// Function to add two numbers asynchronously
void addNumbersAsynchronously(int a, int b)
{
    bool isCompleted = false;
    int result;
    
    // Generate random delay between 1 to 3 seconds
    srand(time(NULL));  
    int delay = generateRandomNumber(1,3);
    sleep(delay);
    
    // Add two numbers
    result = a + b;
    
    // Print result
    printf("The sum of %d and %d is %d\n", a, b, result);
    isCompleted = true;
}

int main()
{
    int num1, num2;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Call function to add two numbers asynchronously
    addNumbersAsynchronously(num1, num2);
    
    // Print message to confirm asynchronous execution
    printf("The addition operation is being performed asynchronously. Please wait for the result...\n");
    
    return 0;
}