//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    float income, expenses, savings;
    
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    savings = income - expenses;
    
    if (savings > 0) { 
        printf("You saved $%.2f this month!\n", savings);
    } 
    else if (savings < 0) { 
        printf("You spent $%.2f more than you earned this month. You should seriously consider cutting down on your expenses.\n", -1*savings);
    }
    else { 
        printf("You broke even this month. Good job!\n");
    } 
    
    return 0; 
}