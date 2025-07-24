//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include<stdio.h>

int main() {

	printf("Gratitude is expressed with code,\n");
	printf("Bitwise operation is the way to go! \n");
	printf("We thank the developers, who made it possible\n");
	printf("For us to do magic, with just a simple symbol\n");

	unsigned char x = 0b01110010;
	unsigned char y = 0b11001011;

	unsigned char result;

	// AND operator
	result = x & y;
	printf("\n AND Operation\n");
	printf("x & y = %d\n", result);

	// OR operator
	result = x | y;
	printf("\n OR Operation\n");
	printf("x | y = %d\n", result);

	// XOR operator
	result = x ^ y;
	printf("\n XOR Operation\n");
	printf("x ^ y = %d\n", result);

	// NOT operator
	result = ~x;
	printf("\n NOT Operation\n");
	printf("~x = %d\n", result);

	// Left Shift operator
	result = x << 2;
	printf("\n Left Shift Operation\n");
	printf("x << 2 = %d\n", result);

	// Right Shift operator
	result = x >> 2;
	printf("\n Right Shift Operation\n");
	printf("x >> 2 = %d\n", result);

	return 0;
}