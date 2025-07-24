//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROOMS 20
#define MAX_RESERVATIONS 50

typedef struct {
    int id;
    int floor;
    int capacity;
    int reserved;
} room_t;

typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[15];
    int room_id;
    int nights;
} reservation_t;

void add_room(room_t* rooms){
    int i;
    for (i=0; i<MAX_ROOMS; i++){
        if (rooms[i].id == -1){
            printf("Enter room details:\n");
            printf("Room ID: ");
            scanf("%d", &rooms[i].id);
            printf("Floor: ");
            scanf("%d", &rooms[i].floor);
            printf("Capacity: ");
            scanf("%d", &rooms[i].capacity);
            rooms[i].reserved = 0;
            break;
        }
    }
}

void add_reservation(reservation_t* reservations, room_t* rooms){
    int room_id, nights, i;
    char name[50], email[50], phone[15];
    for (i=0; i<MAX_RESERVATIONS; i++){
        if (reservations[i].id == -1){
            printf("Enter reservation details:\n");
            printf("Name: ");
            scanf("%s", name);
            printf("Email: ");
            scanf("%s", email);
            printf("Phone: ");
            scanf("%s", phone);
            printf("Room ID: ");
            scanf("%d", &room_id);
            printf("Nights: ");
            scanf("%d", &nights);

            int room_index = -1;
            for (int j=0; j<MAX_ROOMS; j++){
                if (rooms[j].id == room_id){
                    room_index = j;
                    break;
                }
            }

            if (room_index != -1 && rooms[room_index].reserved == 0){
                reservations[i].id = i+1;
                strcpy(reservations[i].name, name);
                strcpy(reservations[i].email, email);
                strcpy(reservations[i].phone, phone);
                reservations[i].room_id = room_id;
                reservations[i].nights = nights;

                rooms[room_index].reserved = 1;

                printf("Reservation added successfully.\n");
            }
            else {
                printf("Room ID not found or room already reserved.\n");
            }
            break;
        }
    }
}

void view_reservations(reservation_t* reservations){
    printf("Reservations:\n");
    for (int i=0; i<MAX_RESERVATIONS; i++){
        if (reservations[i].id != -1){
            printf("Reservation ID: %d\n", reservations[i].id);
            printf("Name: %s\n", reservations[i].name);
            printf("Email: %s\n", reservations[i].email);
            printf("Phone: %s\n", reservations[i].phone);
            printf("Room ID: %d\n", reservations[i].room_id);
            printf("Nights: %d\n", reservations[i].nights);
        }
    }
    printf("\n");
}

int main(){
    room_t rooms[MAX_ROOMS];
    reservation_t reservations[MAX_RESERVATIONS];

    // Initialize rooms and reservations to default values
    for (int i=0; i<MAX_ROOMS; i++){
        rooms[i].id = -1;
    }

    for (int i=0; i<MAX_RESERVATIONS; i++){
        reservations[i].id = -1;
    }

    int choice;
    do {
        printf("========== Hotel Management System ==========\n");
        printf("1. Add Room\n");
        printf("2. Add Reservation\n");
        printf("3. View Reservations\n");
        printf("4. Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                add_room(rooms);
                break;
            case 2:
                add_reservation(reservations, rooms);
                break;
            case 3:
                view_reservations(reservations);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid Choice. Try Again.\n");
        }
    } while (choice != 4);

    return 0;
}