//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int price;
    int quantity;
};

int main() {
    int num_items;
    printf("Enter the number of items ordered: ");
    scanf("%d", &num_items);
    
    struct item items[num_items];

    for(int i=0; i<num_items; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        
        printf("Enter the price of item %d: ", i+1);
        scanf("%d", &items[i].price);
        
        printf("Enter the quantity of item %d: ", i+1);
        scanf("%d", &items[i].quantity);
    }

    int total_bill = 0;
    printf("\nItem\t\tQuantity\tPrice\t\tTotal\n");
    for(int i=0; i<num_items; i++) {
        int item_total = items[i].price * items[i].quantity;
        printf("%s\t\t%d\t\t%d\t\t%d\n", items[i].name, items[i].quantity, items[i].price, item_total);
        total_bill += item_total;
    }

    printf("\nTotal bill: $%d", total_bill);
    return 0;
}