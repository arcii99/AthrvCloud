//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int i, j, num_items, num_locations, warehouse[MAX_SIZE][MAX_SIZE], x, y;
    printf("Welcome to Warehouse Management System\n");

    // get input for number of items and number of locations
    printf("Enter number of items: ");
    scanf("%d", &num_items);
    printf("Enter number of locations: ");
    scanf("%d", &num_locations);

    // initialize warehouse with zeros
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            warehouse[i][j] = 0;
        }
    }

    // add items to warehouse
    for (i = 0; i < num_items; i++) {
        printf("Enter location (x y) for item %d: ", i + 1);
        scanf("%d %d", &x, &y);
        if (x >= num_locations || y >= num_locations) {
            printf("Invalid location, please try again.\n");
            i--;
            continue;
        }
        warehouse[x][y]++;
    }

    // print warehouse contents
    printf("Warehouse contents:\n");
    for (i = 0; i < num_locations; i++) {
        for (j = 0; j < num_locations; j++) {
            printf("%d ", warehouse[i][j]);
        }
        printf("\n");
    }

    return 0;
}