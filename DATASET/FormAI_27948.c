//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ITEMS 10
#define ITEM_NAME_SIZE 20
#define TAX_RATE 0.1     // 10% Sales Tax
#define SERVICE_CHARGE 0.05     // 5% Service Charge

typedef struct item {
    char name[ITEM_NAME_SIZE];
    float price;
} item_t;

item_t items[MAX_ITEMS] = {
    {"Cappuccino", 3.50},
    {"Latte", 4.00},
    {"Espresso", 2.50},
    {"Iced Coffee", 3.00},
    {"Hot Chocolate", 3.50},
    {"Tea", 2.00},
    {"Chai Tea", 3.50},
    {"Muffin", 2.00},
    {"Bagel", 1.75},
    {"Croissant", 1.50}
};

int num_items = 10;

float calculate_tax(float total) {
    return total * TAX_RATE;
}

float calculate_service_charge(float total) {
    return total * SERVICE_CHARGE;
}

void print_menu() {
    int i;
    printf("\nMenu:\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s - %.2f\n", i+1, items[i].name, items[i].price);
    }
}

int validate_input(char* input) {
    int i, l = strlen(input);
    for (i = 0; i < l; i++) {
        if (!isdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, option, quantity, choice[MAX_ITEMS];
    float subtotal = 0, total = 0, tax = 0, service_charge = 0, item_total[MAX_ITEMS];
    char input[ITEM_NAME_SIZE];
    do {
        print_menu();
        printf("\nEnter option number (0 to checkout): ");
        scanf(" %s", input);
        if (!validate_input(input)) {
            printf("\nInvalid input. Please try again.\n");
            continue;
        }
        option = atoi(input);
        if (option < 0 || option > num_items) {
            printf("\nInvalid option. Please try again.\n");
            continue;
        } else if (option == 0) {
            break;
        }
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        if (quantity <= 0) {
            printf("\nInvalid quantity. Please try again.\n");
            continue;
        }
        choice[option-1] += quantity;
        item_total[option-1] = items[option-1].price * quantity;
        subtotal += item_total[option-1];
        printf("\n%s x %d Item(s) Added\n", items[option-1].name, quantity);
    } while(1);
    printf("\n--------------------\n");
    printf("Items\tQty\tTotal\n");
    for (i = 0; i < num_items; i++) {
        if (choice[i] > 0) {
            printf("%s\t%d\t%.2f\n", items[i].name, choice[i], item_total[i]);
        }
    }
    tax = calculate_tax(subtotal);
    service_charge = calculate_service_charge(subtotal);
    total = subtotal + tax + service_charge;
    printf("--------------------\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Sales Tax (10%%): $%.2f\n", tax);
    printf("Service Charge (5%%): $%.2f\n", service_charge);
    printf("Total: $%.2f\n", total);
    printf("--------------------\n");
    printf("Thank you for visiting Cafe!\n");
    return 0;
}