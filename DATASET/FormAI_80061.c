//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Structures for Menu and Bill*/
typedef struct Menu {
    int id;
    char name[50];
    float price;
}Menu;

typedef struct Bill {
    int id;
    char name[50];
    int quantity;
    float price;
}Bill;

/*Function to display menu*/
void display_menu(Menu m[]) {
    printf("\n\t\tMENU\n");
    printf("*******************************************\n");
    printf("|\tID\t|\tName\t|\tPrice\t|\n");
    printf("*******************************************\n");
    
    for(int i=0; i<5; i++) {
        printf("|\t%d\t|\t%s\t|\t%.2f\t|\n", m[i].id, m[i].name, m[i].price);
    }
    
    printf("*******************************************\n");
}

/*Function to calculate total bill*/
float calculate_bill(Bill b[], int n) {
    float total = 0;
    printf("\n\t\tBILL\n");
    printf("*******************************************\n");
    printf("|\tID\t|\tName\t|\tQuantity|\tPrice\t|\n");
    printf("*******************************************\n");
    
    for(int i=0; i<n; i++) {
        printf("|\t%d\t|\t%s\t|\t%d\t|\t%.2f\t|\n", b[i].id, b[i].name, b[i].quantity, b[i].price);
        total += b[i].price;
    }
    
    printf("*******************************************\n");
    printf("|\t\t\tTotal: \t%.2f\t|\n", total);
    printf("*******************************************\n");
    
    return total;
}

/*Main function*/
int main() {
    Menu menu[5]; //Array of Menu structure
    Bill bill[10]; //Array of Bill structure
    int choice, ind, bill_count = 0;
    float total_bill = 0;
    
    /*Initializing menu items*/
    menu[0].id = 1;
    strcpy(menu[0].name, "Cold Coffee");
    menu[0].price = 80;
    
    menu[1].id = 2;
    strcpy(menu[1].name, "Hot Coffee");
    menu[1].price = 60;
    
    menu[2].id = 3;
    strcpy(menu[2].name, "Espresso");
    menu[2].price = 100;
    
    menu[3].id = 4;
    strcpy(menu[3].name, "Cappuccino");
    menu[3].price = 120;
    
    menu[4].id = 5;
    strcpy(menu[4].name, "Latte");
    menu[4].price = 150;
    
    /*Displaying Menu*/
    display_menu(menu);
    
    /*Taking Customer Orders*/
    printf("\nEnter 0 to exit.\n");
    while(1) {
        printf("\nEnter item id: ");
        scanf("%d", &choice);
        
        if(choice==0) break;
        else if(choice<1 || choice>5) {
            printf("Invalid input! Please try again.\n");
            continue;
        }
        else {
            ind = choice-1;
            strcpy(bill[bill_count].name, menu[ind].name);
            bill[bill_count].id = menu[ind].id;
            bill[bill_count].price = menu[ind].price;
            
            printf("Enter quantity: ");
            scanf("%d", &bill[bill_count].quantity);
            bill[bill_count].price *= bill[bill_count].quantity;
            bill_count++;
        }
    }
    
    /*Calculating Total Bill*/
    total_bill = calculate_bill(bill, bill_count);
    
    printf("Thanks for Visiting. Please come again.\n");
    
    return 0;
}