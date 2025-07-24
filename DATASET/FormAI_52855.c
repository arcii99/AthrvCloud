//FormAI DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
	float celsius, fahrenheit; // declaring variables to store temperature values

	printf("Enter temperature value in Celsius: ");
	scanf("%f", &celsius);

	// Convert temperature from Celsius to Fahrenheit
	fahrenheit = (celsius * 9/5) + 32;

	printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

	return 0;
}