//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    char name[50];
    int roomNum;
    float price;
    char location[50];
};

int main() {
    struct hotel h1, h2, h3;
    strcpy(h1.name, "Hilton");
    h1.roomNum = 101;
    h1.price = 199.99;
    strcpy(h1.location, "New York");

    strcpy(h2.name, "Marriott");
    h2.roomNum = 202;
    h2.price = 149.99;
    strcpy(h2.location, "Los Angeles");

    strcpy(h3.name, "Sheraton");
    h3.roomNum = 303;
    h3.price = 99.99;
    strcpy(h3.location, "Miami");

    printf("Welcome to the Hotel Management System!\n\n");
    printf("Hotel 1:\n");
    printf("Name: %s\n", h1.name);
    printf("Room Number: %d\n", h1.roomNum);
    printf("Price per Night: $%.2f\n", h1.price);
    printf("Location: %s\n\n", h1.location);

    printf("Hotel 2:\n");
    printf("Name: %s\n", h2.name);
    printf("Room Number: %d\n", h2.roomNum);
    printf("Price per Night: $%.2f\n", h2.price);
    printf("Location: %s\n\n", h2.location);

    printf("Hotel 3:\n");
    printf("Name: %s\n", h3.name);
    printf("Room Number: %d\n", h3.roomNum);
    printf("Price per Night: $%.2f\n", h3.price);
    printf("Location: %s\n", h3.location);

    printf("\nThank you for using the Hotel Management System!\n");

    return 0;
}