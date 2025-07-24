//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

// Struct to hold appointment information
typedef struct {
    char name[100];
    char date[20];
    char time[20];
} Appointment;

// Array of Appointments to hold all scheduled appointments
Appointment appointments[MAX_APPOINTMENTS];

// Function to display all currently scheduled appointments
void viewAppointments() {
    printf("Currently scheduled appointments:\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strlen(appointments[i].name) > 0) {
            printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
        }
    }
}

// Function to schedule a new appointment
void scheduleAppointment() {
    printf("Enter name of person for appointment: ");
    char name[100];
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");
    
    printf("Enter date of appointment (format: MM/DD/YYYY): ");
    char date[20];
    fgets(date, sizeof(date), stdin);
    strtok(date, "\n");
    
    printf("Enter time of appointment (format: HH:MM AM/PM): ");
    char time[20];
    fgets(time, sizeof(time), stdin);
    strtok(time, "\n");
    
    // Find an empty slot in the appointments array to add new appointment
    int index;
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strlen(appointments[i].name) == 0) {
            index = i;
            break;
        }
        else if (i == MAX_APPOINTMENTS - 1) {
            // If appointments array is full, display error message and return to main menu
            printf("Sorry, appointment scheduler is full. Please try again later.\n");
            return;
        }
    }
    
    // Add appointment to appointments array at empty slot
    strncpy(appointments[index].name, name, 100);
    strncpy(appointments[index].date, date, 20);
    strncpy(appointments[index].time, time, 20);
    
    printf("Appointment added!\n");
}

// Main function to display menu and handle user input
int main() {
    char choice;
    do {
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. View Appointments\n");
        printf("2. Schedule Appointment\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        
        fgets(&choice, sizeof(choice), stdin);
        
        switch (choice) {
            case '1':
                viewAppointments();
                break;
                
            case '2':
                scheduleAppointment();
                break;
                
            case '3':
                printf("Thank you for using the appointment scheduler.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');
    
    return 0;
}