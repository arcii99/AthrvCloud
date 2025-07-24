//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <string.h>

// Define a structure to hold information about guests
typedef struct {
    char name[50];
    int roomNumber;
    int numNights;
    float costPerNight;
    float totalCost;
} Guest;

int main() {
    int numGuests, i;
    float hotelRevenue = 0.0;

    // Prompt the user for the number of guests
    printf("Welcome to the C Hotel Management System!\n");
    printf("How many guests are checking in today? ");
    scanf("%d", &numGuests);

    // Define an array of guests based on the number of guests provided
    Guest guests[numGuests];

    // Prompt the user for information about each guest
    for (i = 0; i < numGuests; i++) {
        printf("\nGuest %d\n", i+1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Room number: ");
        scanf("%d", &guests[i].roomNumber);
        printf("Number of nights: ");
        scanf("%d", &guests[i].numNights);
        printf("Cost per night: ");
        scanf("%f", &guests[i].costPerNight);

        // Calculate the total cost of the guest's stay
        guests[i].totalCost = guests[i].numNights * guests[i].costPerNight;
        hotelRevenue += guests[i].totalCost;
    }

    // Print out a summary of the guests and the hotel's revenue
    printf("\nGuest Summary\n");
    for (i = 0; i < numGuests; i++) {
        printf("%s (room %d): %.2f\n", guests[i].name, guests[i].roomNumber, guests[i].totalCost);
    }
    printf("Hotel Revenue: %.2f\n", hotelRevenue);

    return 0;
}