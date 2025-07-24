//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>

int main()
{
    float income, savings, expenses;
    int age, retirement_age, years_to_retire, savings_goal;
    
    printf("Enter your current age: ");
    scanf("%d", &age);
    
    printf("Enter your current annual income: $");
    scanf("%f", &income);
    
    printf("Enter your current annual expenses: $");
    scanf("%f", &expenses);
    
    printf("Enter the age at which you wish to retire: ");
    scanf("%d", &retirement_age);
    
    printf("Enter your savings goal: $");
    scanf("%d", &savings_goal);
    
    savings = income - expenses;
    years_to_retire = retirement_age - age;
    float total_savings = savings * years_to_retire;
    
    if(total_savings >= savings_goal){
        printf("Congratulations! You have met your savings goal.\n");
    }else{
        printf("You need to save $%.2f more to meet your savings goal.\n", (savings_goal - total_savings));
    }
    
    float monthly_savings = (savings_goal - total_savings) / (years_to_retire * 12);
    printf("To meet your savings goal, you should save $%.2f each month.\n", monthly_savings);
    
    return 0;
}