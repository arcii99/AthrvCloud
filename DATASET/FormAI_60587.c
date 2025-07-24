//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about a hotel guest
struct Guest {
    char name[30];
    char checkinDate[15];
    char checkoutDate[15];
    char roomType[20];
    double roomRate;
};

int main() {
    // Initializing guest struct
    struct Guest guest;

    // Retrieving guest information
    printf("Please enter your name: ");
    fgets(guest.name, sizeof(guest.name), stdin);
    printf("Please enter your check-in date (dd/mm/yyyy): ");
    fgets(guest.checkinDate, sizeof(guest.checkinDate), stdin);
    printf("Please enter your check-out date (dd/mm/yyyy): ");
    fgets(guest.checkoutDate, sizeof(guest.checkoutDate), stdin);
    printf("Please enter your room type (single, double, suite): ");
    fgets(guest.roomType, sizeof(guest.roomType), stdin);

    // Assigning room rate based on room type
    if (strcmp(guest.roomType, "single\n") == 0) {
        guest.roomRate = 100.0;
    } else if (strcmp(guest.roomType, "double\n") == 0) {
        guest.roomRate = 150.0;
    } else if (strcmp(guest.roomType, "suite\n") == 0) {
        guest.roomRate = 250.0;
    } else {
        printf("Invalid room type!\n");
        exit(1);
    }

    // Calculating total cost of stay
    double totalCost = guest.roomRate * 5; // assuming 5 days stay

    // Displaying guest information and total cost
    printf("\nGuest Information:\n");
    printf("Name: %s", guest.name);
    printf("Check-in Date: %s", guest.checkinDate);
    printf("Check-out Date: %s", guest.checkoutDate);
    printf("Room Type: %s", guest.roomType);
    printf("Room Rate: %.2lf\n", guest.roomRate);
    printf("\nTotal Cost: $%.2lf\n", totalCost);

    return 0;
}