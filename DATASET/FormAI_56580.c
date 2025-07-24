//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include<stdio.h>
#include<string.h>

struct guest{
    char name[100];
    char address[100];
    char phone[20];
    char email[100];
};

struct room{
    int roomno;
    char type[50];
    int price;
    int isbooked;
    struct guest guestinfo;
};

struct hotel{
    struct room rooms[100];
    int totalrooms;
};

void addroom(struct hotel *h, int roomno, char type[], int price){
    h->rooms[h->totalrooms].roomno = roomno;
    strcpy(h->rooms[h->totalrooms].type, type);
    h->rooms[h->totalrooms].price = price;
    h->rooms[h->totalrooms].isbooked = 0;
    h->totalrooms++;
}

void displayrooms(struct hotel h){
    int i;
    printf("Room No. \t Type \t Price \t Status\n");
    for(i=0;i<h.totalrooms;i++){
        printf("%d \t\t %s \t %d \t ", h.rooms[i].roomno, h.rooms[i].type, h.rooms[i].price);
        if(h.rooms[i].isbooked==0){
            printf("Available\n");
        }
        else{
            printf("Booked\n");
        }
    }
}

void addguest(struct hotel *h, char name[], char address[], char phone[], char email[]){
    int i;
    for(i=0;i<h->totalrooms;i++){
        if(h->rooms[i].isbooked==0){
            strcpy(h->rooms[i].guestinfo.name, name);
            strcpy(h->rooms[i].guestinfo.address, address);
            strcpy(h->rooms[i].guestinfo.phone, phone);
            strcpy(h->rooms[i].guestinfo.email, email);
            h->rooms[i].isbooked = 1;
            break;
        }
    }
    if(i==h->totalrooms){
        printf("All rooms are booked, cannot add guest\n");
    }
    else{
        printf("Guest added successfully\n");
    }
}

void removeguest(struct hotel *h, int roomno){
    int i;
    for(i=0;i<h->totalrooms;i++){
        if(h->rooms[i].roomno==roomno){
            if(h->rooms[i].isbooked==1){
                h->rooms[i].isbooked = 0;
                strcpy(h->rooms[i].guestinfo.name, "");
                strcpy(h->rooms[i].guestinfo.address, "");
                strcpy(h->rooms[i].guestinfo.phone, "");
                strcpy(h->rooms[i].guestinfo.email, "");
                printf("Guest removed successfully\n");
            }
            else{
                printf("Room is not booked, no guest to remove\n");
            }
            break;
        }
    }
    if(i==h->totalrooms){
        printf("Invalid room no.\n");
    }
}

int main(){
    struct hotel h;
    h.totalrooms = 0;
    int choice, roomno, price;
    char type[50], name[100], address[100], phone[20], email[100];
    printf("Welcome to the C Hotel Management System!\n");
    do{
        printf("\nMenu\n");
        printf("1. Add Room\n");
        printf("2. Display Rooms\n");
        printf("3. Add Guest\n");
        printf("4. Remove Guest\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Room No.: ");
                scanf("%d", &roomno);
                printf("Enter Room Type: ");
                scanf("%s", type);
                printf("Enter Room Price: ");
                scanf("%d", &price);
                addroom(&h, roomno, type, price);
                break;
            case 2:
                displayrooms(h);
                break;
            case 3:
                printf("Enter Guest Name: ");
                scanf("%s", name);
                printf("Enter Guest Address: ");
                scanf("%s", address);
                printf("Enter Guest Phone: ");
                scanf("%s", phone);
                printf("Enter Guest Email: ");
                scanf("%s", email);
                addguest(&h, name, address, phone, email);
                break;
            case 4:
                printf("Enter Room No.: ");
                scanf("%d", &roomno);
                removeguest(&h, roomno);
                break;
            case 5:
                printf("Thanks for using C Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice, please enter again\n");
        }
    }while(choice!=5);
    return 0;
}