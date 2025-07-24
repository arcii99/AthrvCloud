//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROOMS 100
#define MAX_GUESTS 500

struct guest{
    char name[50];
    int age;
    char gender[10];
    char country[50];
};

struct room{
    int room_no;
    char room_type[20];
    int occupancy;
    struct guest guests[MAX_GUESTS];
    int bill;
};

struct hotel{
    char name[50];
    char address[100];
    struct room rooms[MAX_ROOMS];
};

void display_menu();
void add_room(struct hotel *);
void add_guest(struct hotel *);
void check_out(struct hotel *);
void display_guests(struct hotel *);
int get_room_index(struct hotel *, int);
int get_guest_index(struct hotel *, int, char *);

int main(){
    struct hotel h;
    strcpy(h.name, "SafeHotel");
    strcpy(h.address, "123 Main Street");

    for(int i=0;i<MAX_ROOMS;i++){
        h.rooms[i].room_no = i+1;
        strcpy(h.rooms[i].room_type, "Standard");
        h.rooms[i].occupancy = 0;
        h.rooms[i].bill = 0;
    }

    int choice;
    while(1){
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_room(&h); break;
            case 2: add_guest(&h); break;
            case 3: check_out(&h); break;
            case 4: display_guests(&h); break;
            case 5: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu(){
    printf("\n-----------------------\n");
    printf("Welcome to SafeHotel\n");
    printf("-----------------------\n");
    printf("1. Add Room\n");
    printf("2. Add Guest\n");
    printf("3. Check Out\n");
    printf("4. Display Guests\n");
    printf("5. Exit\n");
}

void add_room(struct hotel *h){
    for(int i=0;i<MAX_ROOMS;i++){
        if(h->rooms[i].occupancy == 0){
            printf("Enter type of room (Standard, Deluxe, Suite): ");
            scanf("%s", h->rooms[i].room_type);
            printf("Room added with number %d and type %s.\n", h->rooms[i].room_no, h->rooms[i].room_type);
            return;
        }
    }
    printf("Sorry, the hotel is fully booked.\n");
}

void add_guest(struct hotel *h){
    int room_no, index;
    char confirm;
    printf("Enter room number: ");
    scanf("%d", &room_no);
    index = get_room_index(h, room_no);
    if(index != -1){
        if(h->rooms[index].occupancy == 0){
            printf("Room is vacant.\n");
            printf("Do you want to add a guest (Y/N)? ");
            scanf(" %c", &confirm);
            if(confirm == 'Y' || confirm == 'y'){
                strcpy(h->rooms[index].guests[h->rooms[index].occupancy].name, "");
                printf("Enter name of guest: ");
                scanf("%s", h->rooms[index].guests[h->rooms[index].occupancy].name);
                printf("Enter age of guest: ");
                scanf("%d", &h->rooms[index].guests[h->rooms[index].occupancy].age);
                printf("Enter gender of guest: ");
                scanf("%s", h->rooms[index].guests[h->rooms[index].occupancy].gender);
                printf("Enter country of guest: ");
                scanf("%s", h->rooms[index].guests[h->rooms[index].occupancy].country);
                h->rooms[index].occupancy++;
                printf("Guest added to room number %d.\n", room_no);
            }
            else{
                printf("Aborting operation.\n");
            }
        }
        else{
            printf("Room is occupied.\n");
        }
    }
    else{
        printf("Room number not found.\n");
    }
}

void check_out(struct hotel *h){
    int room_no, room_index, guest_index;
    printf("Enter room number: ");
    scanf("%d", &room_no);
    room_index = get_room_index(h, room_no);
    if(room_index != -1){
        if(h->rooms[room_index].occupancy == 0){
            printf("Room is already vacant.\n");
        }
        else{
            printf("Room bill is Rs.%d.\n", h->rooms[room_index].bill);
            printf("Do you want to check out (Y/N)? ");
            char confirm;
            scanf(" %c", &confirm);
            if(confirm == 'Y' || confirm == 'y'){
                printf("Enter guest name: ");
                char name[50];
                scanf("%s", name);
                guest_index = get_guest_index(h, room_index, name);
                if(guest_index != -1){
                    printf("Guest %s checked out of room number %d.\n", name, room_no);
                    h->rooms[room_index].occupancy--;
                    strcpy(h->rooms[room_index].guests[guest_index].name, "");
                    h->rooms[room_index].bill = 0;
                }
                else{
                    printf("Guest not found.\n");
                }
            }
            else{
                printf("Aborting operation.\n");
            }
        }
    }
    else{
        printf("Room number not found.\n");
    }
}

void display_guests(struct hotel *h){
    int room_no, index;
    printf("Enter room number: ");
    scanf("%d", &room_no);
    index = get_room_index(h, room_no);
    if(index != -1){
        printf("-----------------------\n");
        printf("Name\tAge\tGender\tCountry\n");
        printf("-----------------------\n");
        for(int i=0;i<h->rooms[index].occupancy;i++){
            printf("%s\t%d\t%s\t%s\n", h->rooms[index].guests[i].name, h->rooms[index].guests[i].age, h->rooms[index].guests[i].gender, h->rooms[index].guests[i].country);
        }
        printf("-----------------------\n");
    }
    else{
        printf("Room number not found.\n");
    }
}

int get_room_index(struct hotel *h, int room_no){
    for(int i=0;i<MAX_ROOMS;i++){
        if(h->rooms[i].room_no == room_no){
            return i;
        }
    }
    return -1;
}

int get_guest_index(struct hotel *h, int room_index, char *name){
    for(int i=0;i<h->rooms[room_index].occupancy;i++){
        if(strcmp(h->rooms[room_index].guests[i].name, name) == 0){
            return i;
        }
    }
    return -1;
}