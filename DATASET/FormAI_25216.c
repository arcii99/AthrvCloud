//FormAI DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct {
    int roomNumber;
    char guestName[50];
    bool isOccupied;
    int daysOccupied;
    float roomRate;
    float totalCharge;
    time_t checkInDate;
    time_t checkOutDate;
} Room;

char* formatDate(time_t date) {
    char* buffer = malloc(sizeof(char) * 20);
    strftime(buffer, 20, "%Y-%m-%d", localtime(&date));
    return buffer;
}

void* checkIn(void* arg) {
    Room* room = (Room*) arg;

    printf("Enter guest name for room %d: ", room->roomNumber);
    fgets(room->guestName, sizeof(room->guestName), stdin);
    room->guestName[strlen(room->guestName) - 1] = '\0';

    printf("Enter room rate for room %d: ", room->roomNumber);
    scanf("%f", &room->roomRate);

    printf("Enter number of days to occupy room %d: ", room->roomNumber);
    scanf("%d", &room->daysOccupied);

    time(&room->checkInDate);
    room->isOccupied = true;

    float totalCharge = room->roomRate * (float) room->daysOccupied;
    room->totalCharge = totalCharge;

    printf("\nCheck-in successful!\n");
    printf("------------------------------------------------\n");
    printf("Room Number: %d\n", room->roomNumber);
    printf("Guest Name: %s\n", room->guestName);
    printf("Room Rate: %.2f\n", room->roomRate);
    printf("Days Occupied: %d\n", room->daysOccupied);
    printf("Check-in Date: %s\n", formatDate(room->checkInDate));
    printf("Total Charge: %.2f\n", totalCharge);
    printf("------------------------------------------------\n");

    pthread_exit(NULL);
}

void* checkOut(void* arg) {
    Room* room = (Room*) arg;

    time(&room->checkOutDate);

    float totalCharge = room->totalCharge;
    room->isOccupied = false;

    printf("\n\n------------------------------------------------\n");
    printf("Room Number: %d\n", room->roomNumber);
    printf("Guest Name: %s\n", room->guestName);
    printf("Room Rate: %.2f\n", room->roomRate);
    printf("Days Occupied: %d\n", room->daysOccupied);
    printf("Check-in Date: %s\n", formatDate(room->checkInDate));
    printf("Check-out Date: %s\n", formatDate(room->checkOutDate));
    printf("Total Charge: %.2f\n", totalCharge);
    printf("------------------------------------------------\n\n");

    pthread_exit(NULL);
}

int main() {
    Room rooms[10];

    for (int i = 0; i < 10; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isOccupied = false;
    }

    while (true) {
        printf("\n\n***************** H O T E L  M A N A G E M E N T  S Y S T E M *****************\n\n");
        printf("Room\tGuest Name\tRoom Rate\tDays Occupied\tCheck-in Date\t\tCheck-out Date\n");

        for (int i = 0; i < 10; i++) {
            Room room = rooms[i];

            if (room.isOccupied) {
                printf("%d\t%s\t\t%.2f\t\t%d\t\t%s\t%s\n", room.roomNumber, room.guestName, room.roomRate, room.daysOccupied, formatDate(room.checkInDate), formatDate(room.checkOutDate));
            } else {
                printf("%d\t---\t\t---\t\t---\t\t---\t\t---\n", room.roomNumber);
            }
        }

        printf("\n\n1. Check-in\n");
        printf("2. Check-out\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        int roomNumber;

        if (choice == 1) {
            printf("Enter room number: ");
            scanf("%d", &roomNumber);

            if (rooms[roomNumber - 1].isOccupied) {
                printf("Room %d is already occupied!\n", roomNumber);
            } else {
                pthread_t tid;
                pthread_attr_t attr;

                pthread_attr_init(&attr);
    	        pthread_create(&tid, &attr, checkIn, &rooms[roomNumber - 1]);
    	        pthread_join(tid, NULL);
            }
        } else if (choice == 2) {
            printf("Enter room number: ");
            scanf("%d", &roomNumber);

            if (!rooms[roomNumber - 1].isOccupied) {
                printf("Room %d is not occupied!\n", roomNumber);
            } else {
                pthread_t tid;
                pthread_attr_t attr;

                pthread_attr_init(&attr);
    	        pthread_create(&tid, &attr, checkOut, &rooms[roomNumber - 1]);
    	        pthread_join(tid, NULL);
            }
        }
    }

    return 0;
}