//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// surreal appointment scheduler
int main() {
  srand(time(NULL)); // seed the random function

  printf("Welcome to the surreal appointment scheduler!\n");

  char name[50]; // the name of the appointment holder
  printf("Please enter your name: ");
  scanf("%s", name);

  int day = rand() % 31 + 1; // random day from 1st to 31st
  int month = rand() % 12 + 1; // random month from January to December

  printf("Hello %s, your appointment is scheduled for %d/%d.\n", name, day, month);

  int hour = rand() % 24; // random hour from 0 to 23
  int minute = rand() % 60; // random minute from 0 to 59

  printf("Your appointment is at %02d:%02d.\n", hour, minute);

  int option = rand() % 3; // random number from 0 to 2 for scheduling option

  if (option == 0) {
    printf("Your appointment has been scheduled with our resident clown.\n");
  } else if (option == 1) {
    printf("Your appointment has been scheduled with our talking parrot.\n");
  } else {
    printf("Your appointment has been scheduled with our pet unicorn.\n");
  }

  printf("Thank you for scheduling your surreal appointment with us!\n");

  return 0;
}