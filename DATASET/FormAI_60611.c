//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char medicine[30];
    float price;
    int quantity;
} Medicine;

int main()
{
    FILE *fp;
    int i, n, choice;
    float total = 0;
    char med_name[30];

    // Create a file to store database
    fp = fopen("database.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get number of medicine to add
    printf("Enter number of medicine to add to database: ");
    scanf("%d", &n);

    // Initialize array of Medicine structure
    Medicine med[n];

    // Add medicine to database
    printf("\nEnter details of medicine to add to database:\n");
    for (i = 0; i < n; i++) {
        printf("\nMedicine #%d\n", i+1);

        // Medicine name
        printf("Enter name of medicine: ");
        scanf("%s", med[i].medicine);

        // Medicine price
        printf("Enter price of medicine: ");
        scanf("%f", &med[i].price);

        // Medicine quantity
        printf("Enter quantity of medicine: ");
        scanf("%d", &med[i].quantity);

        // Write to file
        fprintf(fp, "%s\t%f\t%d\n", med[i].medicine, med[i].price, med[i].quantity);
    }

    // Close file pointer
    fclose(fp);

    // Display menu
    while (1) {
        printf("\n***************\n");
        printf("MEDICAL STORE\n");
        printf("***************\n");
        printf("1. View medicine details\n");
        printf("2. Search for medicine\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Read and display database
                fp = fopen("database.txt", "r");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                printf("\nMEDICINE DETAILS:\n");
                printf("Name\tPrice\tQuantity\n");

                while (!feof(fp)) {
                    fscanf(fp, "%s\t%f\t%d", med_name, &med[i].price, &med[i].quantity);
                    printf("%s\t%.2f\t%d\n", med_name, med[i].price, med[i].quantity);
                    total += med[i].price * med[i].quantity;
                }

                printf("\nTotal revenue: %.2f\n", total);

                // Close file pointer
                fclose(fp);
                break;

            case 2:
                // Search for medicine
                printf("\nEnter name of medicine to search for: ");
                scanf("%s", med_name);

                fp = fopen("database.txt", "r");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                while (!feof(fp)) {
                    fscanf(fp, "%s\t%f\t%d", med[i].medicine, &med[i].price, &med[i].quantity);
                    if (strcmp(med[i].medicine, med_name) == 0) {
                        printf("\nMEDICINE DETAILS:\n");
                        printf("Name\tPrice\tQuantity\n");
                        printf("%s\t%.2f\t%d\n", med[i].medicine, med[i].price, med[i].quantity);
                        break;
                    }
                }

                if (feof(fp)) {
                    printf("\nMedicine not found!\n");
                }

                // Close file pointer
                fclose(fp);
                break;

            case 3:
                // Exit program
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}