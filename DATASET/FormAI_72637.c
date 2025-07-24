//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Global Variables
int total_items = 0; 
float total_price = 0;
char menu_items[20][20];
float menu_prices[20];

//Function to display menu
void display_menu(){
    printf("------------------------\n");
    printf("---- Welcome to C Cafe--\n");
    printf("------------------------\n\n");

    printf("Menu: \n");
    for(int i=0;i<total_items;i++){
        printf("%d.\t%s - %f\n",i+1,menu_items[i],menu_prices[i]);
    }
    printf("\n");
}

//Function to add item to the bill
void add_item(char item[],float price){
    strcpy(menu_items[total_items],item);
    menu_prices[total_items] = price;

    printf("%s added to the bill!\n\n",item);

    total_items++;
    total_price += price;
}

//Function to print bill and exit
void print_bill(){
    printf("Total items: %d\n",total_items);
    printf("Total Price: %f\n",total_price);

    printf("\nThank you for visiting C Cafe!\n");

    exit(0);
}

int main(){

    //Adding Items to the menu
    add_item("Hot Coffee", 10.50);
    add_item("Tea", 5.50);
    add_item("Cold Coffee", 15.50);
    add_item("Sandwich", 25.50);
    add_item("Pasta", 35.50);

    //Displaying menu to the customer
    display_menu();

    while(1){

        int option;
        printf("Enter your choice (0 to exit): ");
        scanf("%d",&option);

        if(option == 0){
            print_bill();
        }
        else if(option>total_items || option<0){
            printf("Invalid Choice!\n");
        }
        else{

            //Adding selected item to the bill
            add_item(menu_items[option-1],menu_prices[option-1]);

        }

    }

    return 0;
}