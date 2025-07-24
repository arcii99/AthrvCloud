//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 100

// struct to store appointment information
struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
};

// array to store appointments
struct Appointment appointments[MAX_APPOINTMENTS];

// function to display menu
void displayMenu() {
    printf("\nAppointment Scheduler");
    printf("\n---------------------");
    printf("\n1. Add Appointment");
    printf("\n2. View Appointments");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
}

// function to add appointment
void addAppointment() {
    int i;
    // find first available slot in appointments array
    for(i = 0; i < MAX_APPOINTMENTS; i++) {
        if(strcmp(appointments[i].name, "") == 0) {
            // read appointment information
            printf("\nEnter appointment name: ");
            scanf("%s", appointments[i].name);
            printf("Enter appointment date (DD MM YYYY): ");
            scanf("%d %d %d", &appointments[i].day, &appointments[i].month, &appointments[i].year);
            printf("Enter appointment time (HH:MM AM/PM): ");
            scanf("%s", appointments[i].time);
            printf("\nAppointment added successfully.\n");
            return;
        }
    }
    printf("\nSorry, appointment list is full!\n");
}

// function to view appointments
void viewAppointments() {
    int i, j;
    struct Appointment temp;
    // sort appointments by date and time
    for(i = 0; i < MAX_APPOINTMENTS-1; i++) {
        for(j = i+1; j < MAX_APPOINTMENTS; j++) {
            if(strcmp(appointments[i].name, "") != 0 && strcmp(appointments[j].name, "") != 0) {
                if(appointments[j].year < appointments[i].year ||
                  (appointments[j].year == appointments[i].year && appointments[j].month < appointments[i].month) ||
                  (appointments[j].year == appointments[i].year && appointments[j].month == appointments[i].month && appointments[j].day < appointments[i].day) ||
                  (appointments[j].year == appointments[i].year && appointments[j].month == appointments[i].month && appointments[j].day == appointments[i].day && strcmp(appointments[j].time, appointments[i].time) < 0)) {
                    temp = appointments[i];
                    appointments[i] = appointments[j];
                    appointments[j] = temp;
                }
            }
        }
    }
    // display appointments
    printf("\nAppointment List\n");
    printf("----------------\n");
    printf("%-20s %-12s %-10s\n", "Name", "Date", "Time");
    for(i = 0; i < MAX_APPOINTMENTS; i++) {
        if(strcmp(appointments[i].name, "") != 0) {
            printf("%-20s %02d/%02d/%04d %s\n", 
            appointments[i].name, 
            appointments[i].day, 
            appointments[i].month, 
            appointments[i].year, 
            appointments[i].time);
        }
    }
}

int main() {
    int choice;

    // initialize appointments array with blank appointments
    int i;
    for(i = 0; i < MAX_APPOINTMENTS; i++) {
        strcpy(appointments[i].name, "");
        appointments[i].day = 0;
        appointments[i].month = 0;
        appointments[i].year = 0;
        strcpy(appointments[i].time, "");
    }

    // display menu and process user choice
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}