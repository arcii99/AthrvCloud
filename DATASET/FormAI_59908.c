//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines in the store
#define MAX_MEDICINES 50

// Define the maximum number of characters for name and brand
#define MAX_CHARACTERS 20

// Define the maximum number of characters for generic name
#define MAX_GENERIC_NAME 30

typedef struct {
    char name[MAX_CHARACTERS];
    char brand[MAX_CHARACTERS];
    char genericName[MAX_GENERIC_NAME];
    float price;
    int quantity;
} Medicine;

void initialize(Medicine store[]) {
    // Some funny initialization message
    printf("Initializing Store...\n");
    printf("Please wait while we summon the magical medicine elves to populate our store!\n");
    printf("10...9...8...7...6...5...4...3...2...1... Abra-kadabra! *Poof*\n");

    // Randomly generate store items
    srand(0);
    for (int i = 0; i < MAX_MEDICINES; i++) {
        Medicine medicine;
        char* names[] = {"Aspirin", "Tylenol", "Advil", "Benadryl", "Motrin", "Aleve"};
        strcpy(medicine.name, names[rand() % 6]);
        char* brands[] = {"Johnson & Johnson", "Pfizer", "Roche", "Abbott", "GSK", "Merck"};
        strcpy(medicine.brand, brands[rand() % 6]);
        char* genericNames[] = {"Acetaminophen", "Ibuprofen", "Diphenhydramine", "Naproxen", "Doxylamine"};
        strcpy(medicine.genericName, genericNames[rand() % 5]);
        medicine.price = (float) ((rand() % 5000) + 100) / 100;
        medicine.quantity = rand() % 100;
        store[i] = medicine;
    }
    // Some more funny message
    printf("Voila! Our store now has %d medicine items.\n", MAX_MEDICINES);
}

void display(Medicine store[]) {
    // Display store items
    printf("%10s%20s%30s%10s%10s\n", "Name", "Brand", "Generic Name", "Price", "Quantity");
    for (int i = 0; i < MAX_MEDICINES; i++) {
        Medicine medicine = store[i];
        printf("%10s%20s%30s%10.2f%10d\n", medicine.name, medicine.brand, medicine.genericName, medicine.price, medicine.quantity);
    }
}

void search(Medicine store[], char* keyword) {
    // Searching for keyword
    printf("Listing all medicines whose name, brand or generic name contain '%s'\n", keyword);
    printf("%10s%20s%30s%10s%10s\n", "Name", "Brand", "Generic Name", "Price", "Quantity");
    for (int i = 0; i < MAX_MEDICINES; i++) {
        Medicine medicine = store[i];
        if (strstr(medicine.name, keyword) || strstr(medicine.brand, keyword) || strstr(medicine.genericName, keyword)) {
            printf("%10s%20s%30s%10.2f%10d\n", medicine.name, medicine.brand, medicine.genericName, medicine.price, medicine.quantity);
        }
    }
}

void sell(Medicine store[]) {
    char name[MAX_CHARACTERS];
    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", name);
    for (int i = 0; i < MAX_MEDICINES; i++) {
        Medicine* medicine = &store[i];
        if (strcmp(medicine->name, name) == 0) {
            printf("Enter the quantity you want to sell: ");
            int quantity;
            scanf("%d", &quantity);
            if (quantity > medicine->quantity) {
                printf("Sorry, we don't have enough quantity for %s\n", name);
            } else {
                medicine->quantity -= quantity;
                printf("Thanks for purchasing %s. The total cost is %.2f\n", name, medicine->price * quantity);
            }
            return;
        }
    }
    printf("Sorry, we don't have %s in our store\n", name);
}

int main() {
    Medicine store[MAX_MEDICINES];

    // Funny display for welcoming user
    printf("Welcome to our Medical Store Management System!\n");
    printf("Your one-stop-shop for all your medicine needs - unless you're a hypochondriac and choose to self-diagnose using Google, then we can't help you.\n");

    printf("\n");

    initialize(store);

    printf("\n");

    int choice = -1;
    while (choice != 0) {
        printf("\n");
        printf("Please select one of the following options:\n");
        printf("1. Display\n");
        printf("2. Search\n");
        printf("3. Sell\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(store);
                break;
            case 2:
                printf("Enter the keyword you want to search: ");
                char keyword[MAX_CHARACTERS];
                scanf("%s", keyword);
                search(store, keyword);
                break;
            case 3:
                sell(store);
                break;
            case 0:
                printf("Thanks for using our Medical Store Management System. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}