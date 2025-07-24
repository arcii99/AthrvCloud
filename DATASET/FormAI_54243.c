//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 1000

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char* name;
    Date* date;
} Appointment;

Appointment* appts[MAX_APPTS];

int numAppts = 0;

void addAppointment(char* name, int day, int month, int year) {
    if (numAppts < MAX_APPTS) {
        Appointment* newAppt = (Appointment*) malloc(sizeof(Appointment));
        newAppt->name = (char*) malloc(sizeof(char) * strlen(name) + 1);
        strcpy(newAppt->name, name);
        newAppt->date = (Date*) malloc(sizeof(Date));
        newAppt->date->day = day;
        newAppt->date->month = month;
        newAppt->date->year = year;
        appts[numAppts++] = newAppt;
    }
    else {
        printf("No more appointments can be added!\n");
    }
}

void printAppointments() {
    for (int i = 0; i < numAppts; i++) {
        printf("%s - %d/%d/%d\n", appts[i]->name, appts[i]->date->day, appts[i]->date->month, appts[i]->date->year);
    }
}

int main() {
    addAppointment("Meeting with client", 25, 9, 2021);
    addAppointment("Doctor's appointment", 27, 9, 2021);
    printAppointments();
    return 0;
}