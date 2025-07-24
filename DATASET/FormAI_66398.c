//FormAI DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>

int main() {
	float celsius, fahrenheit;
	printf("Enter temperature in Celsius: ");
	scanf("%f", &celsius);

	// conversion formula
	fahrenheit = (celsius * 9 / 5) + 32;

	// output the result
	printf("%.2f C = %.2f F", celsius, fahrenheit);

	return 0;
}