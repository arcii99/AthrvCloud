//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include<stdio.h>

struct appointment {
    char name[50]; // name of the person
    char date[15]; // date of the appointment
    char time[6]; // time of the appointment
    int duration; // duration of the appointment in minutes
};

int main() {
    int num_appointments, i;
    printf("How many appointments do you want to schedule? ");
    scanf("%d", &num_appointments);

    struct appointment appointments[num_appointments];

    // input data for each appointment
    for(i=0; i<num_appointments; i++) {
        printf("Enter name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter date for appointment %d in format dd/mm/yyyy: ", i+1);
        scanf("%s", appointments[i].date);

        printf("Enter time for appointment %d in 24-hour HH:MM format: ", i+1);
        scanf("%s", appointments[i].time);

        printf("Enter duration for appointment %d in minutes: ", i+1);
        scanf("%d", &appointments[i].duration);
    }

    // print the appointments in a table
    printf("Scheduled Appointments\n");
    printf("------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-7s | %-10s |\n", "Name", "Date", "Time", "Duration");
    printf("------------------------------------------------------------\n");
    for(i=0; i<num_appointments; i++) {
        printf("| %-20s | %-10s | %-7s | %-10d |\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
        printf("------------------------------------------------------------\n");
    }

    return 0;
}