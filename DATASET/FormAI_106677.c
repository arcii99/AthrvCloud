//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encrypt the data using Vigenere Cipher
void vigenere_encrypt(char* data, char* key) {
    int data_len = strlen(data), key_len = strlen(key);
    char encrypted_data[data_len];
    for(int i=0; i<data_len; i++) {
        encrypted_data[i] = ((data[i] + key[i % key_len] - 2*'A') % 26) + 'A';
    }
    strcpy(data, encrypted_data);
}

// Function to decrypt the data using Vigenere Cipher
void vigenere_decrypt(char* data, char* key) {
    int data_len = strlen(data), key_len = strlen(key);
    char decrypted_data[data_len];
    for(int i=0; i<data_len; i++) {
        decrypted_data[i] = ((data[i] - key[i % key_len] + 26) % 26) + 'A';
    }
    strcpy(data, decrypted_data);
}

// Structure to store the medicine details
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to add a new medicine to the inventory
void add_medicine(struct Medicine* inventory, int* count_inventory) {
    printf("Enter the details of the new medicine:\n");
    struct Medicine new_medicine;
    printf("ID: ");
    scanf("%d", &new_medicine.id);
    printf("Name: ");
    scanf("%s", new_medicine.name);
    printf("Price: ");
    scanf("%f", &new_medicine.price);
    printf("Quantity: ");
    scanf("%d", &new_medicine.quantity);
    inventory[(*count_inventory)++] = new_medicine;
    printf("Medicine added successfully!\n");
}

// Function to search for a medicine in the inventory by its ID
int search_medicine_by_id(struct Medicine* inventory, int count_inventory, int id) {
    for(int i=0; i<count_inventory; i++) {
        if(inventory[i].id == id)
            return i;
    }
    return -1;
}

// Function to buy a medicine from the inventory
void buy_medicine(struct Medicine* inventory, int* count_inventory) {
    int id, position;
    printf("Enter the ID of the medicine you want to buy: ");
    scanf("%d", &id);
    position = search_medicine_by_id(inventory, *count_inventory, id);
    if(position == -1) {
        printf("Medicine not found in the inventory!\n");
        return;
    }
    int quantity;
    printf("Enter the quantity you want to buy: ");
    scanf("%d", &quantity);
    if(quantity > inventory[position].quantity) {
        printf("Quantity not available in the inventory!\n");
        return;
    }
    float total_cost = quantity * inventory[position].price;
    printf("Total cost: %.2f\n", total_cost);
    inventory[position].quantity -= quantity;
    printf("Medicine bought successfully!\n");
}

// Function to display the inventory of all the medicines
void display_inventory(struct Medicine* inventory, int count_inventory) {
    printf("ID\tNAME\t\tPRICE\tQUANTITY\n");
    for(int i=0; i<count_inventory; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int main() {
    char key[] = "CRYPTIC";
    char encrypted_option[] = "XGVVWZMBH";
    char option[10];
    vigenere_decrypt(encrypted_option, key);  // Decrypting the option
    int count_inventory = 0;  // Counter variable to keep track of the inventory
    struct Medicine inventory[100];  // Array to store the medicines in the inventory
    while(strcmp(option, "EXIT") != 0) {
        printf("Enter your option: ");
        scanf("%s", option);
        vigenere_decrypt(option, key);  // Decrypting the option
        if(strcmp(option, "ADD") == 0) {
            add_medicine(inventory, &count_inventory);
        }
        else if(strcmp(option, "BUY") == 0) {
            buy_medicine(inventory, &count_inventory);
        }
        else if(strcmp(option, "DISPLAY") == 0) {
            display_inventory(inventory, count_inventory);
        }
    }
    return 0;
}