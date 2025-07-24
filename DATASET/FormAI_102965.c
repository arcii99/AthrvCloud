//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char day[3];
  char month[3];
  char year[5];
} Date;

typedef struct {
  char hour[3];
  char minute[3];
} Time;

typedef struct {
  char name[50];
  char phone[15];
} Patient;

typedef struct {
  Date date;
  Time time;
  Patient patient;
} Appointment;

bool is_valid_date(Date date) {
  int day = atoi(date.day);
  int month = atoi(date.month);
  int year = atoi(date.year);
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
    return false;
  } else {
    return true;
  }
}

bool is_valid_time(Time time) {
  int hour = atoi(time.hour);
  int minute = atoi(time.minute);
  if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
    return false;
  } else {
    return true;
  }
}

void print_date(Date date) {
  printf("%s/%s/%s\n", date.day, date.month, date.year);
}

void print_time(Time time) {
  printf("%s:%s\n", time.hour, time.minute);
}

void print_appointment(Appointment appt) {
  printf("Appointment for:\n");
  printf("Name: %s\n", appt.patient.name);
  printf("Phone: %s\n", appt.patient.phone);
  printf("Date: ");
  print_date(appt.date);
  printf("Time: ");
  print_time(appt.time);
}

int main() {
  Appointment appointments[5];
  int num_appointments = 0;
  char answer[10];
  do {
    Appointment new_appt;
    printf("Enter name: ");
    fgets(new_appt.patient.name, sizeof(new_appt.patient.name), stdin);
    new_appt.patient.name[strcspn(new_appt.patient.name, "\n")] = 0;
    printf("Enter phone: ");
    fgets(new_appt.patient.phone, sizeof(new_appt.patient.phone), stdin);
    new_appt.patient.phone[strcspn(new_appt.patient.phone, "\n")] = 0;
    printf("Enter date (DD/MM/YYYY): ");
    fgets(new_appt.date.day, sizeof(new_appt.date.day), stdin);
    new_appt.date.day[strcspn(new_appt.date.day, "\n")] = 0;
    fgets(new_appt.date.month, sizeof(new_appt.date.month), stdin);
    new_appt.date.month[strcspn(new_appt.date.month, "\n")] = 0;
    fgets(new_appt.date.year, sizeof(new_appt.date.year), stdin);
    new_appt.date.year[strcspn(new_appt.date.year, "\n")] = 0;
    while (!is_valid_date(new_appt.date)) {
      printf("Invalid date. Enter date again (DD/MM/YYYY): ");
      fgets(new_appt.date.day, sizeof(new_appt.date.day), stdin);
      new_appt.date.day[strcspn(new_appt.date.day, "\n")] = 0;
      fgets(new_appt.date.month, sizeof(new_appt.date.month), stdin);
      new_appt.date.month[strcspn(new_appt.date.month, "\n")] = 0;
      fgets(new_appt.date.year, sizeof(new_appt.date.year), stdin);
      new_appt.date.year[strcspn(new_appt.date.year, "\n")] = 0;
    }
    printf("Enter time (24-hour format, HH:MM): ");
    fgets(new_appt.time.hour, sizeof(new_appt.time.hour), stdin);
    new_appt.time.hour[strcspn(new_appt.time.hour, "\n")] = 0;
    fgets(new_appt.time.minute, sizeof(new_appt.time.minute), stdin);
    new_appt.time.minute[strcspn(new_appt.time.minute, "\n")] = 0;
    while (!is_valid_time(new_appt.time)) {
      printf("Invalid time. Enter time again (24-hour format, HH:MM): ");
      fgets(new_appt.time.hour, sizeof(new_appt.time.hour), stdin);
      new_appt.time.hour[strcspn(new_appt.time.hour, "\n")] = 0;
      fgets(new_appt.time.minute, sizeof(new_appt.time.minute), stdin);
      new_appt.time.minute[strcspn(new_appt.time.minute, "\n")] = 0;
    }
    printf("New appointment:\n");
    print_appointment(new_appt);
    printf("Is this correct? (y/n): ");
    fgets(answer, sizeof(answer), stdin);
    if (answer[0] == 'y' || answer[0] == 'Y') {
      appointments[num_appointments++] = new_appt;
      printf("Appointment added.\n");
    } else {
      printf("Appointment cancelled.\n");
    }
    printf("Do you want to add another appointment? (y/n): ");
    fgets(answer, sizeof(answer), stdin);
  } while (answer[0] == 'y' || answer[0] == 'Y');

  printf("All appointments:\n");
  for (int i = 0; i < num_appointments; i++) {
    print_appointment(appointments[i]);
  }

  return 0;
}