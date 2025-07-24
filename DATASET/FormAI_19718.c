//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE 100

// Define the structure of medicine in the store
struct Medicine {
    char name[50];
    float price;
    int quantity;
};

// Initialize empty storage for medicines
struct Medicine medicine_store[MAX_MEDICINE];
int num_medicines = 0;

// Function to add medicine to the store
void add_medicine(char* name, float price, int quantity) {
    if (num_medicines >= MAX_MEDICINE) {
        printf("Error: store is full!\n");
        return;
    }

    // Create a new medicine and add it to array
    struct Medicine new_medicine;
    strcpy(new_medicine.name, name);
    new_medicine.price = price;
    new_medicine.quantity = quantity;
    medicine_store[num_medicines] = new_medicine;
    num_medicines++;

    // Print confirmation message
    printf("Added %d units of %s to the store at %.2f each.\n", quantity, name, price);
}

// Function to display inventory of store
void inventory() {
    printf("Inventory of store:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s (Qty: %d) - $%.2f each\n", i+1, medicine_store[i].name, medicine_store[i].quantity, medicine_store[i].price);
    }
}

// Function to remove medicine from store
void remove_medicine(char* name, int quantity) {
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicine_store[i].name, name) == 0) {
            if (quantity > medicine_store[i].quantity) {
                printf("Error: not enough %s in store!\n", name);
            } else {
                medicine_store[i].quantity -= quantity;
                printf("Removed %d units of %s from the store.\n", quantity, name);
            }
            return;
        }
    }
    printf("Error: %s not found in store!\n", name);
}

// Function to update price of medicine in store
void update_price(char* name, float new_price) {
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicine_store[i].name, name) == 0) {
            medicine_store[i].price = new_price;
            printf("Updated the price of %s to $%.2f.\n", name, new_price);
            return;
        }
    }
    printf("Error: %s not found in store!\n", name);
}

// Main function to run the program
int main() {
    printf("Welcome to the Medical Store Management System.\n");

    // Add some initial medicines to the store
    add_medicine("Aspirin", 4.99, 100);
    add_medicine("Ibuprofen", 7.99, 75);

    // Display initial inventory of store
    inventory();

    // Test removing medicine from store
    remove_medicine("Aspirin", 50);
    remove_medicine("Ibuprofen", 100);

    // Add some new medicines to the store
    add_medicine("Tylenol", 6.49, 150);
    add_medicine("Advil", 8.99, 200);

    // Display updated inventory of store
    inventory();

    // Test updating price of medicine in store
    update_price("Tylenol", 5.99);
    update_price("Advil", 7.99);

    // Display final inventory of store
    inventory();

    return 0;
}