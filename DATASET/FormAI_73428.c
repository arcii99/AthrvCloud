//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>

int main()
{
	float temperature;
	char conversionType;

	printf("Welcome to the Future Temperature Converter!\n");
	printf("Enter the temperature you want to convert: ");
	scanf("%f", &temperature);

	printf("Do you want to convert to Celsius (C) or Fahrenheit (F)? ");
	scanf(" %c", &conversionType);

	if (conversionType == 'C')
	{
		float convertedTemp = (temperature - 32) * 5 / 9;
		printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemp);
	}
	else if (conversionType == 'F')
	{
		float convertedTemp = temperature * 9 / 5 + 32;
		printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemp);
	}
	else
	{
		printf("Invalid conversion type.\n");
	}

	printf("Thank you for using the Future Temperature Converter.\n");

	return 0;
}