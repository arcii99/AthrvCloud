//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include <stdio.h> // Import necessary library

int main() {

    int r, t, s, q; // Initialize variables
    
    printf("Enter four integers: \n"); // Prompt user for input

    scanf("%d %d %d %d", &r, &t, &s, &q); // Read input values

    int sum = r + t + s + q; // Calculate the sum of input values
    
    int product = r * t * s * q; // Calculate the product of input values
    
    int difference = r - t - s - q; // Calculate the difference of input values
    
    int quotient = r / t / s / q; // Calculate the quotient of input values
    
    int modulo = r % t % s % q; // Calculate the modulo of input values

    printf("Sum = %d\n", sum); // Print the sum value
    
    printf("Product = %d\n", product); // Print the product value
    
    printf("Difference = %d\n", difference); // Print the difference value

    printf("Quotient = %d\n", quotient); // Print the quotient value
    
    printf("Modulo = %d\n", modulo); // Print the modulo value

    return 0; // Exit

}