//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

typedef struct Medicine med;

int main() {
    med m[100];
    int choice, n=0, i;
    float total = 0;
    char ch;

    do {
        printf("\n+++C MEDICAL STORE MANAGEMENT SYSTEM+++\n");
        printf("\n1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Sell Medicine\n5. Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: //Add Medicine
                printf("\nEnter Medicine ID: ");
                scanf("%d", &m[n].id);
                printf("Enter Medicine Name: ");
                scanf("%s", &m[n].name);
                printf("Enter Medicine Price: ");
                scanf("%f", &m[n].price);
                printf("Enter Medicine Quantity: ");
                scanf("%d", &m[n].quantity);
                n++;
                printf("\nMedicine Added Successfully!\n");
                break;

            case 2: //Display Medicines
                if(n == 0) {
                    printf("\nMedicines Not Available!\n");
                }
                else {
                    printf("\nID\tNAME\tPRICE\t\tQUANTITY\n");
                    for(i=0; i<n; i++) {
                        printf("%d\t%s\t%.2f\t\t%d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
                    }
                }
                break;

            case 3: //Search Medicine
                int id, flag=0;
                printf("\nEnter ID to Search: ");
                scanf("%d", &id);
                for(i=0; i<n; i++) {
                    if(m[i].id == id) {
                        printf("\nID\tNAME\tPRICE\t\tQUANTITY\n");
                        printf("%d\t%s\t%.2f\t\t%d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nMedicine Not Found!\n");
                }
                break;

            case 4: //Sell Medicine
                int sell_id, sell_quantity, flag2 = 0;
                printf("\nEnter ID to Sell: ");
                scanf("%d", &sell_id);
                for(i=0; i<n; i++) {
                    if(m[i].id == sell_id) {
                        printf("\nEnter Quantity to Sell: ");
                        scanf("%d", &sell_quantity);
                        if(sell_quantity <= m[i].quantity) {
                            total += (m[i].price * sell_quantity);
                            m[i].quantity -= sell_quantity;
                            printf("\nMedicine Sold Successfully!\n");
                            flag2 = 1;
                        }
                        else {
                            printf("\nMedicine Quantity Not Available!\n");
                        }
                        break;
                    }
                }
                if(flag2 == 0) {
                    printf("\nMedicine Not Found!\n");
                }
                break;

            case 5: //Exit
                printf("\nTotal Sales: %.2f\n", total);
                printf("\nThank You For Using C MEDICAL STORE MANAGEMENT SYSTEM!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

        printf("\nDo You Want To Continue? (y/n): ");
        scanf("%s", &ch);

    } while(ch == 'y' || ch == 'Y');

    return 0;
}