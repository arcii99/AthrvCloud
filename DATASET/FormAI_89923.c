//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    int id;
    float price;
    int quantity;
};

void add_medicine();
void search_medicine();
void sell_medicine();
void display_stock();

int main() {
    int choice;
    do {
        printf("==========MEDICAL STORE MANAGEMENT SYSTEM==========\n\n");
        printf("1. Add medicine\n2. Search medicine\n3. Sell medicine\n4. Display stock\n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_medicine(); break;
            case 2: search_medicine(); break;
            case 3: sell_medicine(); break;
            case 4: display_stock(); break;
            case 5: printf("Exiting program..."); break;
            default: printf("Invalid choice, please try again!");
        }
        printf("\n\n");
    } while(choice != 5);
    return 0;
}

void add_medicine() {
    int n, i;
    printf("Enter the number of medicines to be added: ");
    scanf("%d", &n);
    struct medicine med[n];
    for(i=0; i<n; i++) {
        printf("\nEnter details of medicine %d:\n", i+1);
        printf("\nEnter medicine name: ");
        scanf("%s", med[i].name);
        printf("Enter ID number: ");
        scanf("%d", &med[i].id);
        printf("Enter price: ");
        scanf("%f", &med[i].price);
        printf("Enter quantity: ");
        scanf("%d", &med[i].quantity);
    }
    FILE *fptr;
    fptr = fopen("medicine.dat", "ab");
    fwrite(med, sizeof(med), 1, fptr);
    fclose(fptr);
    printf("\n\nMedicine details successfully added!");
}

void search_medicine() {
    FILE *fptr;
    struct medicine med;
    int id;
    printf("Enter the ID of the medicine to be searched: ");
    scanf("%d", &id);
    fptr = fopen("medicine.dat", "rb");
    while(fread(&med, sizeof(med), 1, fptr)) {
        if(med.id == id) {
            printf("\nMedicine details:\n");
            printf("Name: %s\nID: %d\nPrice: %.2f\nQuantity: %d\n", med.name, med.id, med.price, med.quantity);
            fclose(fptr);
            return;
        }
    }
    printf("Medicine not found!");
    fclose(fptr);
}

void sell_medicine() {
    FILE *fptr, *fptr1;
    struct medicine med, new_med;
    int id, quantity;
    printf("Enter the ID of the medicine to be sold: ");
    scanf("%d", &id);
    printf("Enter the quantity to be sold: ");
    scanf("%d", &quantity);
    fptr = fopen("medicine.dat", "rb");
    fptr1 = fopen("temp.dat", "wb");
    while(fread(&med, sizeof(med), 1, fptr)) {
        if(med.id == id) {
            if(med.quantity < quantity) {
                printf("Insufficient stock! Only %d units available.\n\n", med.quantity);
                fwrite(&med, sizeof(med), 1, fptr1);
            } else {
                printf("\nMedicine sold.\n\n");
                new_med.id = id;
                strcpy(new_med.name, med.name);
                new_med.price = med.price;
                new_med.quantity = med.quantity - quantity;
                fwrite(&new_med, sizeof(new_med), 1, fptr1);
            }
        } else {
            fwrite(&med, sizeof(med), 1, fptr1);
        }
    }
    fclose(fptr);
    fclose(fptr1);
    remove("medicine.dat");
    rename("temp.dat", "medicine.dat");
}

void display_stock() {
    FILE *fptr;
    struct medicine med;
    fptr = fopen("medicine.dat", "rb");
    printf("\nID\tName\tPrice\tQuantity\n");
    while(fread(&med, sizeof(med), 1, fptr)) {
        printf("%d\t%s\t%.2f\t%d\n", med.id, med.name, med.price, med.quantity);
    }
    fclose(fptr);
}