//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>

int main() {
	char input[100];
	int decimal, i, j = 0, remainder, quotient;
	char hexadecimal[100];

	printf("Enter a decimal number: ");
	scanf("%d", &decimal);

	quotient = decimal;

	while (quotient != 0) {
		remainder = quotient % 16;

		if (remainder < 10) {
			hexadecimal[j++] = 48 + remainder;
		} else {
			hexadecimal[j++] = 55 + remainder;
		}

		quotient = quotient / 16;
	}

	printf("The hexadecimal equivalent of %d is: ", decimal);

	for (i = j - 1; i >= 0; i--) {
		printf("%c", hexadecimal[i]);
	}

	printf("\n");

	return 0;
}