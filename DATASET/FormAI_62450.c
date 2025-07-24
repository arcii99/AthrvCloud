//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    char location[50];
};

int main() {
    int numAppointments;
    printf("Welcome to the Appointment Scheduler!\n\n");
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &numAppointments);

    struct Appointment appointments[numAppointments];

    for(int i = 0; i < numAppointments; i++) {
        printf("\nAppointment #%d:\n", i+1);
        printf("What is the name of the person you would like to schedule with? ");
        scanf("%s", appointments[i].name);
        printf("What date would you like to schedule the appointment for? ");
        scanf("%s", appointments[i].date);
        printf("What time would you like to schedule the appointment for? ");
        scanf("%s", appointments[i].time);
        printf("Where would you like to schedule the appointment? ");
        scanf("%s", appointments[i].location);
    }

    printf("\n\nHere are your appointments:\n");
    printf("--------------------------\n");

    for(int i = 0; i < numAppointments; i++) {
        printf("Appointment #%d:\n", i+1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Location: %s\n", appointments[i].location);
        printf("--------------------------\n");
    }

    printf("\nThank you for using the Appointment Scheduler! Have a great day!\n");

    return 0;
}