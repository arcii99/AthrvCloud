//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct appointment {
   char name[50];
   int day;
   int month;
   int year;
   char time[10];
   bool is_booked;
};

void print_appointment(struct appointment apt) {
   printf("%s\nDate: %d/%d/%d\nTime: %s\n", apt.name, apt.day, apt.month, apt.year, apt.time);
   if (apt.is_booked) {
      printf("Booked\n");
   } else {
      printf("Available\n");
   }
}

int find_empty_appointment(struct appointment appts[], int num_appts) {
   for (int i = 0; i < num_appts; i++) {
      if (!appts[i].is_booked) {
         return i;
      }
   }
   return -1;
}

int main() {
   // Initialize appointments
   struct appointment appts[10];
   for (int i = 0; i < 10; i++) {
      appts[i].is_booked = false;
   }

   // Add some appointments
   int num_appts = 0;
   appts[num_appts].day = 15;
   appts[num_appts].month = 6;
   appts[num_appts].year = 2022;
   strcpy(appts[num_appts].name, "Dentist Appointment");
   strcpy(appts[num_appts].time, "10:00am");
   appts[num_appts].is_booked = true;
   num_appts++;

   appts[num_appts].day = 16;
   appts[num_appts].month = 6;
   appts[num_appts].year = 2022;
   strcpy(appts[num_appts].name, "Doctor's Checkup");
   strcpy(appts[num_appts].time, "2:00pm");
   appts[num_appts].is_booked = true;
   num_appts++;

   appts[num_appts].day = 17;
   appts[num_appts].month = 6;
   appts[num_appts].year = 2022;
   strcpy(appts[num_appts].name, "Meeting with Client");
   strcpy(appts[num_appts].time, "11:00am");
   appts[num_appts].is_booked = false;
   num_appts++;

   // Print out all appointments
   for (int i = 0; i < num_appts; i++) {
      print_appointment(appts[i]);
      printf("\n");
   }

   // Add a new appointment
   int empty_slot = find_empty_appointment(appts, 10);
   if (empty_slot != -1) {
      appts[empty_slot].day = 18;
      appts[empty_slot].month = 6;
      appts[empty_slot].year = 2022;
      strcpy(appts[empty_slot].name, "Team Lunch");
      strcpy(appts[empty_slot].time, "12:00pm");
      appts[empty_slot].is_booked = true;
      num_appts++;

      printf("Added %s appointment on %d/%d/%d at %s\n\n", appts[empty_slot].name, appts[empty_slot].day, appts[empty_slot].month, appts[empty_slot].year, appts[empty_slot].time);
   } else {
      printf("No available appointment slots.\n\n");
   }

   // Print out all appointments with updated availability
   for (int i = 0; i < num_appts; i++) {
      print_appointment(appts[i]);
      printf("\n");
   }

   return 0;
}