//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: authentic
#include <stdio.h>
#include <math.h>

int main()
{
	float principal, rate, monthly_rate, monthly_payment, total_payment;
	int term_months;

	printf("Enter the principal amount: $");
	scanf("%f", &principal);

	printf("Enter the interest rate (as a decimal): ");
	scanf("%f", &rate);

	printf("Enter the term of the mortgage (in months): ");
	scanf("%d", &term_months);

	// NOTE: Monthly interest rate calculation assumes interest is not compounded.
	monthly_rate = rate / 12.0;

	// Monthly payment calculation
	float numerator = monthly_rate * pow(1 + monthly_rate, term_months);
	float denominator = pow(1 + monthly_rate, term_months) - 1.0;
	monthly_payment = principal * (numerator / denominator);

	// Total payment calculation
	total_payment = monthly_payment * term_months;

	// Output results
	printf("\nMonthly payment: $%.2f\n", monthly_payment);
	printf("Total payment: $%.2f\n", total_payment);

	return 0;
}