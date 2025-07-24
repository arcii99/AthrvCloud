//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

int main() {
  unsigned int a = 60;    // 60 = 0011 1100
  unsigned int b = 13;    // 13 = 0000 1101
	unsigned int result; // Variable to store the result
	
	// Bitwise AND Operator
	result = a & b;
	printf("a & b = %u\n", result);
	
	// Bitwise OR Operator
	result = a | b;
	printf("a | b = %u\n", result);
	
	// Bitwise XOR Operator
	result = a ^ b;
	printf("a ^ b = %u\n", result);
	
	// Bitwise ones' complement operator
	result = ~a;
	printf("~a = %u\n", result);
	
	// Bitwise left shift operator
	result = a << 2;
	printf("a << 2 = %u\n", result);
	
	// Bitwise right shift operator
	result = a >> 2;
	printf("a >> 2 = %u\n", result);
	
	return 0;
}