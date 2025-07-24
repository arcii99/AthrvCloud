//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>

int main() {
	char operator;
	float num1, num2;

	printf("Please enter an operator (+, -, *, /): ");
	scanf("%c", &operator);

	printf("Please enter two numbers: ");
	scanf("%f %f", &num1, &num2);

	switch(operator) {
		case '+':
			printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
			break;

		case '-':
			printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
			break;

		case '*':
			printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
			break;

		case '/':
			if(num2 == 0) {
				printf("Error: Cannot divide by 0");
			} else {
				printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
			}
			break;

		default:
			printf("Invalid operator");
	}

	return 0;
}