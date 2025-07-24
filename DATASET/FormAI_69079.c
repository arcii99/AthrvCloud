//FormAI DATASET v1.0 Category: Educational ; Style: real-life
/*
 * Program: Invoicing System
 * Author: Chatbot
 * Description: A simple invoicing system that allows users to create invoices and store them in a file.
 *              Users can also retrieve and view an existing invoice by searching for it using its invoice number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INVOICES 10
#define MAX_LINE_CHARS 80

typedef struct {
    int invoice_number;
    char customer_name[50];
    float amount_due;
} invoice_t;

int main() {
    invoice_t invoices[MAX_INVOICES];
    int num_invoices = 0;
    char line[MAX_LINE_CHARS];
    int choice;
    
    while(1) {
        // Print menu options
        printf("1. Create invoice\n");
        printf("2. View invoice\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        
        fgets(line, MAX_LINE_CHARS, stdin);
        choice = atoi(line);
        
        switch(choice) {
            case 1:
                if(num_invoices == MAX_INVOICES) {
                    printf("Error: Maximum number of invoices reached!\n");
                } else {
                    invoice_t new_invoice;
                    printf("Enter invoice number: ");
                    fgets(line, MAX_LINE_CHARS, stdin);
                    new_invoice.invoice_number = atoi(line);
                    printf("Enter customer name: ");
                    fgets(new_invoice.customer_name, sizeof(new_invoice.customer_name), stdin);
                    printf("Enter amount due: ");
                    fgets(line, MAX_LINE_CHARS, stdin);
                    new_invoice.amount_due = atof(line);
                    invoices[num_invoices] = new_invoice;
                    num_invoices++;
                }
                break;
            case 2:
                if(num_invoices == 0) {
                    printf("Error: No invoices found!\n");
                } else {
                    printf("Enter invoice number: ");
                    fgets(line, MAX_LINE_CHARS, stdin);
                    int search_invoice_number = atoi(line);
                    int found = 0;
                    for(int i = 0; i < num_invoices; i++) {
                        if(invoices[i].invoice_number == search_invoice_number) {
                            printf("Invoice number: %d\n", invoices[i].invoice_number);
                            printf("Customer name: %s", invoices[i].customer_name);
                            printf("Amount due: %.2f\n", invoices[i].amount_due);
                            found = 1;
                            break;
                        }
                    }
                    if(!found) {
                        printf("Error: Invoice not found!\n");
                    }
                }
                break;
            case 3:
                // Save invoices to file before exiting
                FILE *file = fopen("invoices.txt", "w");
                for(int i = 0; i < num_invoices; i++) {
                    fprintf(file, "%d,%s,%.2f\n", invoices[i].invoice_number, invoices[i].customer_name, invoices[i].amount_due);
                }
                fclose(file);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice!\n");
        }
    }
    
    return 0;
}