//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <string.h>

//Structure to hold details of a hotel guest
struct Guest {
    char name[50];
    int roomNumber;
    int days;
    float billAmount;
};

//Function to calculate the bill amount for a guest based on the number of days stayed
float calcBill(int days) {
    float rate = 100; //room charge per day
    float discount = 0; //discount percentage
    if (days >= 3 && days < 7) {
        discount = 5;
    } else if (days >= 7) {
        discount = 10;
    }
    float billAmt = days * rate;
    billAmt -= (billAmt * discount) / 100;
    return billAmt;
}

int main() {
    int numGuests = 0;
    printf("Welcome to Happy Hotel Management System!\n");
    printf("Please enter the number of guests: ");
    scanf("%d", &numGuests);
    struct Guest guests[numGuests];

    //Get details of all the guests
    for (int i = 0; i < numGuests; i++) {
        printf("\nEnter details of Guest %d:\n", i+1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Room number: ");
        scanf("%d", &guests[i].roomNumber);
        printf("Number of days stayed: ");
        scanf("%d", &guests[i].days);

        //Calculate bill amount for the guest
        guests[i].billAmount = calcBill(guests[i].days);
        printf("Bill amount for Guest %d: %.2f\n", i+1, guests[i].billAmount);
    }

    //Display the billing summary for all guests
    printf("\n\n-------------------------BILL SUMMARY-------------------------\n");
    printf("|%-20s|%-15s|%-10s|%-15s|\n", "Guest Name", "Room Number", "Days", "Bill Amount");
    printf("----------------------------------------------------------------\n");
    float totalBill = 0;
    for (int i = 0; i < numGuests; i++) {
        printf("|%-20s|%-15d|%-10d|%-15.2f|\n", guests[i].name, guests[i].roomNumber, guests[i].days, guests[i].billAmount);
        totalBill += guests[i].billAmount;
    }
    printf("----------------------------------------------------------------\n");
    printf("|%-46s|%-15.2f|\n", "Total Bill Amount:", totalBill);
    printf("----------------------------------------------------------------\n");

    return 0;
}