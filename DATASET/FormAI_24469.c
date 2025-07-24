//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>

int main() {

    float principal, interest_rate, monthly_payment, balance;
    int num_payments;
    int players;

    printf("Welcome to Multiplayer Mortgage Calculator game!\n\n");
    printf("How many players will be playing (2-4)? ");
    scanf("%d", &players);
    printf("\n");

    // input loan details
    printf("Player 1, please enter the loan amount: ");
    scanf("%f", &principal);
    printf("Player 1, please enter the interest rate (as a decimal): ");
    scanf("%f", &interest_rate);
    printf("Player 1, please enter the number of monthly payments: ");
    scanf("%d", &num_payments);
    printf("\n");

    balance = principal;

    // calculate monthly payment
    monthly_payment = (interest_rate * principal) / (1 - pow(1 + interest_rate, -num_payments));

    // start game
    int turn = 1;

    while (balance > 0) {

        printf("It's Player %d's turn\n", turn);

        // ask player to input payment amount
        float payment;
        printf("Player %d, please enter your monthly payment: ", turn);
        scanf("%f", &payment);

        // check if payment is valid
        if (payment > balance) {
            printf("Invalid payment amount. Please enter an amount less than or equal to the balance.\n");
            continue;
        }

        // apply payment to balance
        balance -= payment;

        // calculate interest for the month
        float interest = balance * interest_rate;

        // add interest to balance
        balance += interest;

        // print results for the month
        printf("Balance after payment: $%.2f\n", balance);
        printf("Interest paid: $%.2f\n", interest);
        printf("\n");

        // check if game is over
        if (balance <= 0) {
            printf("Player %d wins!!\n", turn);
            break;
        }

        // switch to next player
        turn++;
        if (turn > players) {
            turn = 1;
        }

    }

    printf("Thanks for playing!\n");

    return 0;

}