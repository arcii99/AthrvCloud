//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure to hold details of medicine
struct Medicine {
    char name[50];
    int id;
    float price;
    int quantity;
};

//Creating array of Medicine type structure to hold inventory records
struct Medicine inventory[100];

//Helper function to add medicine to inventory
void addMedicine(int id, char *name, float price, int quantity) {
    struct Medicine newMedicine;
    newMedicine.id = id;
    strcpy(newMedicine.name, name);
    newMedicine.price = price;
    newMedicine.quantity = quantity;
    inventory[id-1] = newMedicine;
}

//Helper function to delete medicine from inventory
void deleteMedicine(int id) {
    struct Medicine emptyMedicine;
    emptyMedicine.id = 0;
    emptyMedicine.name[0] = '\0';
    emptyMedicine.price = 0.0;
    emptyMedicine.quantity = 0;
    inventory[id-1] = emptyMedicine;
}

//Helper function to check if medicine is present in inventory
int isMedicineAvailable(int id) {
    return (inventory[id-1].id != 0);
}

//Helper function to display list of all medicines in inventory
void displayMedicines() {
    printf("------------------------------------------------------------------------------\n");
    printf("%-15s%-30s%-15s%-15s\n", "Medicine ID", "Medicine Name", "Price", "Quantity");
    printf("------------------------------------------------------------------------------\n");
    for(int i=0; i<100; i++) {
        if(inventory[i].id != 0) {
            printf("%-15d%-30s%-15.2f%-15d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
    printf("------------------------------------------------------------------------------\n");
}

//Helper function to search for medicine by name
void searchMedicineByName(char *name) {
    printf("------------------------------------------------------------------------------\n");
    printf("%-15s%-30s%-15s%-15s\n", "Medicine ID", "Medicine Name", "Price", "Quantity");
    printf("------------------------------------------------------------------------------\n");
    for(int i=0; i<100; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("%-15d%-30s%-15.2f%-15d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
    }
    printf("------------------------------------------------------------------------------\n");
}

int main() {
    printf("Welcome to our Medical Store!\n");
    printf("We are glad to have you here :)\n");

    //Adding initial inventory records
    addMedicine(1, "Paracetamol", 5.99, 100);
    addMedicine(2, "Aspirin", 6.49, 200);
    addMedicine(3, "Ibuprofen", 10.99, 150);
    addMedicine(4, "Amoxicillin", 15.99, 75);
    addMedicine(5, "Naproxen", 7.99, 100);

    //Displaying initial inventory records
    displayMedicines();

    int choice;
    int medicineId;
    char medicineName[50];
    float medicinePrice;
    int medicineQuantity;

    do {
        printf("Please select an option:\n");
        printf("1. Add new medicine to inventory.\n");
        printf("2. Delete medicine from inventory.\n");
        printf("3. Search medicine by name.\n");
        printf("4. Display list of all medicines in inventory.\n");
        printf("5. Exit.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                //Adding new medicine to inventory
                printf("Please enter the following details of new medicine:\n");
                printf("Medicine ID: ");
                scanf("%d", &medicineId);
                printf("Medicine Name: ");
                scanf("%s", medicineName);
                printf("Price: ");
                scanf("%f", &medicinePrice);
                printf("Quantity: ");
                scanf("%d", &medicineQuantity);
                addMedicine(medicineId, medicineName, medicinePrice, medicineQuantity);
                printf("New medicine added to inventory successfully!\n");
                break;

            case 2:
                //Deleting medicine from inventory
                printf("Please enter the ID of medicine to be deleted: ");
                scanf("%d", &medicineId);
                if(isMedicineAvailable(medicineId)) {
                    deleteMedicine(medicineId);
                    printf("Medicine with ID %d deleted from inventory successfully!\n", medicineId);
                } else {
                    printf("Invalid medicine ID. Please enter a valid ID.\n");
                }
                break;

            case 3:
                //Searching medicine by name
                printf("Please enter the name of medicine to be searched: ");
                scanf("%s", medicineName);
                searchMedicineByName(medicineName);
                break;

            case 4:
                //Displaying list of all medicines in inventory
                displayMedicines();
                break;

            case 5:
                //Exiting program
                printf("Thank you for visiting our Medical Store!\n");
                printf("We hope to see you again soon :)\n");
                break;

            default:
                //Invalid option selected
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while(choice != 5);

    return 0;
}