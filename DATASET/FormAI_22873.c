//FormAI DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#define MAX_EXPENSES 100

int main(){
    float expenses[MAX_EXPENSES];
    int count = 0;
    float total = 0, average = 0, variance = 0, std_deviation = 0;
    char choice;
    
    printf("-------------------- Expense Tracker --------------------\n");
    
    do{
        printf("Enter expense amount: ");
        scanf("%f", &expenses[count]);

        total += expenses[count];
        count++;

        if(count == MAX_EXPENSES){
            printf("Maximum number of expenses reached.\n");
            break;
        }

        printf("Add another expense? (Y/N): ");
        scanf(" %c", &choice);
    } while(choice == 'Y' || choice == 'y');

    average = total / count;
    
    for(int i = 0; i < count; i++){
        variance += ((expenses[i] - average) * (expenses[i] - average));
    }
    variance /= count;
    std_deviation = sqrt(variance);

    printf("\n--------------------- Expense Summary -------------------\n");
    printf("Total expenses: $%.2f\n", total);
    printf("Average expense: $%.2f\n", average);
    printf("Variance: %.2f\n", variance);  
    printf("Standard deviation: %.2f\n", std_deviation);      

    return 0;
}