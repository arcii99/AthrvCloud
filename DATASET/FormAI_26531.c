//FormAI DATASET v1.0 Category: Hotel Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for storing guest information
struct Guest {
    int roomNumber;
    char name[50];
    char email[50];
    char phoneNumber[15];
    int daysStayed;
    float totalBill;
} guests[100];

// function to display guest information
void displayGuestData(struct Guest guest) {
    printf("\nRoom Number: %d", guest.roomNumber);
    printf("\nName: %s", guest.name);
    printf("\nEmail: %s", guest.email);
    printf("\nPhone Number: %s", guest.phoneNumber);
    printf("\nDays Stayed: %d", guest.daysStayed);
    printf("\nTotal Bill: $%.2f\n", guest.totalBill);
}

// function to search for guest information by room number
void searchGuestByRoomNumber(int roomNumber, int numGuests) {
    int i;
    for (i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            printf("\nGuest Information Found:\n");
            displayGuestData(guests[i]);
            return;
        }
    }
    printf("\nGuest information not found for room number %d.\n", roomNumber);
}

// function to calculate total bill for a guest
float calculateTotalBill(int daysStayed) {
    float roomCharge = 150.0;
    float taxRate = 0.07;
    return (daysStayed * roomCharge) + ((daysStayed * roomCharge) * taxRate);
}

// function to add a new guest to the system
void addNewGuest(int *numGuestsPtr) {
    int roomNumber, daysStayed;
    char name[50], email[50], phoneNumber[15];

    printf("\nEnter room number (1-100): ");
    scanf("%d", &roomNumber);
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("\nEnter email: ");
    scanf("%s", email);
    printf("\nEnter phone number: ");
    scanf("%s", phoneNumber);
    printf("\nEnter number of days stayed: ");
    scanf("%d", &daysStayed);

    guests[*numGuestsPtr].roomNumber = roomNumber;
    strcpy(guests[*numGuestsPtr].name, name);
    strcpy(guests[*numGuestsPtr].email, email);
    strcpy(guests[*numGuestsPtr].phoneNumber, phoneNumber);
    guests[*numGuestsPtr].daysStayed = daysStayed;
    guests[*numGuestsPtr].totalBill = calculateTotalBill(daysStayed);

    *numGuestsPtr += 1;
    printf("\nGuest added successfully!\n");
}

int main() {
    int numGuests = 0;
    int choice;

    while (1) {
        printf("\n----- C Hotel Management System -----\n");
        printf("\n1. Add New Guest\n");
        printf("2. Search Guest by Room Number\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewGuest(&numGuests);
                break;
            case 2:
                int roomNumber;
                printf("\nEnter room number to search for: ");
                scanf("%d", &roomNumber);
                searchGuestByRoomNumber(roomNumber, numGuests);
                break;
            case 3:
                printf("\nThank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}