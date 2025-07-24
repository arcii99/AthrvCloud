//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest {
  char name[50];
  char address[100];
  char phone_num[20];
  int room_num;
  int days_stayed;
  float bill_amount;
};

int main() {
  int num_guests;
  printf("Enter the number of guests: ");
  scanf("%d", &num_guests);

  struct guest guests[num_guests]; //creating an array of guest structures

  //getting the details of each guest from user
  for(int i=0; i<num_guests; i++) {
    printf("Enter details for guest %d:\n", i+1);
    printf("Name: ");
    scanf("%s", guests[i].name); //inputting string using %s format specifier
    printf("Address: ");
    scanf(" %[^\n]s", guests[i].address); //inputting string with spaces using %[] format specifier
    printf("Phone number: ");
    scanf("%s", guests[i].phone_num);
    printf("Room number: ");
    scanf("%d", &guests[i].room_num);
    printf("Number of days stayed: ");
    scanf("%d", &guests[i].days_stayed);

    //calculating bill amount based on room rate of $100 per day
    guests[i].bill_amount = guests[i].days_stayed * 100;
  }

  //displaying the details of all guests
  printf("\n\nDetails of all guests:\n");
  printf("-------------------------------------------------------------------\n");
  printf("Name\t\tAddress\t\t\t\tPhone number\tRoom number\tDays stayed\tBill amount\n");
  printf("-------------------------------------------------------------------\n");
  for(int i=0; i<num_guests; i++) {
    printf("%s\t\t%s\t\t\t%s\t\t%d\t\t%d\t\t%.2f\n", guests[i].name, guests[i].address, guests[i].phone_num, guests[i].room_num, guests[i].days_stayed, guests[i].bill_amount);
  }
  printf("-------------------------------------------------------------------\n");

  return 0;
}