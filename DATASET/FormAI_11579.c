//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <string.h>

struct Hotel {
    char name[50];
    int rooms;
    float price;
};

void printHotel(struct Hotel h) {
    printf("%s has %d rooms starting at $%.2f per night.\n", h.name, h.rooms, h.price);
}

int main() {
    int numHotels;
    printf("How many hotels would you like to manage? ");
    scanf("%d", &numHotels);
    
    struct Hotel hotels[numHotels];
    
    for (int i = 0; i < numHotels; i++) {
        printf("Enter the name of hotel %d: ", i+1);
        scanf("%s", &hotels[i].name);
        printf("Enter the number of rooms in %s: ", hotels[i].name);
        scanf("%d", &hotels[i].rooms);
        printf("Enter the starting price per night for %s: ", hotels[i].name);
        scanf("%f", &hotels[i].price);
    }
    
    printf("Here are the hotels you have managed:\n");
    for (int i = 0; i < numHotels; i++) {
        printHotel(hotels[i]);
    }
    
    return 0;
}