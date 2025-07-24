//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main(){
	float loanAmount, interestRate, monthlyPayment, paymentTerm, totalPayment, principal, interest, balance;
	
	// Taking inputs of loan amount, interest rate and payment term
	printf("Enter the loan amount: ");
	scanf("%f", &loanAmount);
	
	printf("Enter the interest rate: ");
	scanf("%f", &interestRate);
	
	printf("Enter the payment term in years: ");
	scanf("%f", &paymentTerm);
	
	// Converting payment term to months
	paymentTerm *= 12;
	
	// Calculating monthly interest rate
	interestRate = interestRate / 100.0 / 12.0;
	
	// Calculating monthly payment
	monthlyPayment = (loanAmount * interestRate) / (1 - pow(1+interestRate, -paymentTerm));
	
	// Initializing total payment as 0
	totalPayment = 0;
	
	// Displaying table of repayment schedule
	printf("\n\n\t\tRepayment Schedule\n");
	printf("----------------------------------------------------------\n");
	printf("Month\t   Payment\t   Principal\t   Interest\t   Balance\n");
	printf("----------------------------------------------------------\n");
	
	// Initializing loan balance
	balance = loanAmount;
	
	for(int i=1;i<=paymentTerm;i++){
		// Calculating principal amount
		principal = monthlyPayment - (balance * interestRate);
		
		// Calculating interest amount
		interest = monthlyPayment - principal;
		
		// Calculating balance amount
		balance = balance - principal;
		
		// Printing repayment schedule
		printf("%d\t   %.2f\t   %.2f\t   %.2f\t   %.2f\n",i,monthlyPayment,principal,interest,balance);
		
		// Calculating total payment
		totalPayment += monthlyPayment;
	}
	
	printf("----------------------------------------------------------\n");
	
	// Displaying mortgage summary
	printf("\nMortgage Summary:\n\n");
	printf("Loan Amount: $%.2f\n", loanAmount);
	printf("Interest Rate: %.2f%%\n", interestRate*100*12);
	printf("Payment Term: %.2f years\n", paymentTerm/12);
	printf("Monthly Payment: $%.2f\n", monthlyPayment);
	printf("Total Payment: $%.2f\n\n", totalPayment);
	
	return 0;
}