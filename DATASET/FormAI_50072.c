//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

/*Defining structure for expenses*/
struct expenses{
   char category[20];
   float amount;
};

/*Function to calculate total monthly expenses*/
float calculate_expenses(struct expenses expense_list[], int num_expenses){
   float total_expenses = 0;
   int i;
   for(i=0; i<num_expenses; i++){
      total_expenses += expense_list[i].amount;
   }
   return total_expenses;
}

/*Main function*/
int main(){
   int num_expenses,i;
   printf("---Personal Finance Planner---\n\n");
   printf("How many categories of expenses do you have? ");
   scanf("%d",&num_expenses);
   
   /*Dynamic allocation of memory*/
   struct expenses *expense_list;
   expense_list = (struct expenses*) malloc(num_expenses*sizeof(struct expenses));
   
   /*Inputting category-wise expenses*/
   for(i=0; i<num_expenses; i++){
      printf("\nEnter category %d name: ", i+1);
      scanf("%s",&expense_list[i].category);
      printf("Enter the amount spent: ");
      scanf("%f",&expense_list[i].amount);
   }
   
   /*Calculating and displaying total monthly expenses*/
   printf("\n---Monthly Expenses---\n");
   float total_expenses = calculate_expenses(expense_list,num_expenses);
   printf("Total monthly expenses: %.2f",total_expenses);
   
   /*Freeing allocated memory*/
   free(expense_list);
   return 0;
}