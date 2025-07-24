//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Structure to store the details of a menu item
struct MenuItem{
    char name[50];
    int quantity;
    float price;
};

// Function to display the menu
void showMenu(struct MenuItem menu[], int n){
    printf("\n------------------- MENU -------------------\n");
    printf("ITEM NAME\tQUANTITY\tPRICE\n");
    for(int i=0; i<n; i++){
        printf("%s\t\t%d\t\t%.2f\n", menu[i].name, menu[i].quantity, menu[i].price);
    }
}

// Function to add an item to the bill
void addItem(char name[], float price, struct MenuItem bill[], int *count){
    strcpy(bill[*count].name, name);
    bill[*count].price = price;
    bill[*count].quantity = 1;
    (*count)++;
}

// Function to remove an item from the bill
void removeItem(int index, struct MenuItem bill[], int *count){
    for(int i=index; i<(*count)-1; i++){
        bill[i] = bill[i+1];
    }
    (*count)--;
}

// Function to display the bill
float showBill(struct MenuItem bill[], int n){
    float totalPrice = 0;
    printf("\n------------------- BILL -------------------\n");
    printf("ITEM NAME\tQUANTITY\tPRICE\n");
    for(int i=0; i<n; i++){
        printf("%s\t\t%d\t\t%.2f\n", bill[i].name, bill[i].quantity, bill[i].price);
        totalPrice += (bill[i].price * bill[i].quantity);
    }
    printf("\nTOTAL PRICE: %.2f\n", totalPrice);
    return totalPrice;
}

int main(){
    // Initializing the menu
    struct MenuItem menu[] = {
        {"Idli", 10, 25.0},
        {"Dosa", 20, 40.0},
        {"Vada", 15, 20.0},
        {"Puri", 10, 30.0},
        {"Coffee", 25, 15.0},
        {"Tea", 30, 10.0},
    };
    int n = sizeof(menu)/sizeof(menu[0]);

    // Initializing the bill
    struct MenuItem bill[100];
    int count = 0;

    // Displaying the menu
    showMenu(menu, n);

    // Taking orders from the customer
    printf("\nEnter the items you want to order (q to quit):\n");
    char itemName[50];
    scanf("%s", itemName);
    while(strcmp(itemName, "q")!=0){

        // Searching for the item in the menu
        int index = -1;
        for(int i=0; i<n; i++){
            if(strcmp(itemName, menu[i].name)==0){
                index = i;
                break;
            }
        }
        if(index==-1){
            printf("Item not found in the menu.\n");
        }
        else{
            addItem(menu[index].name, menu[index].price, bill, &count);
            menu[index].quantity--;
            printf("%s added to your bill.\n", menu[index].name);
        }
        scanf("%s", itemName);
    }

    // Displaying the bill
    float totalPrice = showBill(bill, count);

    // Taking payment from the customer
    float paidAmount;
    printf("\nEnter the amount paid by the customer: ");
    scanf("%f", &paidAmount);
    while(paidAmount<totalPrice){
        printf("Amount paid is insufficient. Please enter the correct amount.\n");
        scanf("%f", &paidAmount);
    }

    // Printing the change to be given
    float change = paidAmount - totalPrice;
    printf("\nChange to be given: %.2f\n", change);

    return 0;
}