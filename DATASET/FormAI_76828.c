//FormAI DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include<stdio.h>

int main(){
	float temperature = 0;
	
	printf("Welcome to Temperature Monitor\n\n");
	
	while(1){
		printf("Enter Temperature in Celsius: ");
		scanf("%f", &temperature);
		
		//if temperature is below absolute zero or above boiling point, give warning
		if(temperature < -273.15 || temperature > 100){
			printf("\nWARNING: Temperature outside safe range\n");
		}
		else{
			//convert temperature to Fahrenheit and print results
			float fahrenheit = (temperature * (9.0 / 5)) + 32;
			printf("\nTemperature in Celsius: %.2f\n", temperature);
			printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
		}
		
		//ask user if they want to check another temperature
		char choice;
		printf("\nDo you want to check another temperature? (y/n): ");
		scanf(" %c", &choice);
		printf("\n");
		
		//if user chooses 'n', exit the program
		if(choice == 'n' || choice == 'N'){
			printf("Thank you for using Temperature Monitor!\n");
			return 0;
		}
	}
	return 0;
}