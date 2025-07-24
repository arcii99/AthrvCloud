//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine { //defining the structure of medicines in the store
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

void addMedicine(struct medicine store[], int count) { //function to add new medicine in the store
    printf("\nEnter the following details of the medicine to be added -\n");
    printf("Name: ");
    scanf("%s", store[count].name);
    printf("Manufacturer: ");
    scanf("%s", store[count].manufacturer);
    printf("Price: ");
    scanf("%f", &store[count].price);
    printf("Quantity: ");
    scanf("%d", &store[count].quantity);
}

void displayMedicine(struct medicine store[], int count) { //function to display the medicines available in the store
    printf("\nMedicine List -\n");
    for(int i=0; i<count; i++) {
        printf("\n%d. Name: %s | Manufacturer: %s | Price: %.2f | Quantity: %d", i+1, store[i].name, store[i].manufacturer, store[i].price, store[i].quantity);
    }
}

void searchMedicine(struct medicine store[], int count) { //function to search for a specific medicine in the store
    char name[50];
    int flag = 0;
    printf("\nEnter the name of the medicine to be searched: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(store[i].name, name) == 0) {
            printf("\nMedicine found at position %d -\n", i+1);
            printf("Name: %s | Manufacturer: %s | Price: %.2f | Quantity: %d", store[i].name, store[i].manufacturer, store[i].price, store[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("\nMedicine not found in store.");
}

void sellMedicine(struct medicine store[], int count) { //function to sell a medicine from the store
    char name[50];
    int flag = 0, quantity;
    printf("\nEnter the name of the medicine to be sold: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(store[i].name, name) == 0) {
            printf("Medicine found at position %d -\n", i+1);
            printf("Name: %s | Manufacturer: %s | Price: %.2f | Quantity: %d\n", store[i].name, store[i].manufacturer, store[i].price, store[i].quantity);
            printf("Enter the quantity to be sold: ");
            scanf("%d", &quantity);
            if(quantity > store[i].quantity) {
                printf("Requested quantity not available in store.");
                flag = 1;
                break;
            }
            else {
                printf("Total price to be paid: %.2f\n", store[i].price*quantity);
                store[i].quantity -= quantity;
                flag = 2;
                break;
            }
        }
    }
    if(flag == 0)
        printf("Medicine not found in store.");
    else if(flag == 2)
        printf("Medicine sold successfully.");
}

int main() {
    printf("########## C Medical Store Management System ##########\n");

    struct medicine store[50]; //maximum limit of medicines store can keep is 50
    int choice, count = 0;

    while(1) { //menu driven program loop
        printf("\n\n---------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Sell Medicine\n");
        printf("5. Exit\n");
        printf("---------------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(store, count);
                count++;
                break;
            case 2:
                displayMedicine(store, count);
                break;
            case 3:
                searchMedicine(store, count);
                break;
            case 4:
                sellMedicine(store, count);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}