//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} medicine;

void addMedicine(medicine meds[], int numMeds) {
    printf("\nEnter the name of the medicine: ");
    scanf("%s", meds[numMeds].name);
    printf("Enter the stock of the medicine: ");
    scanf("%d", &meds[numMeds].stock);
    printf("Enter the price of the medicine: ");
    scanf("%f", &meds[numMeds].price);
}

void displayMedicines(medicine meds[], int numMeds) {
    printf("\nMedicine Name\t\tStock\tPrice\n");
    for(int i=0; i<numMeds; i++) {
        printf("%-20s\t%d\t%.2f\n", meds[i].name, meds[i].stock, meds[i].price);
    }
}

void searchMedicine(medicine meds[], int numMeds, char searchName[]) {
    for(int i=0; i<numMeds; i++) {
        if(strcmp(meds[i].name, searchName) == 0) {
            printf("\nMedicine Name: %s\nStock: %d\nPrice: %.2f\n", meds[i].name, meds[i].stock, meds[i].price);
            return;
        }
    }
    printf("\nNo medicine was found with the given name.\n");
}

void updateStock(medicine meds[], int numMeds, char updateName[], int newStock) {
    for(int i=0; i<numMeds; i++) {
        if(strcmp(meds[i].name, updateName) == 0) {
            printf("\nPrevious Stock: %d\nNew Stock: %d\n", meds[i].stock, newStock);
            meds[i].stock = newStock;
            return;
        }
    }
    printf("\nNo medicine was found with the given name.\n");
}

int main() {
    int numMeds = 0, choice;
    medicine meds[100];

    while(1) {
        printf("\n**** Medical Store Management System ****\n");
        printf("1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Update Stock\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(meds, numMeds);
                numMeds++;
                break;
            case 2:
                displayMedicines(meds, numMeds);
                break;
            case 3:
                char searchName[50];
                printf("\nEnter the name of the medicine to search: ");
                scanf("%s", searchName);
                searchMedicine(meds, numMeds, searchName);
                break;
            case 4:
                char updateName[50];
                int newStock;
                printf("\nEnter the name of the medicine to update: ");
                scanf("%s", updateName);
                printf("Enter the new stock: ");
                scanf("%d", &newStock);
                updateStock(meds, numMeds, updateName, newStock);
                break;
            case 5:
                printf("\nThank you for using the Medical Store Management System!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}