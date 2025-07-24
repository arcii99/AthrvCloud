//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the World of C!\n");
    
    // Declare an array to store some data
    int data[5] = {10, 20, 30, 40, 50};
    
    // Declare a variable to store the sum
    int sum = 0;
    
    // Loop through the array and add each element to the sum
    for (int i = 0; i < 5; i++) {
        sum += data[i];
    }
    
    // Print the sum to the console
    printf("The sum of the data array is: %d\n", sum);
    
    // Declare a variable to store the average
    float average = (float)sum / 5;
    
    // Print the average to the console
    printf("The average of the data array is: %.2f\n", average);
    
    // Declare a variable to store the product
    long long product = 1;
    
    // Loop through the array and multiply each element by the product
    for (int i = 0; i < 5; i++) {
        product *= data[i];
    }
    
    // Print the product to the console
    printf("The product of the data array is: %lld\n", product);
    
    return 0;
}