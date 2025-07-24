//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include<stdio.h>
#include<math.h>

// function prototypes
void menu();
void calculator();

int main() {
	char choice;
	printf("Welcome to the Scientific Calculator\n");

	do {
		menu();
		printf("Do you wish to continue? (Y/N): ");
		scanf(" %c", &choice);
	} while(choice == 'Y' || choice == 'y');

	printf("Thank you for using the Scientific Calculator\n");
	return 0;
}

void menu() {
	double a, b, res;
	int op;

	printf("\nChoose an Operation\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("5. Power\n");
	printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");
    printf("11. Logarithm Base 10\n");
	scanf("%d", &op);

	switch(op) {
		case 1:
			printf("Enter two numbers: ");
			scanf("%lf %lf", &a, &b);
			res = a + b;
			printf("Result: %.2lf\n", res);
			break;
		case 2:
			printf("Enter two numbers: ");
			scanf("%lf %lf", &a, &b);
			res = a - b;
			printf("Result: %.2lf\n", res);
			break;
		case 3:
			printf("Enter two numbers: ");
			scanf("%lf %lf", &a, &b);
			res = a * b;
			printf("Result: %.2lf\n", res);
			break;
		case 4:
			printf("Enter two numbers: ");
			scanf("%lf %lf", &a, &b);

			if(b == 0) {
				printf("Error: Division by zero\n");
			} else {
				res = a / b;
				printf("Result: %.2lf\n", res);
			}

			break;
		case 5:
			printf("Enter base and exponent: ");
			scanf("%lf %lf", &a, &b);
			res = pow(a, b);
			printf("Result: %.2lf\n", res);
			break;
		case 6:
			printf("Enter a number: ");
			scanf("%lf", &a);
			if(a < 0) {
				printf("Error: Cannot compute square root of negative number\n");
			} else {
				res = sqrt(a);
				printf("Result: %.2lf\n", res);
			}
			break;
        	case 7:
			printf("Enter an angle: ");
			scanf("%lf", &a);
			res = sin(a * M_PI / 180);
			printf("Result: %.2lf\n", res);
			break;
        	case 8:
			printf("Enter an angle: ");
			scanf("%lf", &a);
			res = cos(a * M_PI / 180);
			printf("Result: %.2lf\n", res);
			break;
        	case 9:
			printf("Enter an angle: ");
			scanf("%lf", &a);
			res = tan(a * M_PI / 180);
			printf("Result: %.2lf\n", res);
			break;
        	case 10:
			printf("Enter a number: ");
			scanf("%lf", &a);
			res = log(a);
			printf("Result: %.2lf\n", res);
			break;
        	case 11:
			printf("Enter a number: ");
			scanf("%lf", &a);
			res = log10(a);
			printf("Result: %.2lf\n", res);
			break;
		default:
			printf("Error: Invalid Operation\n");
			break;
	}
}