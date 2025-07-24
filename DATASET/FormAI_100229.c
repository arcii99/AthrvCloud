//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int choice, num;
	float result, num1, num2;

	do {
		printf("====== Scientific Calculator ======\n");
		printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Power Calculation\n7. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter two numbers to add: ");
				scanf("%f %f", &num1, &num2);
				result = num1 + num2;
				printf("%.2f\n", result);
				break;

			case 2:
				printf("Enter two numbers to substract: ");
				scanf("%f %f", &num1, &num2);
				result = num1 - num2;
				printf("%.2f\n", result);
				break;

			case 3:
				printf("Enter two numbers to multiply: ");
				scanf("%f %f", &num1, &num2);
				result = num1 * num2;
				printf("%.2f\n", result);
				break;

			case 4:
				printf("Enter two numbers to divide: ");
				scanf("%f %f", &num1, &num2);
				result = num1 / num2;
				printf("%.2f\n", result);
				break;

			case 5:
				printf("Enter a number to find square root: ");
				scanf("%f", &num1);
				result = sqrt(num1);
				printf("%.2f\n", result);
				break;

			case 6:
				printf("Enter a number: ");
				scanf("%f", &num1);
				printf("Enter its power: ");
				scanf("%f", &num2);
				result = pow(num1, num2);
				printf("%.2f\n", result);
				break;

			case 7:
				printf("Exiting program...");
				exit(0);
				break;

			default:
				printf("Invalid choice. Try again.\n");
                break;
		}
	} while(choice != 7);

	return 0;
}