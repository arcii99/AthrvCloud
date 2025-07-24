//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>

int main() {
    int item1_stock = 100;
    int item2_stock = 50;
    int item3_stock = 200;

    printf("Current inventory levels:\n");
    printf("Item 1: %d\n", item1_stock);
    printf("Item 2: %d\n", item2_stock);
    printf("Item 3: %d\n\n", item3_stock);

    // Sell 20 units of item 1
    item1_stock -= 20;
    printf("20 units of item 1 sold\n");
    printf("New inventory levels:\n");
    printf("Item 1: %d\n", item1_stock);
    printf("Item 2: %d\n", item2_stock);
    printf("Item 3: %d\n\n", item3_stock);

    // Restock 75 units of item 2
    item2_stock += 75;
    printf("75 units of item 2 restocked\n");
    printf("New inventory levels:\n");
    printf("Item 1: %d\n", item1_stock);
    printf("Item 2: %d\n", item2_stock);
    printf("Item 3: %d\n", item3_stock);

    return 0;
}