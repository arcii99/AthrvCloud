//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

void add_medicine(struct medicine* inventory, int quantity) {
    for(int i=0; i<quantity; i++) {
        printf("Enter medicine id: ");
        scanf("%d", &inventory[i].id);
        printf("Enter medicine name: ");
        scanf("%s", inventory[i].name);
        printf("Enter medicine quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Enter medicine price: ");
        scanf("%f", &inventory[i].price);
    }
}

void display_medicine(struct medicine* inventory, int quantity) {
    printf("Medicine Inventory:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<quantity; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_medicine(struct medicine* inventory, int quantity, char name[]) {
    printf("Search Results:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<quantity; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void sell_medicine(struct medicine* inventory, int quantity, int id, int sell_quantity) {
    for(int i=0; i<quantity; i++) {
        if(inventory[i].id == id) {
            if(inventory[i].quantity >= sell_quantity) {
                inventory[i].quantity -= sell_quantity;
                printf("%d %s sold for %.2f\n", sell_quantity, inventory[i].name, sell_quantity*inventory[i].price);
            } else {
                printf("Insufficient stock for %s\n", inventory[i].name);
            }
            return;
        }
    }

    printf("Medicine not found!\n");
}

int main() {
    int inventory_size;
    printf("Enter Inventory Size: ");
    scanf("%d", &inventory_size);

    struct medicine* inventory = (struct medicine*)malloc(inventory_size*sizeof(struct medicine));

    int choice;
    do {
        printf("\nMenu\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine(inventory, inventory_size);
                break;
            case 2:
                display_medicine(inventory, inventory_size);
                break;
            case 3:
                char name[50];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_medicine(inventory, inventory_size, name);
                break;
            case 4:
                int id, sell_quantity;
                printf("Enter medicine id: ");
                scanf("%d", &id);
                printf("Enter quantity to sell: ");
                scanf("%d", &sell_quantity);
                sell_medicine(inventory, inventory_size, id, sell_quantity);
                break;
            case 5:
                printf("Exiting ...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    free(inventory);

    return 0;
}