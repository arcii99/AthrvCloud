//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  int id;
  char name[50];
  int quantity;
  float price;
};

int main() {
  int i, j, choice, med_num, med_id, sold_num;
  float total = 0;
  struct medicine meds[100];

  printf("Welcome to the C Medical Store Management System!\n");

  // Add initial medicines
  meds[0].id = 1001;
  strcpy(meds[0].name, "Paracetamol");
  meds[0].quantity = 50;
  meds[0].price = 10.50;

  meds[1].id = 1002;
  strcpy(meds[1].name, "Amoxicillin");
  meds[1].quantity = 30;
  meds[1].price = 20.00;

  meds[2].id = 1003;
  strcpy(meds[2].name, "Aspirin");
  meds[2].quantity = 60;
  meds[2].price = 5.00;

  med_num = 3;

  while(choice != 4) {
    printf("\nMenu:\n");
    printf("1. Display Medicines\n");
    printf("2. Add New Medicine\n");
    printf("3. Sell Medicine\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("ID\tName\tQuantity\tPrice\n");

        for(i = 0; i < med_num; i++) {
          printf("%d\t%s\t%d\t\t%.2f\n", meds[i].id, meds[i].name, meds[i].quantity, meds[i].price);
        }
        break;

      case 2:
        printf("Enter Medicine ID: ");
        scanf("%d", &med_id);

        // Check if medicine already exists
        for(i = 0; i < med_num; i++) {
          if(meds[i].id == med_id) {
            printf("Medicine with this ID already exists.\n");
            break;
          }
        }

        // Add new medicine
        if(i == med_num) {
          meds[med_num].id = med_id;

          printf("Enter Name of Medicine: ");
          scanf("%s", meds[med_num].name);

          printf("Enter Quantity of Medicine: ");
          scanf("%d", &meds[med_num].quantity);

          printf("Enter Price of Medicine: ");
          scanf("%f", &meds[med_num].price);

          med_num++;
        }
        break;

      case 3:
        printf("Enter Medicine ID: ");
        scanf("%d", &med_id);

        // Check if medicine exists
        for(i = 0; i < med_num; i++) {
          if(meds[i].id == med_id) {
            printf("Enter Quantity to be sold: ");
            scanf("%d", &sold_num);

            if(sold_num <= meds[i].quantity) {
              meds[i].quantity -= sold_num;
              total += sold_num * meds[i].price;

              printf("Sold %d %s for %.2f\n", sold_num, meds[i].name, sold_num * meds[i].price);
            } else {
              printf("Not enough quantity of %s.\n", meds[i].name);
            }
            break;
          }
        }

        if(i == med_num) {
          printf("Medicine with this ID does not exist.\n");
        }
        break;

      case 4:
        printf("Thank you for using the C Medical Store Management System!\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  printf("Total Sales: %.2f", total);

  return 0;
}