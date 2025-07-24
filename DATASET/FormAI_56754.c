//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to convert the message string into a hash value
unsigned long hash(char* message) {
    int length = strlen(message);
    unsigned long hash_value = 0;
    for(int i=0; i<length; i++) {
        int fibonacci_num = fibonacci(i+1);  // Calculate the (i+1)th Fibonacci number
        int char_value = (int) message[i];
        hash_value += char_value * fibonacci_num;
    }
    return hash_value;
}

// Example usage
int main() {
    char message[] = "Hello world!";
    unsigned long hash_value = hash(message);
    printf("The hash value of \"%s\" is %lu.\n", message, hash_value);
    return 0;
}