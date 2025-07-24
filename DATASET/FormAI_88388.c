//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* Define the struct for our inventory items */
struct item {
    char name[50];
    int quantity;
};

/* Define the struct for our warehouse locations */
struct location {
    int aisle;
    int shelf;
    int bin;
};

/* Define the struct for our warehouse workers */
struct worker {
    char name[50];
    int id;
};

int main() {
    /* Initialize an array of 100 inventory items */
    struct item inventory[100];

    /* Initialize an array of 10 warehouse locations */
    struct location warehouse[10];

    /* Initialize an array of 5 warehouse workers */
    struct worker workers[5];

    /* Add some items to the inventory */
    strcpy(inventory[0].name, "Pencil");
    inventory[0].quantity = 200;
    strcpy(inventory[1].name, "Pen");
    inventory[1].quantity = 150;
    strcpy(inventory[2].name, "Notebook");
    inventory[2].quantity = 100;

    /* Add some locations to the warehouse */
    warehouse[0].aisle = 1;
    warehouse[0].shelf = 2;
    warehouse[0].bin = 3;
    warehouse[1].aisle = 1;
    warehouse[1].shelf = 3;
    warehouse[1].bin = 4;
    warehouse[2].aisle = 2;
    warehouse[2].shelf = 1;
    warehouse[2].bin = 2;

    /* Add some workers to the warehouse */
    strcpy(workers[0].name, "John");
    workers[0].id = 101;
    strcpy(workers[1].name, "Sara");
    workers[1].id = 102;

    /* Let the user know that the program has started */
    printf("Welcome to the Warehouse Management System!\n\n");

    /* Display the inventory */
    printf("Current inventory:\n");
    for(int i=0; i<3; i++) {
        printf("%d. %s - %d\n", i+1, inventory[i].name, inventory[i].quantity);
    }
    printf("\n");

    /* Display the warehouse locations */
    printf("Warehouse locations:\n");
    for(int i=0; i<3; i++) {
        printf("%d. Aisle %d, Shelf %d, Bin %d\n", i+1, warehouse[i].aisle, warehouse[i].shelf, warehouse[i].bin);
    }
    printf("\n");

    /* Display the warehouse workers */
    printf("Warehouse workers:\n");
    for(int i=0; i<2; i++) {
        printf("%d. %s (ID: %d)\n", i+1, workers[i].name, workers[i].id);
    }
    printf("\n");

    /* Let the user know that the program has finished */
    printf("Thank you for using the Warehouse Management System!\n");

    return 0;
}