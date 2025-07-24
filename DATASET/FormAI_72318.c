//FormAI DATASET v1.0 Category: Product Inventory System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int code;
    float price;
    int quantity;
} items[100];

int num_items = 0;

void add_item() {
    printf("Enter product name: ");
    scanf("%s", items[num_items].name);
    printf("Enter product code: ");
    scanf("%d", &items[num_items].code);
    printf("Enter product price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter product quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void update_item() {
    int code, index;
    printf("Enter product code: ");
    scanf("%d", &code);
    for(int i=0; i<num_items; i++) {
        if(items[i].code == code) {
            index = i;
            break;
        }
    }
    printf("Enter product quantity: ");
    scanf("%d", &items[index].quantity);
}

void remove_item() {
    int code, index;
    printf("Enter product code: ");
    scanf("%d", &code);
    for(int i=0; i<num_items; i++) {
        if(items[i].code == code) {
            index = i;
            break;
        }
    }
    for(int i=index; i<num_items-1; i++) {
        strcpy(items[i].name, items[i+1].name);
        items[i].code = items[i+1].code;
        items[i].price = items[i+1].price;
        items[i].quantity = items[i+1].quantity;
    }
    num_items--;
}

void display_items() {
    printf("\nProduct Inventory Details:\n\n");
    printf("Name\tCode\tQuantity\tPrice\n");
    for(int i=0; i<num_items; i++) {
        printf("%s\t%d\t%d\t\t%.2f\n", items[i].name, items[i].code, items[i].quantity, items[i].price);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("Product Inventory System\n\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Remove Item\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                update_item();
                break;
            case 3:
                remove_item();
                break;
            case 4:
                display_items();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!=5);
    return 0;
}