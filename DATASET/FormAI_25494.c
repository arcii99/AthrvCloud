//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int quantity;
    float price;
} Medicine;

typedef struct {
    char name[100];
    int phone;
    char address[200];  
} Customer;

typedef struct {
    char invoiceNo[20];
    char date[20];
    Customer customer;
    Medicine *medicines;
} Order;

int main() {
    int n, m, i, j;
    float total = 0.0;
    printf("--- Medical Store Management System ---\n");
    printf("Enter number of medicines available: ");
    scanf("%d", &n);

    Medicine medicines[n];

    printf("Enter details of medicines:\n");
    for (i = 0; i < n; i++) {
        printf("\nMedicine %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", medicines[i].name);
        printf("Quantity: ");
        scanf("%d", &medicines[i].quantity);
        printf("Price: ");
        scanf("%f", &medicines[i].price);
    }

    printf("\nEnter number of customers: ");
    scanf("%d", &m);

    Order orders[m];

    for (i = 0; i < m; i++) {
        printf("\nCustomer %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", orders[i].customer.name);
        printf("Phone: ");
        scanf("%d", &orders[i].customer.phone);
        printf("Address: ");
        scanf("%s", orders[i].customer.address);

        int num;
        printf("Enter number of medicines to purchase: ");
        scanf("%d", &num);

        orders[i].medicines = (Medicine*) malloc(num * sizeof(Medicine));

        for (j = 0; j < num; j++) {
            int k;
            printf("\nEnter medicine %d details:\n", j + 1);
            printf("Name: ");
            scanf("%s", orders[i].medicines[j].name);
            for (k = 0; k < n; k++) {
                if (strcmp(medicines[k].name ,orders[i].medicines[j].name) == 0) {
                    printf("Quantity: ");
                    scanf("%d", &orders[i].medicines[j].quantity);
                    if (orders[i].medicines[j].quantity > medicines[k].quantity) {
                        printf("Sorry, we only have %d quantity available for this medicine.\n", 
medicines[k].quantity);
                        j--;
                    } else {
                        medicines[k].quantity -= orders[i].medicines[j].quantity;
                        orders[i].medicines[j].price = medicines[k].price;
                        total += orders[i].medicines[j].quantity * orders[i].medicines[j].price;
                    }
                    break;
                }
            }
            if (k == n) {
                printf("This medicine is not available.\n");
                j--;
            }
        }
    }

    printf("\nOrders:\n");
    for (i = 0; i < m; i++) {
        printf("\nCustomer %d:\n", i + 1);
        printf("Name: %s\n", orders[i].customer.name);
        printf("Phone: %d\n", orders[i].customer.phone);
        printf("Address: %s\n", orders[i].customer.address);
        printf("Medicines:\n");

        for (j = 0; j < strlen(orders[i].invoiceNo); j++) {
            orders[i].invoiceNo[j] = '\0'; // clear invoice no
        }
        sprintf(orders[i].invoiceNo, "%06d", i + 1); // generate invoice no
        printf("Invoice No: %s\n", orders[i].invoiceNo);

        for (j = 0; j < strlen(orders[i].date); j++) {
            orders[i].date[j] = '\0'; // clear date
        }
        printf("Date: ");
        scanf("%s", orders[i].date); // get date from user
        printf("\n");
        for (j = 0; j < strlen(orders[i].date); j++) {
            printf("-");
        }
        printf("\n");
        printf("| Medicine       | Quantity       | Price          | Total          |\n");
        for (j = 0; j < strlen(orders[i].date); j++) {
            printf("-");
        }
        printf("\n");
        float orderTotal = 0.0;
        for (j = 0; j < sizeof(orders[i].medicines)/sizeof(orders[i].medicines[0]); j++) {
            if (strcmp(orders[i].medicines[j].name, "") != 0) { // check if medicine exists
                printf("| %-15s | %-15d | %-15.2f | %-15.2f |\n", 
orders[i].medicines[j].name, orders[i].medicines[j].quantity, orders[i].medicines[j].price, 
orders[i].medicines[j].quantity * orders[i].medicines[j].price); // print medicine details

                orderTotal += orders[i].medicines[j].quantity * orders[i].medicines[j].price;
            }
        }
        for (j = 0; j < strlen(orders[i].date); j++) {
            printf("-");
        }
        printf("\n");
        printf("|                                Order Total: | %-15.2f |\n", orderTotal);
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        if (medicines[i].quantity <= 2) {
            printf("Warning: Only %d quantity left for medicine %s\n", medicines[i].quantity, 
medicines[i].name);
        }
    }

    printf("\nTotal Daily Sales: %.2f\n", total);

    return 0;
}