//FormAI DATASET v1.0 Category: Hotel Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 100
#define MAX_OCCUPANTS 2

// Struct for Room Information
struct Room{
    int room_num;
    bool is_occupied;
    char occupants[MAX_OCCUPANTS][30];
    char room_type[20];
    int room_rate;
    char check_in_date[30];
    char check_out_date[30];
};

// Function Declaration
void display_menu();
void view_rooms(struct Room *rooms);
void book_room(struct Room *rooms);
void view_occupants(struct Room *rooms);
void checkout(struct Room *rooms);

int main(){
    // Initializing Rooms
    struct Room rooms[MAX_ROOMS];
    for(int i=0; i<MAX_ROOMS; i++){
        rooms[i].room_num = i+1;
        rooms[i].is_occupied = false;
        strcpy(rooms[i].room_type, "Basic");
        rooms[i].room_rate = 50;
        strcpy(rooms[i].check_in_date, "");
        strcpy(rooms[i].check_out_date, "");
    }

    // Welcome Message
    printf("Welcome to the C Hotel Management System! \n");
    display_menu(); // Display Menu

    int choice = 0;
    while(choice != 5){ // Exit Condition
        // Prompt User for Choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: view_rooms(rooms); break;
            case 2: book_room(rooms); break;
            case 3: view_occupants(rooms); break;
            case 4: checkout(rooms); break;
            case 5: printf("Exiting Program! "); break;
            default: printf("Invalid Choice! "); break;
        }

        if(choice != 5){
            // Reload Menu
            printf("\n\n");
            display_menu();
        }
    }

    return 0;
}

void display_menu(){
    printf("===== MENU =====\n");
    printf("1. View Rooms\n");
    printf("2. Book Room\n");
    printf("3. View Occupants\n");
    printf("4. Check-Out\n");
    printf("5. Exit\n");
}

void view_rooms(struct Room *rooms){
    printf("===== ROOMS =====\n");
    printf("Room No.\tType\tRate\tStatus\n");

    for(int i=0; i<MAX_ROOMS; i++){
        printf("%d\t\t%s\t$%d\t", rooms[i].room_num, rooms[i].room_type, rooms[i].room_rate);
        if(rooms[i].is_occupied == true){
            printf("Occupied");
            printf("\tOccupants: %s", rooms[i].occupants[0]);
            if(strcmp(rooms[i].occupants[1], "") != 0){
                printf(", %s", rooms[i].occupants[1]);
            }
            printf(", Check-In: %s", rooms[i].check_in_date);
            printf(", Check-Out: %s", rooms[i].check_out_date);
        }else{
            printf("Available");
        }
        printf("\n");
    }
}

void book_room(struct Room *rooms){
    printf("===== BOOK ROOM =====\n\n");
    printf("Enter Room No.: ");
    int room_no;
    scanf("%d", &room_no);

    // Check if Room Exists
    if(room_no < 1 || room_no > MAX_ROOMS){
        printf("Invalid Room No.! ");
        return;
    }

    // Check if Room is Available
    if(rooms[room_no-1].is_occupied == true){
        printf("Room already occupied! ");
        return;
    }

    // Get User Input
    char occupants[MAX_OCCUPANTS][30];
    printf("\nEnter Name of Occupant 1: ");
    scanf(" %[^\n]s", occupants[0]);
    printf("Enter Name of Occupant 2 (Optional, press enter to skip): ");
    scanf(" %[^\n]s", occupants[1]);
    char check_in_date[30];
    char check_out_date[30];
    printf("Enter Check-In Date (DD/MM/YYYY): ");
    scanf(" %[^\n]s", check_in_date);
    printf("Enter Check-Out Date (DD/MM/YYYY): ");
    scanf(" %[^\n]s", check_out_date);

    // Update Room Information
    rooms[room_no-1].is_occupied = true;
    strcpy(rooms[room_no-1].occupants[0], occupants[0]);
    if(strcmp(occupants[1], "") != 0){
        strcpy(rooms[room_no-1].occupants[1], occupants[1]);
    }
    strcpy(rooms[room_no-1].check_in_date, check_in_date);
    strcpy(rooms[room_no-1].check_out_date, check_out_date);

    printf("\n\nRoom %d has been booked! \n", room_no);
}

void view_occupants(struct Room *rooms){
    printf("===== OCCUPANTS =====\n\n");

    // Check if any Rooms are Occupied
    bool is_occupied = false;
    for(int i=0; i<MAX_ROOMS; i++){
        if(rooms[i].is_occupied == true){
            is_occupied = true;
            break;
        }
    }

    if(is_occupied == false){
        printf("No Rooms are Occupied! ");
        return;
    }

    // Get User Input
    printf("Enter Room No.: ");
    int room_no;
    scanf("%d", &room_no);

    // Check if Room Exists and is Occupied
    if(room_no < 1 || room_no > MAX_ROOMS){
        printf("Invalid Room No.! ");
        return;
    }else{
        if(rooms[room_no-1].is_occupied == false){
            printf("Room is not Occupied! ");
            return;
        }
    }

    printf("\nOccupants of Room %d: %s", room_no, rooms[room_no-1].occupants[0]);
    if(strcmp(rooms[room_no-1].occupants[1], "") != 0){
        printf(", %s", rooms[room_no-1].occupants[1]);
    }
    printf("\n");
}

void checkout(struct Room *rooms){
    printf("===== CHECK-OUT =====\n\n");

    // Check if any Rooms are Occupied
    bool is_occupied = false;
    for(int i=0; i<MAX_ROOMS; i++){
        if(rooms[i].is_occupied == true){
            is_occupied = true;
            break;
        }
    }

    if(is_occupied == false){
        printf("No Rooms are Occupied! ");
        return;
    }

    // Get User Input
    printf("Enter Room No.: ");
    int room_no;
    scanf("%d", &room_no);

    // Check if Room Exists and is Occupied
    if(room_no < 1 || room_no > MAX_ROOMS){
        printf("Invalid Room No.! ");
        return;
    }else{
        if(rooms[room_no-1].is_occupied == false){
            printf("Room is not Occupied! ");
            return;
        }
    }

    // Calculate Bill
    int rate = rooms[room_no-1].room_rate;
    char check_in_date[30];
    strcpy(check_in_date, rooms[room_no-1].check_in_date);
    char check_out_date[30];
    strcpy(check_out_date, rooms[room_no-1].check_out_date);
    int check_in_day, check_in_month, check_in_year;
    sscanf(check_in_date, "%d/%d/%d", &check_in_day, &check_in_month, &check_in_year);
    int check_out_day, check_out_month, check_out_year;
    sscanf(check_out_date, "%d/%d/%d", &check_out_day, &check_out_month, &check_out_year);
    int days_stayed = (check_out_year - check_in_year)*365 + (check_out_month - check_in_month)*30 + (check_out_day - check_in_day);
    int total_bill = rate*days_stayed;

    printf("\nTotal Bill: $%d", total_bill);

    // Update Room Information
    rooms[room_no-1].is_occupied = false;
    strcpy(rooms[room_no-1].occupants[0], "");
    strcpy(rooms[room_no-1].occupants[1], "");
    strcpy(rooms[room_no-1].check_in_date, "");
    strcpy(rooms[room_no-1].check_out_date, "");

    printf("\n\nCheck-Out of Room %d completed! \n", room_no);
}