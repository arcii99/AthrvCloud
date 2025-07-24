//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Expense{
    float cost;
    char description[100];
    struct tm *time;
}expenses[100]; //creating expenses array

int main(){
    int num_expenses = 0;
    char answer;
    do{
        system("clear"); //clearing the screen
        printf("Expense Tracker\n");
        printf("================\n\n");
        printf("Enter expense:\n");
        scanf("%f", &expenses[num_expenses].cost);
        printf("Enter description:\n");
        scanf("%s", &expenses[num_expenses].description);

        //getting current time
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        expenses[num_expenses].time = timeinfo;

        num_expenses++;

        printf("\nDo you want to enter another expense?(y/n)\n");
        scanf(" %c", &answer);
    }while(answer == 'y');

    printf("\nExpense List\n");
    printf("=============\n\n");
    for(int i=0; i<num_expenses; i++){
        printf("Expense #%d\n",i+1);
        printf("Cost: %.2f\n",expenses[i].cost);
        printf("Description: %s\n",expenses[i].description);
        printf("Date and Time: %s",asctime(expenses[i].time));
        printf("\n");
    }
    return 0;
}