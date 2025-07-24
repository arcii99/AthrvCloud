//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME_LENGTH 50
#define MAX_MEDICINE_LIST_LENGTH 100

typedef struct {
    char name[MAX_MEDICINE_NAME_LENGTH];
    int quantity;
    double price;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINE_LIST_LENGTH];
    int count;
} MedicineList;

void printMedicineList(MedicineList *medicineList) {
    int i;
    printf("Medicine List:\n");
    printf("----------------------------------------\n");
    printf("%-20s %-20s %-20s\n", "Medicine Name", "Quantity", "Price");
    printf("----------------------------------------\n");
    for (i = 0; i < medicineList->count; i++) {
        printf("%-20s %-20d %-20.2f\n", medicineList->medicines[i].name,
               medicineList->medicines[i].quantity, medicineList->medicines[i].price);
    }
    printf("----------------------------------------\n");
}

int addMedicine(Medicine *medicine, MedicineList *medicineList) {
    if (medicineList->count < MAX_MEDICINE_LIST_LENGTH) {
        medicineList->medicines[medicineList->count++] = *medicine;
        return 1;
    }
    return 0;
}

double sellMedicine(char *medicineName, int quantity, MedicineList *medicineList) {
    int i;
    for (i = 0; i < medicineList->count; i++) {
        if (strcmp(medicineName, medicineList->medicines[i].name) == 0) {
            if (medicineList->medicines[i].quantity >= quantity) {
                medicineList->medicines[i].quantity -= quantity;
                return quantity * medicineList->medicines[i].price;
            } else {
                printf("Insufficient Quantity: %s\n", medicineName);
            }
        }
    }
    printf("Medicine Not Found: %s\n", medicineName);
    return 0;
}

int main() {
    MedicineList medicineList;
    medicineList.count = 0;

    Medicine m1 = {"Medicine1", 100, 5.50};
    Medicine m2 = {"Medicine2", 50, 10.25};

    addMedicine(&m1, &medicineList);
    addMedicine(&m2, &medicineList);

    printMedicineList(&medicineList);

    double totalAmount = sellMedicine("Medicine1", 50, &medicineList);
    printf("Total Amount: %.2f\n", totalAmount);

    printMedicineList(&medicineList);

    totalAmount = sellMedicine("Medicine3", 10, &medicineList);
    printf("Total Amount: %.2f\n", totalAmount);

    totalAmount = sellMedicine("Medicine1", 100, &medicineList);
    printf("Total Amount: %.2f\n", totalAmount);

    return 0;
}