//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100 // maximum number of medicines that can be stored

struct Medicine {
    char name[50];
    char manufacturer[50];
    float cost;
    int quantity;
};

struct MedicineList {
    struct Medicine medicines[MAX_MEDICINES];
    int count;
};

void initialize_list(struct MedicineList *list);
void add_medicine(struct MedicineList *list, char* name, char* manufacturer, float cost, int quantity);
void remove_medicine(struct MedicineList *list, char* name);
void display_medicines(struct MedicineList *list);

int main() {
    struct MedicineList medicine_list;
    initialize_list(&medicine_list);

    // add some medicines
    add_medicine(&medicine_list, "Paracetamol", "GSK", 4.0, 50);
    add_medicine(&medicine_list, "Ibuprofen", "Pfizer", 6.0, 40);
    add_medicine(&medicine_list, "Aspirin", "Bayer", 5.0, 30);

    // remove a medicine
    remove_medicine(&medicine_list, "Aspirin");

    // display all medicines
    display_medicines(&medicine_list);

    return 0;
}

void initialize_list(struct MedicineList *list) {
    list->count = 0;
}

void add_medicine(struct MedicineList *list, char* name, char* manufacturer, float cost, int quantity) {
    if (list->count < MAX_MEDICINES) {
        struct Medicine medicine;
        strcpy(medicine.name, name);
        strcpy(medicine.manufacturer, manufacturer);
        medicine.cost = cost;
        medicine.quantity = quantity;
        list->medicines[list->count++] = medicine;
    }
}

void remove_medicine(struct MedicineList *list, char* name) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->medicines[i].name, name) == 0) {
            int j;
            for (j = i; j < list->count - 1; j++) {
                list->medicines[j] = list->medicines[j + 1];
            }
            list->count--;
            break;
        }
    }
}

void display_medicines(struct MedicineList *list) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Medicine medicine = list->medicines[i];
        printf("Name: %s\n", medicine.name);
        printf("Manufacturer: %s\n", medicine.manufacturer);
        printf("Cost: %.2f\n", medicine.cost);
        printf("Quantity: %d\n", medicine.quantity);
        printf("\n");
    }
}