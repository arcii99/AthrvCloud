//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
}medicine;

int main(){
    int i, choice, record, quantity;
    float price;
    char name[20];

    printf("Welcome to the C Medical Store Management System\n\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new medicine\n");
        printf("2. Remove a medicine\n");
        printf("3. Update a medicine's quantity\n");
        printf("4. Display all medicines\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name of the new medicine:\n");
                scanf("%s", name);

                printf("Enter the quantity of the new medicine:\n");
                scanf("%d", &quantity);

                printf("Enter the price of the new medicine:\n");
                scanf("%f", &price);

                medicine new_med = { name, quantity, price };

                FILE *fp;
                fp = fopen("medicines.txt", "a");

                if(fp == NULL){
                    printf("Error opening file\n");
                    exit(1);
                }

                if(fwrite(&new_med, sizeof(medicine), 1, fp) != 1) {
                    printf("Error writing to file\n");
                    exit(1);
                }

                fclose(fp);

                printf("%s added successfully!\n", name);

                break;

            case 2:
                printf("\nEnter the name of the medicine to remove:\n");
                scanf("%s", name);

                FILE *fp1, *fp2;
                fp1 = fopen("medicines.txt", "rb");
                fp2 = fopen("temp.txt", "wb");

                if(fp1 == NULL || fp2 == NULL){
                    printf("Error opening file\n");
                    exit(1);
                }

                medicine med1;

                while(fread(&med1, sizeof(medicine), 1, fp1) == 1) {
                    if(strcmp(med1.name, name) != 0){
                        fwrite(&med1, sizeof(medicine), 1, fp2);
                    } else{
                        printf("%s removed successfully!", name);
                    }
                }

                fclose(fp1);
                fclose(fp2);
                remove("medicines.txt");
                rename("temp.txt", "medicines.txt");

                break;

            case 3:
                printf("\nEnter the name of the medicine to update:\n");
                scanf("%s", name);

                printf("Enter the new quantity:\n");
                scanf("%d", &quantity);

                FILE *fp3, *fp4;
                fp3 = fopen("medicines.txt", "rb");
                fp4 = fopen("temp.txt", "wb");

                if(fp3 == NULL || fp4 == NULL){
                    printf("Error opening file\n");
                    exit(1);
                }

                medicine med2;

                while(fread(&med2, sizeof(medicine), 1, fp3) == 1) {
                    if(strcmp(med2.name, name) == 0){
                        med2.quantity = quantity;
                    }
                    fwrite(&med2, sizeof(medicine), 1, fp4);
                }

                fclose(fp3);
                fclose(fp4);
                remove("medicines.txt");
                rename("temp.txt", "medicines.txt");

                break;

            case 4:
                FILE *fp5;
                fp5 = fopen("medicines.txt", "rb");

                if(fp5 == NULL){
                    printf("Error opening file\n");
                    exit(1);
                }

                printf("\n%-20s%-20s%-20s\n", "Name", "Quantity", "Price");

                medicine med3;

                while(fread(&med3, sizeof(medicine), 1, fp5) == 1) {
                    printf("%-20s%-20d%-20.2f\n", med3.name, med3.quantity, med3.price);
                }

                fclose(fp5);

                break;

            case 5:
                printf("\nThank you for using the C Medical Store Management System!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}