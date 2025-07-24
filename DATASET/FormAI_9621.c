//FormAI DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

#define MAX_BINARY_DIGITS 32 

int is_binary_valid(const char binary[MAX_BINARY_DIGITS]) { 
    int i = 0; 
    while (binary[i]) { 
        if (binary[i] != '0' && binary[i] != '1') return 0; 
        i++; 
    } 
    return 1; 
} 

int convert_binary_to_decimal(const char binary[MAX_BINARY_DIGITS]) { 
    int decimal = 0; 
    int len = strlen(binary); 
    for (int i = len - 1, j = 0; i >= 0; i--, j++) { 
        if (binary[i] == '1') decimal += 1 << j; 
    } 
    return decimal; 
} 

int main() { 
    printf("Enter a binary number: "); 
    char binary[MAX_BINARY_DIGITS]; 
    fgets(binary, MAX_BINARY_DIGITS, stdin); 
    binary[strcspn(binary, "\n")] = 0; 
    
    if (!is_binary_valid(binary)) { 
        printf("Invalid binary number format.\n"); 
        return 1; 
    } 
    
    int decimal = convert_binary_to_decimal(binary); 
    printf("%s in binary = %d in decimal\n", binary, decimal); 
    
    return 0; 
}