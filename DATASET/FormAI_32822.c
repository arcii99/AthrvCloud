//FormAI DATASET v1.0 Category: Data validation ; Style: satisfied
#include <stdio.h>

int main()
{
	// Initialize variables
	char name[20], gender, confirm;
	int age;

	// Loop until user confirms inputs
	do {
		// Get user inputs
		printf("Enter your name: ");
		scanf("%s", name);
		printf("Enter your age: ");
		scanf("%d", &age);
		printf("Enter your gender (M/F): ");
		scanf(" %c", &gender);

		// Check for valid inputs
		if (age < 0 || age > 120) {
			printf("Invalid age. Please enter a value between 0 and 120.\n");
		} else if (gender != 'M' && gender != 'F') {
			printf("Invalid gender. Please enter either M or F.\n");
		} else {
			// Display user inputs for confirmation
			printf("Name: %s\n", name);
			printf("Age: %d\n", age);
			printf("Gender: %c\n", gender);

			// Confirm inputs with user
			printf("Are these inputs correct? (Y/N): ");
			scanf(" %c", &confirm);

			// Capitalize confirm input for simplicity
			if (confirm >= 'a' && confirm <= 'z') {
				confirm -= ('a' - 'A');
			}
		}
	} while (confirm != 'Y');

	// If inputs are confirmed, display confirmation message and end program
	printf("Thank you, your inputs have been confirmed.");
	return 0;
}