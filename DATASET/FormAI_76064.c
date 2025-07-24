//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ITEMS 100 // Maximum number of items in the menu

typedef struct menuItem{ // structure to hold information about the menu item
    char itemName[50];
    int itemCode;
    float itemPrice;
}menuItem;

struct menuItem Menu[MAX_ITEMS]; // Array of menuItems
int numItems = 0; // number of items in the menu currently

void addItemToMenu(){ // function to add items to the menu
    printf("Enter item name: ");
    fgets(Menu[numItems].itemName, 50, stdin);
    Menu[numItems].itemName[strcspn(Menu[numItems].itemName, "\n")] = 0; // removes newline character

    printf("Enter item code: ");
    scanf("%d",&Menu[numItems].itemCode);

    printf("Enter item price: ");
    scanf("%f",&Menu[numItems].itemPrice);
    getchar(); // removes trailing newline character from scanf

    numItems++;
}

void displayMenu(){ // function to display the full menu
    printf("The menu is:\n");
    printf("#\tItem Name\t\tCode\tPrice\n");
    for(int i=0; i<numItems; i++){
        printf("%d\t%-20s\t%d\t%.2f\n", i+1, Menu[i].itemName, Menu[i].itemCode, Menu[i].itemPrice); // display item information
    }
}

int main(){
    int choice = 0; // user choice for the menu
    int order[MAX_ITEMS]; // array to hold order
    int qty[MAX_ITEMS]; // array to hold quantity of each item in the order
    int numOrders = 0; // number of items in the order
    float totalCost = 0.0; // total cost of the order
    char again[10] = "yes"; // user input for wanting to order again

    while(strcmp(again, "yes") == 0){ // loop until the user doesn't want to order anymore
        printf("Welcome to the cafe. What would you like to do?\n1. Add item to menu\n2. Display menu\n3. Place order\n");
        scanf("%d", &choice);
        getchar(); // removes trailing newline character from scanf

        switch(choice){
            case 1:
                addItemToMenu(); // add item to menu
                break;
            
            case 2:
                displayMenu(); // display full menu
                break;

            case 3:
                printf("Place your order. Enter -1 to stop adding items.\n");

                int i = 0;
                int code = 0;
                while(i<MAX_ITEMS){ // while loop to add multiple items to the order
                    printf("Enter item code for item %d: ", i+1);
                    scanf("%d",&code);
                    if(code == -1){ // -1 means no more items to add
                        break;
                    }

                    int idx = -1;
                    for(int j=0; j<numItems; j++){ 
                        if(Menu[j].itemCode == code){ // if the item exists in the menu
                            idx = j;
                            break;
                        }
                    }
                    if(idx == -1){ // if the item doesn't exist in the menu
                        printf("Item not found in the menu. Please try again.\n");
                        continue;
                    }

                    printf("Enter quantity for item %d: ", i+1);
                    scanf("%d",&qty[i]);

                    totalCost += qty[i]*Menu[idx].itemPrice; // add to the total cost of the order

                    order[i] = idx; // add item index to the order array
                    i++;
                }

                numOrders = i-1; // number of items in the order

                // Display the order summary
                printf("The order summary is:\n");
                printf("#\tItem Name\t\tQty\tPrice\n");
                for(int j=0; j<numOrders; j++){
                    printf("%d\t%-20s\t%d\t%.2f\n", j+1, Menu[order[j]].itemName, qty[j], qty[j]*Menu[order[j]].itemPrice);
                }
                printf("Total cost = %.2f\n", totalCost);
                
                printf("Would you like to order again? (yes/no) ");
                fgets(again, 10, stdin);
                again[strcspn(again, "\n")] = 0; // removes newline character
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    printf("Thank you for visiting the cafe!\n");
    return 0;
}