//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int principal, years;
    float rate, interest, total;

    printf("O Romeo, what is the principal amount of thy mortgage?\n");
    scanf("%d", &principal);
    
    printf("And, how many years will thou pay thy dues?\n");
    scanf("%d", &years);
    
    printf("My dear Juliet, what is the interest rate on thy mortgage?\n");
    scanf("%f", &rate);
    
    interest = principal * (rate / 100);
    total = principal + interest;

    printf("O Romeo, thy total payable amount is %.2f, including an interest of %.2f, with payments spread over %d years.\n", total, interest, years);
    printf("Thus, thy monthly payment shall be %.2f, O Juliet the fair maid.\n", total / (years * 12));

    return 0;
}