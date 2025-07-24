//FormAI DATASET v1.0 Category: Hotel Management System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct room {
    int room_number;
    int occupant_count;
    int occupied;
};

struct guest {
    char name[50];
    int age;
    char gender;
    char address[50];
    char nationality[50];
    int room_number;
};

int main() {
    int choice;
    struct room rooms[10];
    struct guest guests[10];

    for(int i=0;i<10;i++){
        rooms[i].room_number = i+1;
        rooms[i].occupied=0;
        rooms[1].occupant_count=0;
    }

    do {
        printf("\n\n");
        printf("======Hotel Management System======\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Room List\n");
        printf("4. Guest List\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    int room_number;
                    printf("\nEnter Room Number: ");
                    scanf("%d", &room_number);

                    if(rooms[room_number-1].occupied == 1) {
                        printf("\nRoom is already occupied!\n");
                        break;
                    }
                    else {
                        guests[room_number-1].room_number = room_number;
                        printf("\nEnter Guest Name: ");
                        scanf("%s", guests[room_number-1].name);
                        printf("\nEnter Guest Age: ");
                        scanf("%d", &guests[room_number-1].age);
                        printf("\nEnter Guest Gender(M/F): ");
                        scanf("%s", &guests[room_number-1].gender);
                        printf("\nEnter Guest Address: ");
                        scanf("%s", guests[room_number-1].address);
                        printf("\nEnter Guest Nationality: ");
                        scanf("%s", guests[room_number-1].nationality);

                        rooms[room_number-1].occupied = 1;
                        rooms[room_number-1].occupant_count++;
                        printf("\nChecked In Successfully\n");
                    }
                    break;
                }

            case 2:
                {
                    int room_number;

                    printf("\nEnter Room Number: ");
                    scanf("%d", &room_number);

                    if(rooms[room_number-1].occupied == 0) {
                        printf("\nRoom is already vacant!\n");
                        break;
                    }
                    else {
                        guests[room_number-1].room_number = 0;
                        printf("\nChecked Out Successfully\n");
                        rooms[room_number-1].occupied = 0;
                        rooms[room_number-1].occupant_count--;
                    }
                    break;
                }

            case 3:
                {
                    printf("\nRoom Number\tStatus\tGuest Count\n");

                    for(int i=0;i<10;i++) {
                        printf("%d\t\t", rooms[i].room_number);
                        if(rooms[i].occupied == 1)
                            printf("Occupied\t%d\n", rooms[i].occupant_count);
                        else
                            printf("Vacant\n");
                    }
                    break;
                }

            case 4:
                {
                    printf("\nName\tAge\tGender\tAddress\tNationality\tRoom No.\n");

                    for(int i=0;i<10;i++) {
                        if(strcmp(guests[i].name, "") != 0) {
                            printf("%s\t%d\t%c\t%s\t%s\t\t%d\n", guests[i].name, guests[i].age, guests[i].gender, guests[i].address, guests[i].nationality, guests[i].room_number);
                        }
                    }
                    break;
                }

            case 5:
                break;

            default:
                printf("\nInvalid Choice!\n");
        }
    } while(choice != 5);

    return 0;
}