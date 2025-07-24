//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Guest {
    char name[50];
    int roomNumber;
    int daysStayed;
};

int main() {
    int numGuests;
    printf("Enter number of guests: ");
    scanf("%d", &numGuests);
    struct Guest guests[numGuests];
    for (int i = 0; i < numGuests; i++) {
        printf("Guest %d name: ", i+1);
        scanf("%s", guests[i].name);
        printf("Guest %d room number: ", i+1);
        scanf("%d", &guests[i].roomNumber);
        printf("Guest %d days stayed: ", i+1);
        scanf("%d", &guests[i].daysStayed);
    }

    printf("\nGuest List:\n");
    for (int i = 0; i < numGuests; i++) {
        printf("Name: %s\n", guests[i].name);
        printf("Room number: %d\n", guests[i].roomNumber);
        printf("Days stayed: %d\n", guests[i].daysStayed);
        int rate = 100;
        int totalCost = rate * guests[i].daysStayed;
        printf("Total cost: $%d\n", totalCost);
        printf("\n");
    }
    return 0;
}