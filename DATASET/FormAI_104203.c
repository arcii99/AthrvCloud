//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining a structure for room details
struct roomDetails{
    int roomNo;
    char status[10];
};

// A function to display the room status
void displayStatus(struct roomDetails * room){
    printf("\nRoom No: %d\nRoom Status: %s\n", room->roomNo, room->status);
}

int main(){
    // Creating an array of roomDetails structures
    struct roomDetails hotel[50];

    // Initializing all room statuses as vacant
    for(int i=0; i<50; i++){
        hotel[i].roomNo = i+1; // Room numbers will start from 1
        strcpy(hotel[i].status, "Vacant"); 
    }

    // Displaying available room status
    printf("\nAvailable Rooms:\n");
    for(int i=0; i<50; i++){
        displayStatus(&hotel[i]);
    }

    // Checking in a guest
    int roomNumber;
    printf("\nEnter Room Number for Check-In: ");
    scanf("%d", &roomNumber);

    // Updating room status as occupied
    strcpy(hotel[roomNumber-1].status, "Occupied");

    // Displaying updated room status
    printf("\nUpdated Room Status");
    displayStatus(&hotel[roomNumber-1]);

    // Checking out a guest
    printf("\nEnter Room Number for Check-Out: ");
    scanf("%d", &roomNumber);

    // Updating room status as vacant
    strcpy(hotel[roomNumber-1].status, "Vacant");

    // Displaying updated room status
    printf("\nUpdated Room Status");
    displayStatus(&hotel[roomNumber-1]);

    return 0;
}