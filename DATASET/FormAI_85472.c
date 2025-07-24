//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>

void displayMenu(){
	printf("-----Mortgage Calculator-----\n");
	printf("1. Calculate Monthly Payment\n");
	printf("2. Calculate Total Payment\n");
	printf("3. Exit\n\n");
}

float calculateMonthlyPayment(float principal, float interestRate, int numberOfPayments){
	float monthlyInterestRate = interestRate / 1200;
	float monthlyPayment = (principal * monthlyInterestRate) / (1 - (pow(1 + monthlyInterestRate, -numberOfPayments)));
	return monthlyPayment;
}

float calculateTotalPayment(float monthlyPayment, int numberOfPayments){
	float totalPayment = monthlyPayment * numberOfPayments;
	return totalPayment;
}

int main(){
	
	float principal, interestRate;
	int numberOfPayments, choice;
	float monthlyPayment, totalPayment;
	
	printf("Enter Principal Amount: ");
	scanf("%f", &principal);
	
	printf("Enter Interest Rate: ");
	scanf("%f", &interestRate);
	
	printf("Enter Number of Payments: ");
	scanf("%d", &numberOfPayments);
	
	do{
		displayMenu();
		printf("Enter Choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 1:
				monthlyPayment = calculateMonthlyPayment(principal, interestRate, numberOfPayments);
				printf("\nMonthly Payment: %.2f\n\n", monthlyPayment);
				break;
				
			case 2:
				monthlyPayment = calculateMonthlyPayment(principal, interestRate, numberOfPayments);
				totalPayment = calculateTotalPayment(monthlyPayment, numberOfPayments);
				printf("\nTotal Payment: %.2f\n\n", totalPayment);
				break;
				
			case 3:
				printf("\nGoodbye!\n");
				break;
				
			default:
				printf("\nInvalid choice\n\n");
		}
		
	}while(choice != 3);
	
	return 0;
}