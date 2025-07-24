//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
    int salary;
    float expenses, savingsRatio, savings, taxRate, afterTaxIncome, afterExpensesIncome;
    
    printf("Welcome to Retro Personal Finance Planner!\n\n");
    printf("Enter your monthly salary: ");
    scanf("%d", &salary);
    
    printf("\nEnter your monthly expenses: ");
    scanf("%f", &expenses);
    
    printf("\nEnter your tax rate: ");
    scanf("%f", &taxRate);
    
    taxRate = taxRate / 100;
    
    afterTaxIncome = salary - (salary * taxRate);
    afterExpensesIncome = afterTaxIncome - expenses;
    
    printf("\n\nYour monthly income after tax and expenses: %.2f\n", afterExpensesIncome);
    
    savingsRatio = (afterExpensesIncome * 100) / salary;
    printf("\n\nYour savings ratio: %.2f%\n", savingsRatio);
    
    savings = afterExpensesIncome * 12;
    printf("\n\nYour estimated yearly savings: $%.2f\n", savings);
    
    if(savingsRatio >= 20) {
        printf("\n\nGreat job! You are saving 20%% or more of your income.\n");
    }
    else if(savingsRatio >= 10) {
        printf("\n\nNot bad! But you could be saving more than 10%% of your income.\n");
    }
    else {
        printf("\n\nYou need to increase your savings rate to at least 10%%.\n");
    }
    
    return 0;
}