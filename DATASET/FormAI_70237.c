//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Constant for the number of products
#define NUM_PRODUCTS 10

// Structure to represent a medicine
typedef struct Medicine
{
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function to display the main menu
void displayMainMenu()
{
    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add a new medicine\n");
    printf("2. Remove an existing medicine\n");
    printf("3. Update stock of a medicine\n");
    printf("4. Search for a medicine\n");
    printf("5. Display all medicines\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to add a new medicine
void addMedicine(Medicine medicines[])
{
    int id, quantity;
    float price;
    char name[50];

    printf("Enter medicine id: ");
    scanf("%d", &id);

    printf("Enter medicine name: ");
    scanf("%s", name);

    printf("Enter medicine price: ");
    scanf("%f", &price);

    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);

    Medicine medicine = {id, name, price, quantity};

    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        if (medicines[i].id == -1)
        {
            medicines[i] = medicine;
            printf("\nMedicine added successfully!\n\n");
            return;
        }
    }

    printf("\nSorry, maximum number of medicines reached.\n\n");
}

// Function to remove an existing medicine
void removeMedicine(Medicine medicines[])
{
    int id;

    printf("Enter medicine id to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        if (medicines[i].id == id)
        {
            medicines[i].id = -1;
            medicines[i].name[0] = '\0';
            medicines[i].price = 0;
            medicines[i].quantity = 0;
            printf("\nMedicine removed successfully!\n\n");
            return;
        }
    }

    printf("\nSorry, medicine not found.\n\n");
}

// Function to update stock of a medicine
void updateInventory(Medicine medicines[])
{
    int id, quantity;

    printf("Enter medicine id to update stock: ");
    scanf("%d", &id);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        if (medicines[i].id == id)
        {
            medicines[i].quantity += quantity;
            printf("\nStock updated successfully!\n\n");
            return;
        }
    }

    printf("\nSorry, medicine not found.\n\n");
}

// Function to search for a medicine
void searchMedicine(Medicine medicines[])
{
    int id;

    printf("Enter medicine id to search: ");
    scanf("%d", &id);

    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        if (medicines[i].id == id)
        {
            printf("\nId\tName\t\tPrice\tQuantity\n");
            printf("%d\t%s\t%.2f\t%d\n\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            return;
        }
    }

    printf("\nSorry, medicine not found.\n\n");
}

// Function to display all medicines
void displayAllMedicines(Medicine medicines[])
{
    printf("\nId\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        if (medicines[i].id != -1)
        {
            printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
        }
    }
    printf("\n");
}

// Main function
int main()
{
    Medicine medicines[NUM_PRODUCTS];

    // Initialize all medicines with id = -1 to indicate empty slots
    for (int i = 0; i < NUM_PRODUCTS; i++)
    {
        medicines[i].id = -1;
        medicines[i].name[0] = '\0';
        medicines[i].price = 0;
        medicines[i].quantity = 0;
    }

    int option;
    do
    {
        displayMainMenu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            addMedicine(medicines);
            break;
        case 2:
            removeMedicine(medicines);
            break;
        case 3:
            updateInventory(medicines);
            break;
        case 4:
            searchMedicine(medicines);
            break;
        case 5:
            displayAllMedicines(medicines);
            break;
        case 6:
            printf("Thank you for using the Medical Store Management System!\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (option != 6);

    return 0;
}