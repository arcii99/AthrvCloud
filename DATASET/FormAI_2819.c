//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: real-life
#include<stdio.h>
#include<math.h>

int main(){
	
	float amount, interest, payment, principle, total_interest;
	float monthly_interest_rate, monthly_payment, monthly_interest, balance;
	int term, payment_count = 0;
	
	printf("Enter the amount of the loan: ");
	scanf("%f", &amount);
	
	printf("Enter the interest rate of the loan: ");
	scanf("%f", &interest);
	
	printf("Enter the term of the loan (in years): ");
	scanf("%d", &term);
	
	//converting years to months
	term = term* 12;
	
	//calculating monthly interest rate
	monthly_interest_rate = interest/(12*100);
	
	//calculating monthly payment
	monthly_payment = (amount*monthly_interest_rate*pow(1+monthly_interest_rate,term))/(pow(1+monthly_interest_rate,term)-1);
	
	//loop until the balance becomes 0
	balance = amount;
	while(balance > 0){
		
		//calculating monthly interest
		monthly_interest = balance*monthly_interest_rate;
		
		//calculating principle amount
		principle = monthly_payment - monthly_interest;
		
		//calculating total interest
		total_interest += monthly_interest;
		
		//reducing the balance
		balance -= principle;
		
		//incrementing the payment count
		payment_count++;
		
		//printing the payment details
		printf("\nPayment %d:\n", payment_count);
		printf("Principle Amount : %.2f\n", principle);
		printf("Interest Amount : %.2f\n", monthly_interest);
		printf("Total Interest Paid : %.2f\n", total_interest);
		printf("Total Amount Paid : %.2f\n", monthly_payment * payment_count);
		printf("Loan Balance : %.2f\n", balance);
	}
	
	return 0;
}