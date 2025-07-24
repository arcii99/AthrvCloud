//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int roomNumber;
    int reservationStatus;
    char guestName[50];
    int numberOfGuests;
} Room;

int main(){

    Room rooms[10];

    //initializing the rooms
    for(int i=0; i<10; i++){
        rooms[i].roomNumber = i+1;
        rooms[i].reservationStatus = 0;
        strcpy(rooms[i].guestName,"");
        rooms[i].numberOfGuests = 0;
    }

    int option = 0;
    int roomNumber;
    int numberOfGuests;
    char guestName[50];

    //start of menu loop
    while(option != 4){
        printf("\n\nC Hotel Management System\n");
        printf("------------------------\n");
        printf("1. Reserve Room\n");
        printf("2. View Room Status\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        printf("------------------------\n");

        printf("Enter option: ");
        scanf("%d",&option);

        switch(option){
            case 1: //Reserve Room
                printf("\nEnter room number: ");
                scanf("%d",&roomNumber);
                if(rooms[roomNumber-1].reservationStatus == 0){
                    printf("Enter guest name: ");
                    scanf("%s",guestName);
                    printf("Enter number of guests: ");
                    scanf("%d",&numberOfGuests);
                    rooms[roomNumber-1].reservationStatus = 1;
                    rooms[roomNumber-1].numberOfGuests = numberOfGuests;
                    strcpy(rooms[roomNumber-1].guestName,guestName);
                    printf("Room %d reserved successfully for %s with %d guests",roomNumber,guestName,numberOfGuests);
                }
                else{
                    printf("Room %d is already reserved",roomNumber);
                }
            break;

            case 2: //View Room Status
                printf("\nRoom Status\n");
                printf("-----------\n");
                for(int i=0; i<10; i++){
                    printf("Room %d - ",i+1);
                    if(rooms[i].reservationStatus == 0){
                        printf("Vacant\n");
                    }
                    else{
                        printf("Reserved for %s with %d guests\n",rooms[i].guestName,rooms[i].numberOfGuests);
                    }
                }
            break;

            case 3: //Check Out
                printf("\nEnter room number: ");
                scanf("%d",&roomNumber);
                if(rooms[roomNumber-1].reservationStatus == 1){
                    printf("%s has checked out from Room %d\n",rooms[roomNumber-1].guestName,roomNumber);
                    rooms[roomNumber-1].reservationStatus = 0;
                    rooms[roomNumber-1].numberOfGuests = 0;
                    strcpy(rooms[roomNumber-1].guestName,"");
                }
                else{
                    printf("Room %d is not yet reserved",roomNumber);
                }
            break;

            case 4: //Exit
                printf("\nThank you for using C Hotel Management System");
            break;

            default: //Invalid Option
                printf("\nInvalid option, please try again");
            break;
        }

    }

    return 0;
}