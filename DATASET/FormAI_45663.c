//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  char day[10];
  int time, age;
  
  printf("Hello! I am the appointment scheduler chatbot. What day would you like to schedule your appointment? (Please input the day in three-letter format, i.e. Mon)\n");
  scanf("%s", day);

  printf("Great! What time works best for you? (Please input the time in hours, i.e. 13 for 1:00 PM)\n");
  scanf("%d", &time);

  printf("And finally, how old are you?\n");
  scanf("%d", &age);

  if ((day[0] == 'M' || day[0] == 'W' || day[0] == 'F') && time >= 9 && time <= 16 && age >= 18) {
    printf("Your appointment has been scheduled for %s at %d:00. Please arrive 15 minutes early and bring a valid ID. Thank you!\n", day, time);
  } 
  else if ((day[0] == 'T' || day[0] == 'Th') && time >= 11 && time <= 18 && age >= 21) {
    printf("Your appointment has been scheduled for %s at %d:00. Please arrive 15 minutes early and bring a valid ID. Thank you!\n", day, time);
  } 
  else {
    printf("Sorry, we cannot schedule an appointment for you at this time. Please make sure you are eligible and that your preferred day and time are within our hours of operation. Thank you!\n");
  }

  return 0;
}