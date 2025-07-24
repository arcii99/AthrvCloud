//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>

// function to calculate monthly payment for a given loan amount, interest rate and tenure
float calculateMonthlyPayment(float loanAmount, float interestRate, int tenure) {
    float monthlyInterestRate = interestRate / 1200; // monthly interest rate
    int months = tenure * 12; // total number of months
    float monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -months)); // formula
    return monthlyPayment;
}

int main() {
    float loanAmount, interestRate;
    int tenure, numPlayers;

    printf("Enter loan amount: ");
    scanf("%f", &loanAmount);

    printf("Enter interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter loan tenure in years: ");
    scanf("%d", &tenure);

    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    float monthlyPayment = calculateMonthlyPayment(loanAmount, interestRate, tenure);
    printf("Monthly payment: %.2f\n", monthlyPayment);

    float totalPayment = monthlyPayment * tenure * 12;

    // calculate and display contribution of each player
    float contribution = totalPayment / numPlayers;
    printf("Contribution per player: %.2f\n", contribution);

    // play game until all players have paid their contribution
    while (numPlayers > 0) {
        for (int i = 1; i <= numPlayers; i++) {
            printf("Player %d, make your contribution of %.2f: ", i, contribution);
            float payment;
            scanf("%f", &payment);
            // check if player paid correct amount
            if (payment == contribution) {
                printf("Payment accepted. %d players remaining.\n", numPlayers - 1);
                numPlayers--;
            } else {
                printf("Payment incorrect. Try again.\n");
            }
        }
    }

    printf("All payments received. Loan paid off!\n");

    return 0;
}