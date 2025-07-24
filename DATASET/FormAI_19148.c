//FormAI DATASET v1.0 Category: Expense Tracker ; Style: protected
#include<stdio.h>
#include<stdlib.h>

struct expense{
    char item[20];
    float cost;
    char category[10];
};

int main(){
    int n, i, total=0;
    printf("Enter the number of expenses: ");
    scanf("%d", &n);
    struct expense expenses[n]; //Array of expenses

    //Taking input
    for(i=0;i<n;i++){
        printf("\nEnter item name: ");
        scanf("%s", expenses[i].item);
        printf("Enter cost: ");
        scanf("%f", &expenses[i].cost);
        total += expenses[i].cost; //Calculating total expenses
        printf("Enter category: ");
        scanf("%s", expenses[i].category);
    }

    //Displaying the expenses
    printf("\n%20s %15s %15s\n", "Item", "Cost", "Category");
    for(i=0;i<n;i++){
        printf("%20s %15.2f %15s\n", expenses[i].item, expenses[i].cost, expenses[i].category);
    }
    printf("\nTotal expenses: %d\n", total);
    return 0;
}