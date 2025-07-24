//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>

// Pre-apocalyptic currency values
#define BTC_VALUE 1000
#define GOLD_VALUE 1500
#define SILVER_VALUE 50

// Post-apocalyptic currency values
#define BOTTLE_CAP_VALUE 5
#define TRASH_VALUE 1
#define MUTANT_CLAW_VALUE 10

int main() {
    double loan_amount, interest_rate;
    int num_years;

    // Pre-apocalyptic payment options
    char preapoc_payment;
    float btc_payment, gold_payment, silver_payment;

    // Post-apocalyptic payment options
    char postapoc_payment;
    int bottle_cap_payment, trash_payment, mutant_claw_payment;

    // Prompt user for loan amount
    printf("Enter loan amount: $");
    scanf("%lf", &loan_amount);

    // Prompt user for interest rate
    printf("Enter interest rate: %%");
    scanf("%lf", &interest_rate);

    // Prompt user for number of years
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    // Calculate monthly payment
    double monthly_rate = (interest_rate / 100) / 12.0;
    int num_payments = num_years * 12;
    double monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));

    // Pre-apocalyptic payment options
    printf("\nPre-Apocalyptic Payment Options:\n");
    printf("a) %d BitCoin ($%0.2f)\n", BTC_VALUE, btc_payment = monthly_payment * BTC_VALUE);
    printf("b) %d ounces of Gold ($%0.2f)\n", GOLD_VALUE, gold_payment = monthly_payment * GOLD_VALUE);
    printf("c) %d ounces of Silver ($%0.2f)\n", SILVER_VALUE, silver_payment = monthly_payment * SILVER_VALUE);

    // Post-apocalyptic payment options
    printf("\nPost-Apocalyptic Payment Options:\n");
    printf("a) %d Bottle Caps ($%d)\n", BOTTLE_CAP_VALUE, bottle_cap_payment = (int) (monthly_payment / BOTTLE_CAP_VALUE));
    printf("b) %d pieces of Trash ($%d)\n", TRASH_VALUE, trash_payment = (int) (monthly_payment / TRASH_VALUE));
    printf("c) %d Mutant Claws ($%d)\n", MUTANT_CLAW_VALUE, mutant_claw_payment = (int) (monthly_payment / MUTANT_CLAW_VALUE));

    // Prompt user for payment option
    printf("\nEnter payment option (a, b, or c): ");
    scanf(" %c", &preapoc_payment);

    // Calculate and output pre-apocalyptic total payment
    printf("\nTotal pre-apocalyptic payment: $");
    switch (preapoc_payment) {
        case 'a':
            printf("%.2f", btc_payment * num_payments);
            break;
        case 'b':
            printf("%.2f", gold_payment * num_payments);
            break;
        case 'c':
            printf("%.2f", silver_payment * num_payments);
            break;
        default:
            printf("Invalid input");
            return 1;
    }

    // Prompt user for payment option
    printf("\nEnter payment option (a, b, or c): ");
    scanf(" %c", &postapoc_payment);

    // Calculate and output post-apocalyptic total payment
    printf("\nTotal post-apocalyptic payment: $");
    switch (postapoc_payment) {
        case 'a':
            printf("%d", bottle_cap_payment * num_payments);
            break;
        case 'b':
            printf("%d", trash_payment * num_payments);
            break;
        case 'c':
            printf("%d", mutant_claw_payment * num_payments);
            break;
        default:
            printf("Invalid input");
            return 1;
    }

    return 0;
}