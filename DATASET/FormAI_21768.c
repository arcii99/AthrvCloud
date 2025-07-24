//FormAI DATASET v1.0 Category: Hotel Management System ; Style: excited
#include<stdio.h>
#include<stdlib.h>

struct customer{
    char name[20];
    int room_no;
    float bill;
};

int main(){
    struct customer data[10];
    int choice,i,room;
    float amount;
    char ch = 'y';
    for(i=0;i<10;i++){
        strcpy(data[i].name, "Empty");
        data[i].room_no = i+1;
        data[i].bill = 0.0;
    }
    while(ch=='y'){
        system("cls");
        printf("\n Hotel Customer Management System \n");
        printf("\n 1. Book a Room");
        printf("\n 2. Check Out");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: // Book a Room
                printf("\n Enter the Room number: ");
                scanf("%d",&room);
                if(strcmp(data[room-1].name,"Empty")==0){
                    printf("\n Enter the Customer Name: ");
                    scanf("%s",data[room-1].name);
                    data[room-1].room_no = room;
                    printf("\n Room Booked Successfully!");
                }
                else{
                    printf("\n Room is already booked by %s",data[room-1].name);
                }
                break;
            case 2: // Check Out
                printf("\n Enter the Room number: ");
                scanf("%d",&room);
                if(strcmp(data[room-1].name,"Empty")!=0){
                    printf("\n Customer Name: %s",data[room-1].name);
                    printf("\n Room No.: %d",data[room-1].room_no);
                    printf("\n Check-out Amount (in Rs.): ");
                    scanf("%f",&amount);
                    data[room-1].bill += amount;
                    printf("\n Total Bill Amount: Rs. %.2f",data[room-1].bill);
                    strcpy(data[room-1].name,"Empty");                 
                }
                else{
                    printf("\n Room is already vacant.");
                }
                break;
            default: // Wrong Choice
                printf("\n Invalid Choice!");
        }
        printf("\n Do you want to continue (y/n)? ");
        fflush(stdin);
        scanf("%c",&ch);
    }
    return 0;
}