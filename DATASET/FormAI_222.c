//FormAI DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include<stdio.h>

int calcExpenses(int n, int* expenses){
    if(n == 0){
        return 0;
    }
    return expenses[n-1] + calcExpenses(n-1, expenses);
}

int main(){
    int n;
    printf("Enter the number of expenses: ");
    scanf("%d", &n);
    int expenses[n];
    printf("Enter the expenses: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &expenses[i]);
    }
    printf("Total expenses: %d", calcExpenses(n, expenses));
    return 0;
}