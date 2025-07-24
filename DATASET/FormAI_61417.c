//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h> 

void reverse(char* str, int start, int end) { 
    if (start >= end) { 
        return; 
    } 
    // Swapping the first and last characters of the string 
    char temp = *(str + start); 
    *(str + start) = *(str + end); 
    *(str + end) = temp; 
    // Recursively call the reverse function to swap the remaining characters 
    reverse(str, ++start, --end); 
} 

void convertToBinary(int num) { 
    if (num <= 0) { 
        return; 
    } 
    // Recursively calling the function to print binary digits in reverse order 
    convertToBinary(num / 2); 
    printf("%d", num % 2); 
} 

int main() { 
    char str[] = "Hello World"; 
    printf("Original string: %s\n", str); 
    reverse(str, 0, 10); // Reversing the string starting from index 0 to 10 
    printf("Reversed string: %s\n", str); 

    int num = 12345; 
    printf("Decimal number: %d\n", num); 
    printf("Binary number: "); 
    convertToBinary(num); // Converting decimal number to binary using recursion 
    printf("\n"); 

    return 0; 
}