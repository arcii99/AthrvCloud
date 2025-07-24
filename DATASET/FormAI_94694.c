//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int id;
    char name[50];
    int price;
    int quantity;
    int total;
};

void printline(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void printItem(struct item *item, int width) {
    printf("| %*d | %-*s | %*d | %*d | %*d |\n", 3, item->id, width, item->name, 5, item->price, 4, item->quantity, 5, item->total);
}

int main() {
    struct item items[100];
    int choice, count = 0;
    int item_id, item_qty;

    while (1) {
        printf("\nMenu\n");
        printline(50);
        printf("| %-*s | %*s | %*s |\n", 20, "Name", 5, "Price", 4, "Qty");
        printline(50);
        printf("| %-*s | %*s | %*s |\n", 20, "Coffee", 5, "30", 4, "");
        printf("| %-*s | %*s | %*s |\n", 20, "Tea", 5, "20", 4, "");
        printf("| %-*s | %*s | %*s |\n", 20, "Sandwich", 5, "50", 4, "");
        printf("| %-*s | %*s | %*s |\n", 20, "Cake", 5, "70", 4, "");
        printline(50);

        printf("Enter item id and quantity (0 to exit): ");
        scanf("%d %d", &item_id, &item_qty);

        if (item_id == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (items[i].id == item_id) {
                found = 1;
                items[i].quantity += item_qty;
                items[i].total += items[i].price * item_qty;
                break;
            }
        }

        if (!found) {
            struct item new_item;
            new_item.id = item_id;
            strncpy(new_item.name, item_id == 1 ? "Coffee" : item_id == 2 ? "Tea" : item_id == 3 ? "Sandwich" : "Cake", sizeof(new_item.name));
            new_item.price = item_id == 1 ? 30 : item_id == 2 ? 20 : item_id == 3 ? 50 : 70;
            new_item.quantity = item_qty;
            new_item.total = new_item.price * item_qty;
            items[count++] = new_item;
        }
    }

    if (count > 0) {
        printf("\n\nBilling details:\n");
        printline(65);
        printf("| %-*s | %*s | %*s | %*s |\n", 20, "Name", 5, "Price", 4, "Qty", 5, "Total");
        printline(65);
        int total = 0;
        for (int i = 0; i < count; i++) {
            printItem(&items[i], 20);
            total += items[i].total;
        }
        printline(65);
        printf("| %*s | %*s |\n", 51, "Total:", 5, total);
        printline(65);
    }

    return 0;
}