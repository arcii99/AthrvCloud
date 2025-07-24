//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME 50
#define MAX_MEDICINE_QUANTITY 100
#define MAX_MEDICINE_STOCK 300 //maximum number of medicine that can be stored

struct Medicine {
    char name[MAX_MEDICINE_NAME];
    int quantity;
    float price;
};

struct MedicineStore {
    struct Medicine medicines[MAX_MEDICINE_STOCK];
    int medicineCount;
};

void addMedicine(struct MedicineStore* store, char* name, int quantity, float price) {
    if (store->medicineCount == MAX_MEDICINE_STOCK) {
        printf("Store is full, cannot add any more medicine\n");
        return;
    }
    strcpy(store->medicines[store->medicineCount].name, name);
    store->medicines[store->medicineCount].quantity = quantity;
    store->medicines[store->medicineCount].price = price;
    store->medicineCount++;
}

void sellMedicine(struct MedicineStore* store, char* name, int quantity) {
    for (int i = 0; i < store->medicineCount; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            if (store->medicines[i].quantity < quantity) {
                printf("Not enough medicine in stock\n");
                return;
            }
            store->medicines[i].quantity -= quantity;
            printf("%d %s sold for %.2f each\n", quantity, name, store->medicines[i].price);
            return;
        }
    }
    printf("Medicine not found\n");
}

void displayMedicine(struct MedicineStore* store) {
    printf("Medicine\tQuantity\tPrice\n");
    for (int i = 0; i < store->medicineCount; i++) {
        printf("%s\t\t%d\t\t%.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

int main() {
    struct MedicineStore store;
    store.medicineCount = 0;

    addMedicine(&store, "Paracetamol", 50, 1.50);
    addMedicine(&store, "Aspirin", 25, 1.25);
    addMedicine(&store, "Ibuprofen", 20, 2.00);

    displayMedicine(&store);

    sellMedicine(&store, "Aspirin", 10);

    displayMedicine(&store);

    return 0;
}