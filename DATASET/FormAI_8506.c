//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define Constants for expenditure categories
#define HOUSING 1
#define TRANSPORTATION 2
#define FOOD 3
#define UTILITIES 4
#define ENTERTAINMENT 5
#define OTHER 6

// Define struct for each expenditure
struct Expenditure {
   int category;
   float amount;
};

int main() {
   struct Expenditure expenses[100];  // Create an array of expenditures to store user input
   int numExpenses = 0;  // Counter to track number of expenditures entered
   float totalSpent = 0;  // Variable to store total amount spent
    
   printf("Welcome to the Personal Finance Planner! \n");
   printf("* * * * * * * * * * * * * * * * * *\n");
   
   int option;
   do {
       // Display menu options
       printf("\n\nChoose an option:\n");
       printf("1. Add an expenditure\n");
       printf("2. View all expenditures\n");
       printf("3. Calculate total spent by category\n");
       printf("4. Exit\n");
       
       // Get user input
       printf("Enter your option (1-4): ");
       scanf("%d", &option);
       
       switch(option) {
           case 1: 
               // Get user input for expenditure category and amount
               printf("\n\nEnter the category of the expenditure: \n");
               printf("%d. Housing\n", HOUSING);
               printf("%d. Transportation\n", TRANSPORTATION);
               printf("%d. Food\n", FOOD);
               printf("%d. Utilities\n", UTILITIES);
               printf("%d. Entertainment\n", ENTERTAINMENT);
               printf("%d. Other\n", OTHER);
               printf("Category: ");
               scanf("%d", &(expenses[numExpenses].category));
               printf("Amount: ");
               scanf("%f", &(expenses[numExpenses].amount));
               
               // Add expenditure to total spent and increment counter
               totalSpent += expenses[numExpenses].amount;
               numExpenses++;
               printf("Expenditure added successfully!\n");
               break;
           case 2:
               // Display all expenditures entered by user
               if(numExpenses == 0) {
                   printf("No expenditures added yet.\n");
                   break;
               }
               printf("\n\nAll expenditures:\n");
               printf("-------------------------\n");
               for(int i = 0; i < numExpenses; i++) {
                   printf("Category: ");
                   switch(expenses[i].category) {
                       case HOUSING: printf("Housing    "); break;
                       case TRANSPORTATION: printf("Transportation    "); break;
                       case FOOD: printf("Food     "); break;
                       case UTILITIES: printf("Utilities    "); break;
                       case ENTERTAINMENT: printf("Entertainment    "); break;
                       case OTHER: printf("Other    "); break;
                   }
                   printf("Amount: %f\n", expenses[i].amount);
               }
               break;
           case 3:
               // Calculate total spent by category
               float housingSpent = 0, transportSpent = 0, foodSpent = 0, 
                     utilitiesSpent = 0, entertainSpent = 0, otherSpent = 0;
               for(int i = 0; i < numExpenses; i++) {
                   switch(expenses[i].category) {
                       case HOUSING: housingSpent += expenses[i].amount; break;
                       case TRANSPORTATION: transportSpent += expenses[i].amount; break;
                       case FOOD: foodSpent += expenses[i].amount; break;
                       case UTILITIES: utilitiesSpent += expenses[i].amount; break;
                       case ENTERTAINMENT: entertainSpent += expenses[i].amount; break;
                       case OTHER: otherSpent += expenses[i].amount; break;
                   }
               }
               printf("\n\nSpending by category:\n");
               printf("-----------------------------\n");
               printf("Housing: %f\n", housingSpent);
               printf("Transportation: %f\n", transportSpent);
               printf("Food: %f\n", foodSpent);
               printf("Utilities: %f\n", utilitiesSpent);
               printf("Entertainment: %f\n", entertainSpent);
               printf("Other: %f\n", otherSpent);
               break;
           case 4:
               printf("Exiting Personal Finance Planner...\n");
               break;
           default:
               printf("Invalid option.\n");
               break;
       }
   } while(option != 4);
   
   printf("Total amount spent: %f\n", totalSpent);
   
   return 0;
}