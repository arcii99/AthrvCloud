//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>

int main(){
    int income, expenses, savings;
    
    printf("My love, welcome to our Personal Finance Planner.\n");
    printf("Please enter your monthly income:\n");
    scanf("%d", &income);
    
    printf("Next, enter your monthly expenses:\n");
    scanf("%d", &expenses);
    
    savings = income - expenses;
    
    printf("\nMy darling, your monthly savings are: $%d\n", savings);
    printf("This means that you can save up to $%d in a year!\n", savings*12);
    
    if(savings > 500){
        printf("Wow my love, your financial situation is amazing!\n");
        printf("You are saving a lot every month. I am so proud of you!\n");
    }
    else if(savings > 300){
        printf("My love, you are doing a great job!\n");
        printf("Your savings are good and you are on the right track!\n");
    }
    else if(savings > 100){
        printf("My love, we can do better!\n");
        printf("Let's try to reduce some of our expenses so we can save more!\n");
    }
    else{
        printf("My love, we need to work on our finances!\n");
        printf("We need to reduce our expenses and try to save more so we can achieve our financial goals!\n");
    }
    
    printf("\nThank you for using our Personal Finance Planner, my love.\n");
    printf("I will always be here to support you in your financial journey!\n");
    
    return 0;
}