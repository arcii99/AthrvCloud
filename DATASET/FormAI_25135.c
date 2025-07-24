//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include<stdio.h>

int main(){

	printf("Hello! Let's have some fun with Bitwise Operations!\n");

	unsigned int a = 1638; // Binary: 0110 0110 0110 
	unsigned int b = 546; // Binary: 0010 0010 0010

	// Bitwise AND
	unsigned int c = a & b; // Binary: 0010 0010 0010

	printf("The result of Bitwise AND between %u and %u is %u.\n", a, b, c);

	// Bitwise OR
	unsigned int d = a | b; // Binary: 0110 0110 0110

	printf("The result of Bitwise OR between %u and %u is %u.\n", a, b, d);

	// Bitwise XOR
	unsigned int e = a ^ b; // Binary: 0100 0100 0100

	printf("The result of Bitwise XOR between %u and %u is %u.\n", a, b, e);

	// Bitwise NOT
	unsigned int f = ~a; // Binary: 1001 1001 1001 1001

	printf("The result of Bitwise NOT operation on %u is %u.\n", a, f);

	unsigned int g = ~b; // Binary: 1101 1101 1101

	printf("The result of Bitwise NOT operation on %u is %u.\n", b, g);

	// Bitwise left shift
	unsigned int h = a << 2; //  Binary: 1001 1001 0000 Number of bits shifted: 2

	printf("The result of Bitwise Left Shift on %u by 2 bits is %u.\n", a, h);

	// Bitwise right shift
	unsigned int i = b >> 1; // Binary: 0001 0001 0001

	printf("The result of Bitwise Right Shift on %u by 1 bit is %u.\n", b, i);

	return 0;
}