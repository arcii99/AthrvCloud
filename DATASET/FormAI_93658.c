//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Defining the struct for medicine
struct Medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
};

// Defining the struct for the medical store
struct MedicalStore {
    char name[50];
    struct Medicine medicines[100];
    int num_medicines;
};

// Function to add a medicine to the store
void add_medicine(struct MedicalStore* store, char* name, char* company, int quantity, float price) {
    // Creating a new medicine and setting its values
    struct Medicine new_med;
    strcpy(new_med.name, name);
    strcpy(new_med.company, company);
    new_med.quantity = quantity;
    new_med.price = price;

    // Adding the new medicine to the store
    store->medicines[store->num_medicines++] = new_med;
}

// Function to display the medicines in the store
void display_medicines(struct MedicalStore* store) {
    printf("Medicines in store:\n");
    for (int i = 0; i < store->num_medicines; i++) {
        printf("%d. Name: %s, Company: %s, Quantity: %d, Price: %.2f\n", i+1, store->medicines[i].name, store->medicines[i].company, store->medicines[i].quantity, store->medicines[i].price);
    }
}

// Function to search for a medicine in the store
void search_medicine(struct MedicalStore* store, char* name) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s, Company: %s, Quantity: %d, Price: %.2f\n", store->medicines[i].name, store->medicines[i].company, store->medicines[i].quantity, store->medicines[i].price);
            return;
        }
    }
    printf("Medicine '%s' not found in store.\n", name);
}

// Function to buy a medicine from the store
void buy_medicine(struct MedicalStore* store, char* name, int quantity) {
    for (int i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            if (store->medicines[i].quantity >= quantity) {
                store->medicines[i].quantity -= quantity;
                printf("Purchased %d %s for Rs. %.2f each.\n", quantity, store->medicines[i].name, store->medicines[i].price);
            } else {
                printf("Sorry, only %d %s available in store.\n", store->medicines[i].quantity, store->medicines[i].name);
            }
            return;
        }
    }
    printf("Medicine '%s' not found in store.\n", name);
}

int main() {
    // Creating two medical stores
    struct MedicalStore store1;
    struct MedicalStore store2;

    // Setting the names of the stores
    strcpy(store1.name, "Medicine Mart");
    strcpy(store2.name, "Pharma Plus");

    // Adding medicines to store 1
    add_medicine(&store1, "Paracetamol", "Mediford", 50, 5.00);
    add_medicine(&store1, "Crocin", "GlaxoSmithKline", 30, 6.50);
    add_medicine(&store1, "Dolo", "Micro Labs", 20, 7.00);

    // Adding medicines to store 2
    add_medicine(&store2, "Medicine A", "Company A", 10, 8.00);
    add_medicine(&store2, "Medicine B", "Company B", 5, 12.00);
    add_medicine(&store2, "Medicine C", "Company C", 20, 6.50);

    // Displaying the medicines in both stores
    printf("%s:\n", store1.name);
    display_medicines(&store1);
    printf("\n%s:\n", store2.name);
    display_medicines(&store2);

    // Searching for a medicine in store 1
    char medicine_name[50] = "Crocin";
    printf("\nSearching for medicine '%s' in %s...\n", medicine_name, store1.name);
    search_medicine(&store1, medicine_name);

    // Buying a medicine from store 2
    printf("\nBuying 3 Medicines B from %s...\n", store2.name);
    buy_medicine(&store2, "Medicine B", 3);

    return 0;
}