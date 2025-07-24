//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <string.h>

//Struct to store the bill information
typedef struct {
    char item_name[100];
    double price;
    int quantity;
} Bill_Item;

int main(){
    int num_items;
    double total=0;
    printf("Welcome to the Cafe Billing System!\n");
    printf("How many items are on the bill?\n");
    scanf("%d",&num_items);
    
    //Create the Bill_Items array to store the information for each item on the bill
    Bill_Item bill_items[num_items];
    for(int i=0;i<num_items;i++){
        char item_name[100];
        double price;
        int quantity;
        printf("Enter the name of item %d: \n",i+1);
        scanf("%s", item_name);
        printf("Enter the price of item %d: \n",i+1);
        scanf("%lf", &price);
        printf("Enter the quantity of item %d: \n",i+1);
        scanf("%d", &quantity);
        //Populate the array with the information for the current item
        strcpy(bill_items[i].item_name, item_name);
        bill_items[i].price = price;
        bill_items[i].quantity = quantity;
    }
    
    //Print the bill
    printf("\n\nHere is your bill:\n");
    printf("%-30s%-10s%-10s%-10s\n","Item","Price","Quantity","Total");
    for(int i=0;i<num_items;i++){
        printf("%-30s%-10.2f%-10d%-10.2f\n",bill_items[i].item_name,bill_items[i].price,bill_items[i].quantity,bill_items[i].quantity*bill_items[i].price);
        //Add up the total price for all items
        total += bill_items[i].quantity*bill_items[i].price;
    }
    
    printf("\n\nThe total bill is %.2f\n",total);
    printf("Thank you for using the Cafe Billing System!\n");
    return 0;
}