//FormAI DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct hotel {
    char name[50];
    int room;
    float price;
};

struct hotel hotelList[MAX];
int count = 0;

void addHotel(char* name, int room, float price) {
    struct hotel temp_hotel;
    strcpy(temp_hotel.name, name);
    temp_hotel.room = room;
    temp_hotel.price = price;
    hotelList[count] = temp_hotel;
    count++;
}

void displayHotels() {
    printf("\n=====================================");
    printf("\n      HOTEL MANAGEMENT SYSTEM        ");
    printf("\n=====================================");
    for(int i=0; i<count; i++) {
        printf("\nName: %s", hotelList[i].name);
        printf("\nRoom: %d", hotelList[i].room);
        printf("\nPrice: $%.2f per night", hotelList[i].price);
    }
}

int main() {
    printf("Welcome to the Hotel Management System!\n");
    printf("========================================\n");

    addHotel("The Ritz-Carlton", 101, 250.00);
    addHotel("The Four Seasons", 202, 350.00);
    addHotel("The Waldorf Astoria", 303, 450.00);

    displayHotels();

    return 0;
}