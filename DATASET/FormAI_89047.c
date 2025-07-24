//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
	
	float fahrenheit, celsius, kelvin;
	char choice;
	int valid_choice = 0;
	
	printf("Welcome, dear user. Please tell me if you want to convert from Fahrenheit [F], Celsius [C], or Kelvin [K]: ");
	
	do {
		scanf("%c", &choice);
		if (choice == 'F') {
			printf("Ah, the good old Fahrenheit temperature scale. Very well. Please give me the temperature you want to convert: ");
			scanf("%f", &fahrenheit);
			celsius = (fahrenheit - 32) * 5 / 9;
			kelvin = celsius + 273.15;
			printf("%f F equals %f C and %f K.\n", fahrenheit, celsius, kelvin);
			valid_choice = 1;
		} else if (choice == 'C') {
			printf("Celsius you say? That's interesting. Please give me the temperature you want to convert: ");
			scanf("%f", &celsius);
			fahrenheit = celsius * 9 / 5 + 32;
			kelvin = celsius + 273.15;
			printf("%f C equals %f F and %f K.\n", celsius, fahrenheit, kelvin);
			valid_choice = 1;
		} else if (choice == 'K') {
			printf("Kelvin? An exotic choice indeed. Please give me the temperature you want to convert: ");
			scanf("%f", &kelvin);
			celsius = kelvin - 273.15;
			fahrenheit = celsius * 9 / 5 + 32;
			printf("%f K equals %f C and %f F.\n", kelvin, celsius, fahrenheit);
			valid_choice = 1;
		} else {
			printf("Sorry, I didn't understand your choice. Please enter F for Fahrenheit, C for Celsius or K for Kelvin: ");
			continue;
		}
	} while (!valid_choice);
	
	printf("Thank you for using this temperature converter. Goodbye!\n");
	
	return 0;
}