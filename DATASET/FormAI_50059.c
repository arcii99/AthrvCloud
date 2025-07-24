//FormAI DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
   char name[50];
   int room_no;
   int num_of_days;
   float rate;
   float total_amt;
   char status[10];
} guests[100];

int main() {
   int choice, count = 0;
   for (;;) {
      printf("\nC Hotel Management System");
      printf("\n1. Check In");
      printf("\n2. Check Out");
      printf("\n3. View Guests");
      printf("\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1: // Check In
            printf("\nEnter guest name: ");
            scanf("%s", &guests[count].name);
            printf("Enter room number: ");
            scanf("%d", &guests[count].room_no);
            printf("Enter number of days of stay: ");
            scanf("%d", &guests[count].num_of_days);
            printf("Enter room rate: ");
            scanf("%f", &guests[count].rate);
            guests[count].total_amt = guests[count].num_of_days * 
            guests[count].rate;
            strcpy(guests[count].status, "Checked In");
            printf("\nCheck In Successful!");
            count++;
            break;
         case 2: // Check Out
            char name[50];
            int room_no, i;
            printf("\nEnter guest name: ");
            scanf("%s", &name);
            printf("Enter room number: ");
            scanf("%d", &room_no);
            for (i = 0; i < count; i++) {
               if (strcmp(guests[i].name, name) == 0 && 
               guests[i].room_no == room_no) {
                  printf("\nGuest found!");
                  printf("\nGuest Name: %s", guests[i].name);
                  printf("\nRoom Number: %d", guests[i].room_no);
                  printf("\nNumber of Days Stayed: %d", guests[i].num_of_days);
                  printf("\nRoom Rate: %0.2f", guests[i].rate);
                  printf("\nTotal Amount Due: %0.2f", guests[i].total_amt);
                  printf("\nStatus: %s", guests[i].status);
                  strcpy(guests[i].status, "Checked Out");
                  printf("\nCheck Out Successful!");
                  break;
               }
            }
            if (i == count) {
               printf("\nGuest not found!");
            }
            break;
         case 3: // View Guests
            printf("\nGuest Name\tRoom Number\tNumber of Days\tRoom Rate\tTotal Amount Due\tStatus");
            for (i = 0; i < count; i++) {
               printf("\n%s\t\t%d\t\t%d\t\t%0.2f\t\t%0.2f\t\t%s", guests[i].name, guests[i].room_no, guests[i].num_of_days, guests[i].rate, guests[i].total_amt, guests[i].status);
            }
            break;
         case 4: // Exit
            printf("\nThank you for using C Hotel Management System!");
            exit(0);
         default:
            printf("\nInvalid choice! Please try again.");
      }
   }
   return 0;
}