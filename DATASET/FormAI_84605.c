//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for each guest
struct guest{
    char name[50];
    int roomNumber;
    int numDaysStaying;
    float totalBill;
};

//Structure for each room
struct room{
    int roomNumber;
    char type[20];
    int numBeds;
    float costPerNight;
    int isAvailable;
};

typedef struct room room; //alias for struct room
typedef struct guest guest; //alias for struct guest

//Function to check if a room is available
int isRoomAvailable(room r){
    return r.isAvailable;
}

//Function to display a guest's information
void displayGuest(guest g){
    printf("Name: %s\n", g.name);
    printf("Room Number: %d\n", g.roomNumber);
    printf("Num. of days staying: %d\n", g.numDaysStaying);
    printf("Total Bill: %.2f\n", g.totalBill);
}

//Function to display a room's information
void displayRoom(room r){
    printf("Room Number: %d\n", r.roomNumber);
    printf("Type: %s\n", r.type);
    printf("Number of beds: %d\n", r.numBeds);
    printf("Cost per night: %.2f\n", r.costPerNight);
    printf("Availability: %s\n", (r.isAvailable ? "Available" : "Occupied"));
}

//Function to reserve a room for a guest
void reserveRoom(room *r, guest *g){
    g->roomNumber = r->roomNumber;
    printf("Enter num. of days staying: ");
    scanf("%d", &g->numDaysStaying);
    g->totalBill = g->numDaysStaying * r->costPerNight;
    r->isAvailable = 0;
    printf("Room reserved!\n");
}

//Main function
int main(){
    //Initialize rooms
    room rooms[5];
    for(int i=0; i<5; i++){
        rooms[i].roomNumber = i+1;
        strcpy(rooms[i].type, (i%2==0 ? "Single" : "Double"));
        rooms[i].numBeds = (i%2==0 ? 1 : 2);
        rooms[i].costPerNight = (i%2==0 ? 50.0 : 80.0);
        rooms[i].isAvailable = 1;
    }

    //Initialize guests
    guest guests[5];
    for(int i=0; i<5; i++){
        strcpy(guests[i].name, "Guest");
        guests[i].roomNumber = -1;
        guests[i].numDaysStaying = 0;
        guests[i].totalBill = 0.0;
    }

    int choice, roomNum, guestIndex;

    printf("***HOTEL MANAGEMENT SYSTEM***\n");

    do{
        printf("\n\n");
        printf("1. View all rooms\n");
        printf("2. View all available rooms\n");
        printf("3. View all guests\n");
        printf("4. Reserve a room\n");
        printf("5. Check out a guest\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //View all rooms
                for(int i=0; i<5; i++){
                    displayRoom(rooms[i]);
                }
                break;
            case 2:
                //View all available rooms
                for(int i=0; i<5; i++){
                    if(isRoomAvailable(rooms[i])){
                        displayRoom(rooms[i]);
                    }
                }
                break;
            case 3:
                //View all guests
                for(int i=0; i<5; i++){
                    if(guests[i].roomNumber != -1){
                        displayGuest(guests[i]);
                    }
                }
                break;
            case 4:
                //Reserve a room
                printf("Enter room number: ");
                scanf("%d", &roomNum);
                for(int i=0; i<5; i++){
                    if(rooms[i].roomNumber == roomNum && isRoomAvailable(rooms[i])){
                        printf("Enter guest name: ");
                        scanf("%s", guests[i].name);
                        reserveRoom(&rooms[i], &guests[i]);
                        break;
                    }
                    else if(i == 4){
                        printf("Invalid room number or room is already occupied!");
                    }
                }
                break;
            case 5:
                //Check out a guest
                printf("Enter room number: ");
                scanf("%d", &roomNum);
                for(int i=0; i<5; i++){
                    if(guests[i].roomNumber == roomNum){
                        guestIndex = i;
                        break;
                    }
                    else if(i == 4){
                        printf("Invalid room number or room is already unoccupied!");
                    }
                }

                displayGuest(guests[guestIndex]);
                printf("Thank you for staying with us, %s! Your total bill is %.2f\n", guests[guestIndex].name, guests[guestIndex].totalBill);
                guests[guestIndex].roomNumber = -1;
                guests[guestIndex].numDaysStaying = 0;
                guests[guestIndex].totalBill = 0.0;
                for(int i=0; i<5; i++){
                    if(rooms[i].roomNumber == roomNum){
                        rooms[i].isAvailable = 1;
                        printf("Room is now available for occupancy.");
                        break;
                    }
                }
                break;
            case 6:
                printf("Thank you for using our hotel management system.");
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }while(choice != 6);

    return 0;
}