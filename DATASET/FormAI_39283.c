//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double principal, rate, payment;
    int duration, guess, count = 0;
    time_t t;
    srand((unsigned) time(&t)); // seed for random interest rate

    printf("Welcome to the puzzling mortgage calculator!\n\n");
    printf("Please enter the principal amount of the mortgage: $");
    scanf("%lf", &principal);
    printf("Please enter the duration of the mortgage (in years): ");
    scanf("%d", &duration);
    printf("Great! Now it's time to guess the interest rate.\n");
    printf("Hint: the interest rate is a whole number between 1 and 10.\n\n");

    // Generate random interest rate
    rate = rand() % 10 + 1;

    do {
        printf("What is your guess for the interest rate? ");
        scanf("%d", &guess);
        count++; // increment guess count
        if (guess < rate) {
            printf("Your guess is too low!\n\n");
        } else if (guess > rate) {
            printf("Your guess is too high!\n\n");
        } else {
            printf("Congratulations! It took you %d guesses to guess the interest rate!\n\n", count);
            break; // exit loop when correct guess is made
        }
    } while (1);

    // Calculate payment with guessed interest rate
    payment = ((rate / 1200.0) * principal) / (1 - pow(1 + (rate / 1200.0), (-1 * duration * 12)));

    // Output final mortgage details
    printf("With a principal amount of $%.2lf, a duration of %d years,\n", principal, duration);
    printf("and an interest rate of %0.2lf%%, your monthly payment will be $%.2lf.\n", rate, payment);

    return 0;
}