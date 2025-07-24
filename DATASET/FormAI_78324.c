//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include <stdio.h>
#include <string.h>

struct inventory {
    char item_name[50];
    int quantity;
    char location[50];
    int availability;
};

void view_inventory(struct inventory *inv) {
    printf("Item name\tQuantity\tLocation\tAvailability\n");
    for (int i = 0; i < sizeof(inv)/sizeof(struct inventory); i++) {
        printf("%s\t%d\t%s\t%d\n", inv[i].item_name, inv[i].quantity, inv[i].location, inv[i].availability);
    }
}

int main() {
    struct inventory inv[3] = {{"Shoe", 100, "A1", 1}, {"Shirt", 50, "B2", 0}, {"Hat", 80, "C1", 1}};
    view_inventory(inv);
    return 0;
}