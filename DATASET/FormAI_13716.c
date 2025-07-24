//FormAI DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int num, i, largest_factor = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // Check if the input is valid
    if (num <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }
    
    // Check if the input is a prime number
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            largest_factor = i;
            num /= i;
            i--;
        }
    }
    if (num > 1) {
        largest_factor = num;
    }
    
    printf("The largest prime factor of the input is: %d\n", largest_factor);
    
    return 0;
}