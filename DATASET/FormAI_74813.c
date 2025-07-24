//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: portable
#include<stdio.h>

int main()
{
    float salary, expenses, saved_money, total_saved = 0;
    int year;
    
    printf("Enter your yearly salary: ");
    scanf("%f",&salary);
    
    printf("Enter your yearly expenses: ");
    scanf("%f",&expenses);
    
    printf("Enter number of years to plan: ");
    scanf("%d",&year);
    
    printf("\n\nYear\tSalary\t\tExpenses\tSaved\n");
    
    for(int i = 1; i <= year; i++)
    {
        saved_money = salary - expenses;
        total_saved += saved_money;
        
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",i, salary, expenses, saved_money);
        
        salary += (salary*(10.0/100));
        expenses += (expenses*(8.0/100));
    }
    
    printf("\n\nTotal saved money after %d years : %.2f\n", year, total_saved);
    
    return 0;
}