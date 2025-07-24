//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stock{
    char itemName[20];
    int itemID;
    int quantity;
    float price;
}Stock;

int main(){
    int numItems;
    printf("Enter number of items in stock: ");
    scanf("%d",&numItems);
    Stock *stocks = (Stock*)malloc(numItems*sizeof(Stock));
    
    for(int i=0;i<numItems;i++){
        printf("Enter details for item %d:\n",i+1);
        printf("Item name: ");
        scanf("%s",stocks[i].itemName);
        printf("Item ID: ");
        scanf("%d",&stocks[i].itemID);
        printf("Quantity: ");
        scanf("%d",&stocks[i].quantity);
        printf("Price: ");
        scanf("%f",&stocks[i].price);
    }
    
    printf("Stocks available:\n");
    printf("%-10s %-10s %-10s %-10s\n","Item Name","Item ID","Quantity","Price");
    for(int i=0;i<numItems;i++){
        printf("%-10s %-10d %-10d %-10.2f\n",stocks[i].itemName,stocks[i].itemID,stocks[i].quantity,stocks[i].price);
    }
    free(stocks);   
    return 0;
}