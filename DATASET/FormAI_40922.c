//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    double principal, interest, rate;
    int years;

    printf("Oh love, thou art my mortgage,\n");
    printf("A debt that I must ever bear;\n");
    printf("But fear not, my dear Juliet,\n");
    printf("For I shall pay it, do not despair.\n\n");
    printf("What is the principal, my sweet?\n");
    scanf("%lf", &principal);
    printf("And what is the interest rate, my dove?\n");
    scanf("%lf", &interest);
    printf("And how many years must we be wed, my love?\n");
    scanf("%d", &years);

    rate = interest / 100;

    double monthlyPayment = (principal * rate / 12) /
                            (1 - pow(1 + rate / 12, -years * 12));
    double totalPayment = monthlyPayment * years * 12;
    double totalInterest = totalPayment - principal;

    printf("\nI have calculated the mortgage, my love,\n");
    printf("Our monthly payment shall be %0.2f,\n", monthlyPayment);
    printf("And over the course of %d years, we shall pay\n", years);
    printf("A total of %0.2f, with %0.2f of it in interest.\n", 
            totalPayment, totalInterest);
    
    printf("\nOh what relief, my sweet Juliet,\n");
    printf("That our mortgage has been calculated right;\n");
    printf("And now we may together rest,\n");
    printf("Eternally happy, forever blessed.\n");

    return 0;
}