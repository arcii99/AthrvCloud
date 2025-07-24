//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Structure for Expense Tracker
struct ExpenseTracker{
    char category[20];
    float amount;
    char date[15];
};

//Function to calculate the total expense for a given category
float calculateTotalExpense(struct ExpenseTracker expense[], int size, char category[]){
    float totalExpense = 0.0;
    for(int i=0; i<size; i++){
        if(strcmp(expense[i].category, category) == 0){
            totalExpense += expense[i].amount;
        }
    }

    return totalExpense;
}

int main(){
    //Randomizing the seed
    srand(time(0));

    //Creating an expense tracker with random values
    struct ExpenseTracker expenseTracker[10];
    strcpy(expenseTracker[0].category, "Food");
    expenseTracker[0].amount = rand() % 100;
    strcpy(expenseTracker[0].date, "03/01/2022");
    strcpy(expenseTracker[1].category, "Clothing");
    expenseTracker[1].amount = rand() % 150;
    strcpy(expenseTracker[1].date, "03/02/2022");
    strcpy(expenseTracker[2].category, "Rent");
    expenseTracker[2].amount = rand() % 500;
    strcpy(expenseTracker[2].date, "03/04/2022");
    strcpy(expenseTracker[3].category, "Transport");
    expenseTracker[3].amount = rand() % 50;
    strcpy(expenseTracker[3].date, "03/05/2022");
    strcpy(expenseTracker[4].category, "Entertainment");
    expenseTracker[4].amount = rand() % 200;
    strcpy(expenseTracker[4].date, "03/07/2022");
    strcpy(expenseTracker[5].category, "Education");
    expenseTracker[5].amount = rand() % 1000;
    strcpy(expenseTracker[5].date, "03/11/2022");
    strcpy(expenseTracker[6].category, "Travel");
    expenseTracker[6].amount = rand() % 500;
    strcpy(expenseTracker[6].date, "03/12/2022");
    strcpy(expenseTracker[7].category, "Healthcare");
    expenseTracker[7].amount = rand() % 300;
    strcpy(expenseTracker[7].date, "03/14/2022");
    strcpy(expenseTracker[8].category, "Gifts");
    expenseTracker[8].amount = rand() % 100;
    strcpy(expenseTracker[8].date, "03/18/2022");
    strcpy(expenseTracker[9].category, "Other");
    expenseTracker[9].amount = rand() % 50;
    strcpy(expenseTracker[9].date, "03/19/2022");

    //Printing the expenses in the expense tracker
    printf("Expense Tracker\n");
    printf("----------------\n");
    printf("Category\tAmount\t\tDate\n");
    for(int i=0; i<10; i++){
        printf("%s\t\t$%.2f\t%s\n", expenseTracker[i].category, expenseTracker[i].amount, expenseTracker[i].date);
    }

    //Calculating the total expense for each category
    printf("\nTotal Expenses\n");
    printf("----------------\n");
    printf("Category\tTotal Expense\n");
    printf("Food\t\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Food"));
    printf("Clothing\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Clothing"));
    printf("Rent\t\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Rent"));
    printf("Transport\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Transport"));
    printf("Entertainment\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Entertainment"));
    printf("Education\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Education"));
    printf("Travel\t\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Travel"));
    printf("Healthcare\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Healthcare"));
    printf("Gifts\t\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Gifts"));
    printf("Other\t\t$%.2f\n", calculateTotalExpense(expenseTracker, 10, "Other"));

    return 0;
}