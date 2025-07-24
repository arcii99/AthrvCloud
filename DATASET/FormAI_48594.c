//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

void main()
{
  int choice;
  while(1)
  {
    printf("\n\n*****C HOTEL MANAGEMENT SYSTEM*****\n");
    printf("1. Book a Room\n");
    printf("2. Check-in\n");
    printf("3. Check-out\n");
    printf("4. View Room Details\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
  
    switch(choice)
    {
      case 1:
        printf("\n\n*****BOOK A ROOM*****\n");
        //code to book a room
        break;
    
      case 2:
        printf("\n\n*****CHECK-IN*****\n");
        //code to check-in a guest
        break;
    
      case 3:
        printf("\n\n*****CHECK-OUT*****\n");
        //code to check-out a guest and generate bill
        break;
    
      case 4:
        printf("\n\n*****VIEW ROOM DETAILS*****\n");
        //code to view room details
        break;
    
      case 5: 
        exit(0);
    
      default: 
        printf("\nInvalid Input!");
    }
  }
}