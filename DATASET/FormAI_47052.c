//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[20];
    int quantity;
    float price;
};

int main() {
    FILE *fp;
    struct item inventory[10];

    // Create and populate inventory
    strcpy(inventory[0].name, "Bottle of water");
    inventory[0].quantity = 10;
    inventory[0].price = 2.5;

    strcpy(inventory[1].name, "Can of beans");
    inventory[1].quantity = 5;
    inventory[1].price = 3.0;

    // Save inventory to file
    fp = fopen("inventory.dat", "wb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(inventory, sizeof(struct item), 2, fp);
    fclose(fp);

    // Load inventory from file
    fp = fopen("inventory.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fread(inventory, sizeof(struct item), 2, fp);
    fclose(fp);

    // Display inventory
    printf("Welcome to the post-apocalyptic store!\n");
    printf("--------------------------------------------------\n");
    printf("| Item                 | Quantity | Price per unit |\n");
    printf("--------------------------------------------------\n");
    int i;
    for(i = 0; i < 2; i++) {
        printf("| %-20s | %-8d | $%-13.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("--------------------------------------------------\n");

    return 0;
}