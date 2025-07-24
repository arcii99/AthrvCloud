//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct expenditure{
    char category_name[20];
    float amount_spent;
}Exp;

int main(){
    int choice = 0, num_of_categories = 0;
    float total_expense = 0;

    printf("Enter the number of categories for tracking\n");
    scanf("%d", &num_of_categories);

    Exp category[num_of_categories];
    
    while(choice != 3){
        printf("\nChoose an option\n");
        printf("1. Add an expense\n");
        printf("2. View total expense\n");
        printf("3. Exit\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                for(int i = 0; i < num_of_categories; i++){
                    printf("Enter amount spent for %s category: ", category[i].category_name);
                    scanf("%f", &category[i].amount_spent);
                    total_expense += category[i].amount_spent;
                    printf("\n");
                }
                break;
            }
            case 2:{
                printf("Total money spent: $%0.2f\n", total_expense);
                for(int i = 0; i < num_of_categories; i++){
                    printf("%s money spent: $%0.2f (%.2f%% of total expense)\n", category[i].category_name, category[i].amount_spent, (category[i].amount_spent/total_expense)*100);
                }
                break;
            }
            case 3:{
                printf("Exiting Program\n");
                exit(0);
            }
            default: printf("Invalid choice. Enter again.\n");
        }
    }

    return 0;
}