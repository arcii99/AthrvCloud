//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include<stdio.h>
#include<stdint.h>

// Function to perform bitwise AND operation
void bitwise_and(uint8_t a, uint8_t b){
    uint8_t result = a & b;
    printf("Bitwise AND Operation: %d & %d = %d \n", a, b, result);
}

// Function to perform bitwise OR operation
void bitwise_or(uint8_t a, uint8_t b){
    uint8_t result = a | b;
    printf("Bitwise OR Operation: %d | %d = %d \n", a, b, result);
}

// Function to perform bitwise XOR operation
void bitwise_xor(uint8_t a, uint8_t b){
    uint8_t result = a ^ b;
    printf("Bitwise XOR Operation: %d ^ %d = %d \n", a, b, result);
}

// Function to perform bitwise complement operation
void bitwise_complement(uint8_t a){
    uint8_t result = ~a;
    printf("Bitwise Complement Operation: ~ %d = %d \n", a, result);
}

int main(){
    uint8_t num1, num2;
    printf("Enter two numbers (between 0 and 255): \n");
    scanf("%hhu %hhu", &num1, &num2);
    
    bitwise_and(num1, num2);
    bitwise_or(num1, num2);
    bitwise_xor(num1, num2);
    bitwise_complement(num1);
    bitwise_complement(num2);
    
    return 0;
}