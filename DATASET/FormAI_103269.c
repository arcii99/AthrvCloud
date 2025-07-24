//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

// Structure to store Appointment related information
typedef struct {
    char name[20];
    char date[15];
    char time[10];
    char reason[50];
} Appointment;

// Function to display all the appointments on a given date
void print_appointments(Appointment *appointments, char *date) {
    printf("\nAppointments on %s:\n", date);
    bool no_appointments = true;
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        if(strcmp(appointments[i].date, date) == 0) {
            printf("\nName: %s\nTime: %s\nReason: %s\n", appointments[i].name,
                                                         appointments[i].time,
                                                         appointments[i].reason);
            no_appointments = false;
        }
    }
    if(no_appointments) printf("\nNo appointments on %s.\n", date);
}

// Function to add an appointment
void add_appointment(Appointment *appointments, int *count) {
    char name[20], date[15], time[10], reason[50];
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter time (hh:mm): ");
    scanf("%s", time);
    printf("Enter reason: ");
    scanf("%s", reason);
    strcpy(appointments[*count].name, name);
    strcpy(appointments[*count].date, date);
    strcpy(appointments[*count].time, time);
    strcpy(appointments[*count].reason, reason);
    (*count)++;
    printf("\nAppointment added successfully!\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointment_count = 0;
    int choice;
    do {
        printf("\nAPPOINTMENT SCHEDULER MENU:\n");
        printf("1. Add Appointment\n2. Print Appointments by Date\n3. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                if(appointment_count < MAX_APPOINTMENTS) {
                    add_appointment(appointments, &appointment_count);
                }
                else {
                    printf("\nCannot schedule more appointments, maximum limit reached.\n");
                }
                break;
            case 2:
                char date[15];
                printf("\nEnter date to view appointments (dd/mm/yyyy): ");
                scanf("%s", date);
                print_appointments(appointments, date);
                break;
            case 3: 
                printf("\nExiting Appointment Scheduler. Have a nice day!\n");
                exit(0);
            default: 
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 3);
    return 0;
}