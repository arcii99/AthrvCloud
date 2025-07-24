//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_EXPENSES 100 //Maximum number of expenses to track

int main(){
    int num_expenses = 0;
    double expenses[MAX_EXPENSES];
    char choice;

    //Main menu
    do{
        printf("Expense Tracker\n");
        printf("A - Add an expense\n");
        printf("R - Remove an expense\n");
        printf("S - Show all expenses\n");
        printf("E - Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        choice = toupper(choice); //Convert choice to uppercase

        switch(choice){
            case 'A':
                if(num_expenses < MAX_EXPENSES){ //Check if array is full
                    printf("Enter expense amount: ");
                    scanf("%lf", &expenses[num_expenses]);
                    num_expenses++;
                    printf("Expense added successfully!\n");
                }
                else{
                    printf("Maximum number of expenses reached. Cannot add any more expenses.\n");
                }
                break;

            case 'R':
                if(num_expenses > 0){ //Check if array is empty
                    int index = -1;
                    double expense = 0;

                    while(index < 0 || index >= num_expenses){ //Loop until a valid index is entered
                        printf("Enter index of expense to remove (0-%d): ", num_expenses-1);
                        scanf("%d", &index);
                    }

                    expense = expenses[index];

                    for(int i=index; i<num_expenses-1; i++){ //Shift remaining expenses one index to the left
                        expenses[i] = expenses[i+1];
                    }

                    num_expenses--;

                    printf("Expense %.2lf removed successfully!\n", expense);
                }
                else{
                    printf("No expenses to remove.\n");
                }
                break;

            case 'S':
                if(num_expenses > 0){ //Check if array is empty
                    printf("Expenses:\n");
                    for(int i=0; i<num_expenses; i++){
                        printf("%d. %.2lf\n", i, expenses[i]);
                    }
                }
                else{
                    printf("No expenses to show.\n");
                }
                break;

            case 'E':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option (A, R, S, or E).\n");
                break;
        }

        printf("----------------------------------------\n");

    }while(choice != 'E'); //Exit loop when 'E' is entered

    return 0;
}