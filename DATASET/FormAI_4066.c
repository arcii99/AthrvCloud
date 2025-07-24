//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

// Struct for representing an appointment
typedef struct {
    char date[11];
    char time[6];
    char patientName[50];
} Appointment;

// Global array to store the appointments
Appointment appointments[MAX_APPOINTMENTS];

// Function to print the menu options
void printMenu() {
    printf("\n----------Menu Options----------\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Edit Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
    printf("--------------------------------\n");
}

// Function to print a single appointment
void printAppointment(Appointment appointment) {
    printf("%s at %s with %s\n", appointment.date, appointment.time, appointment.patientName);
}

// Function to print all the appointments
void viewAppointments() {
    printf("\n--------------Appointments--------------\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strlen(appointments[i].date) != 0) { // Check if the appointment exists
            printAppointment(appointments[i]);
        }
    }
    printf("-----------------------------------------\n");
}

// Function to add a new appointment
void addAppointment() {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strlen(appointments[i].date) == 0) { // Check if the appointment slot is empty
            printf("Enter the date of the appointment (dd/mm/yyyy): ");
            scanf("%s", appointments[i].date);
            printf("Enter the time of the appointment (hh:mm): ");
            scanf("%s", appointments[i].time);
            printf("Enter the patient's name: ");
            scanf("%s", appointments[i].patientName);
            printf("Appointment added successfully!\n");
            return;
        }
    }
    printf("Sorry, all appointment slots are full.\n");
}

// Function to edit an appointment
void editAppointment() {
    char date[11], time[6];
    printf("Enter the date of the appointment to edit (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter the time of the appointment to edit (hh:mm): ");
    scanf("%s", time);

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) { // Check if the appointment matches
            printf("Appointment found: ");
            printAppointment(appointments[i]);
            printf("Enter the new date of the appointment (dd/mm/yyyy): ");
            scanf("%s", appointments[i].date);
            printf("Enter the new time of the appointment (hh:mm): ");
            scanf("%s", appointments[i].time);
            printf("Enter the new patient's name: ");
            scanf("%s", appointments[i].patientName);
            printf("Appointment updated successfully!\n");
            return;
        }
    }
    printf("Sorry, appointment not found.\n");
}

// Function to delete an appointment
void deleteAppointment() {
    char date[11], time[6];
    printf("Enter the date of the appointment to delete (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter the time of the appointment to delete (hh:mm): ");
    scanf("%s", time);

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) { // Check if the appointment matches
            printf("Appointment found: ");
            printAppointment(appointments[i]);
            strcpy(appointments[i].date, "");
            strcpy(appointments[i].time, "");
            strcpy(appointments[i].patientName, "");
            printf("Appointment deleted successfully!\n");
            return;
        }
    }
    printf("Sorry, appointment not found.\n");
}

int main() {
    int option;
    // Initialize all the appointments to have empty values
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        strcpy(appointments[i].date, "");
        strcpy(appointments[i].time, "");
        strcpy(appointments[i].patientName, "");
    }

    while (true) {
        printMenu();
        printf("Enter the desired option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                viewAppointments();
                break;
            case 2:
                addAppointment();
                break;
            case 3:
                editAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                printf("Exiting appointment scheduler...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break; 
        }
    }

    return 0;
}