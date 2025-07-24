//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {
	int num1, num2, sum, diff, product, quotient, remainder;

	printf("Enter the first number: ");
	scanf("%d", &num1);

	printf("Enter the second number: ");
	scanf("%d", &num2);

	sum = num1 + num2;
	diff = num1 - num2;
	product = num1 * num2;

	if (num2 != 0) {
		quotient = num1 / num2;
		remainder = num1 % num2;
	}
	
	printf("\nMathematical Operations:\n");
	printf("------------------------\n");

	printf("Sum of %d and %d is %d\n", num1, num2, sum);
	printf("Difference of %d and %d is %d\n", num1, num2, diff);
	printf("Product of %d and %d is %d\n", num1, num2, product);

	if (num2 != 0) {
		printf("Quotient when %d is divided by %d is %d with remainder %d\n", num1, num2, quotient, remainder);
	}

	return 0;
}