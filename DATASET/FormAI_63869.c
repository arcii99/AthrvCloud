//FormAI DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Struct to store expense data
struct Expense {
    int id;
    float amount;
    char description[100];
    char date[11];
};

//Struct to store user data
struct User {
    char name[50];
    char email[50];
    char password[20];
    int id;
};

//Function to create and store new user
struct User createUser(char name[], char email[], char password[], int id) {
    struct User user;
    strcpy(user.name, name);
    strcpy(user.email, email);
    strcpy(user.password, password);
    user.id = id;
    return user;
}

//Function to create and store new expense
struct Expense createExpense(float amount, char description[], char date[], int id) {
    struct Expense expense;
    expense.amount = amount;
    strcpy(expense.description, description);
    strcpy(expense.date, date);
    expense.id = id; 
    return expense;
}

//Function to print all expenses
void printAllExpenses(struct Expense expenses[], int len) {
    printf("\nAll expenses:\n");
    printf("ID  Amount  Description  Date\n");
    printf("--------------------------------\n");
    for(int i=0;i<len;i++) {
        printf("%d   %.2f    %s  %s\n",expenses[i].id,expenses[i].amount,expenses[i].description,expenses[i].date);
    }
}

//Function to print expenses of a particular date
void printExpensesByDate(struct Expense expenses[], int len, char search[]) {
    printf("\nExpenses on %s\n",search);
    printf("ID  Amount  Description\n");
    printf("-------------------------\n");
    for(int i=0;i<len;i++) {
        if(strcmp(expenses[i].date, search) == 0) {
            printf("%d   %.2f    %s\n",expenses[i].id,expenses[i].amount,expenses[i].description);
        }
    }
}

//Function to print expenses within a certain date range
void printExpensesByDateRange(struct Expense expenses[], int len, char start[], char end[]) {
    printf("\nExpenses between %s to %s\n",start, end);
    printf("ID  Amount  Description  Date\n");
    printf("--------------------------------\n");
    for(int i=0;i<len;i++) {
        if(strcmp(expenses[i].date, start) >= 0 && strcmp(expenses[i].date, end) <= 0) {
            printf("%d   %.2f    %s  %s\n",expenses[i].id,expenses[i].amount,expenses[i].description,expenses[i].date);
        }
    }
}

int main() {
    struct User user = createUser("John Doe","johndoe@example.com","1234",1);
    printf("Welcome %s!\n",user.name);
    
    //initializing expenses
    struct Expense expenses[5];
    expenses[0] = createExpense(100, "Grocery shopping","2021-10-20",1);
    expenses[1] = createExpense(50, "Dinner at restaurant","2021-10-21",2);
    expenses[2] = createExpense(200, "Movie tickets","2021-10-22",3);
    expenses[3] = createExpense(50, "Coffee with friends","2021-10-22",4);
    expenses[4] = createExpense(300, "Weekend trip","2021-10-23",5);
    
    //Printing all expenses
    printAllExpenses(expenses,5);
    
    //Printing expenses on a specific date
    printExpensesByDate(expenses,5,"2021-10-22");
    
    //Printing expenses within date range
    printExpensesByDateRange(expenses,5,"2021-10-20","2021-10-22");
    
    return 0;
}