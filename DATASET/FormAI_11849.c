//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>

struct Warehouse {
    int id;
    char name[50];
    int quantity;
};

int main() {
    // initializing the warehouse items
    struct Warehouse w1 = { 1, "Item A", 100 };
    struct Warehouse w2 = { 2, "Item B", 50 };
    struct Warehouse w3 = { 3, "Item C", 200 };
    struct Warehouse w4 = { 4, "Item D", 75 };
    struct Warehouse w5 = { 5, "Item E", 150 };
    
    // printing the initial warehouse status
    printf("Initial Warehouse Status:\n");
    printf("Item %d - %s: %d\n", w1.id, w1.name, w1.quantity);
    printf("Item %d - %s: %d\n", w2.id, w2.name, w2.quantity);
    printf("Item %d - %s: %d\n", w3.id, w3.name, w3.quantity);
    printf("Item %d - %s: %d\n", w4.id, w4.name, w4.quantity);
    printf("Item %d - %s: %d\n", w5.id, w5.name, w5.quantity);
    
    // updating the warehouse items
    w1.quantity -= 25;
    w2.quantity += 10;
    w3.quantity -= 50;
    w4.quantity += 20;
    w5.quantity -= 100;
    
    // printing the final warehouse status
    printf("\nFinal Warehouse Status:\n");
    printf("Item %d - %s: %d\n", w1.id, w1.name, w1.quantity);
    printf("Item %d - %s: %d\n", w2.id, w2.name, w2.quantity);
    printf("Item %d - %s: %d\n", w3.id, w3.name, w3.quantity);
    printf("Item %d - %s: %d\n", w4.id, w4.name, w4.quantity);
    printf("Item %d - %s: %d\n", w5.id, w5.name, w5.quantity);
    
    return 0;
}