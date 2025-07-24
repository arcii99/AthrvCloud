//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store appointment information
typedef struct {
    char date[11];
    char time[6];
    char name[50];
    char reason[100];
} Appointment;

// Function to print menu options
void printMenu() {
    printf("\n***********************\n");
    printf("1. Schedule an appointment\n");
    printf("2. Edit an appointment\n");
    printf("3. Cancel an appointment\n");
    printf("4. View all appointments\n");
    printf("5. Exit\n");
    printf("Enter an option: ");
}

// Function to schedule an appointment
void scheduleAppointment(Appointment *appointments, int *count) {
    char date[11], time[6], name[50], reason[100];
    
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter time (HH:MM): ");
    scanf("%s", time);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter reason: ");
    scanf("%s", reason);
    
    // Copy input values into appointment structure
    strcpy(appointments[*count].date, date);
    strcpy(appointments[*count].time, time);
    strcpy(appointments[*count].name, name);
    strcpy(appointments[*count].reason, reason);
    
    printf("\nAppointment scheduled successfully!\n\n");
    (*count)++;
}

// Function to edit an appointment
void editAppointment(Appointment *appointments, int count) {
    char date[11], time[6];
    printf("Enter date of appointment to edit (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter time of appointment to edit (HH:MM): ");
    scanf("%s", time);
    
    for(int i = 0; i < count; i++) {
        if(strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            char name[50], reason[100];
            printf("Enter new name (or enter 'skip' to keep existing name): ");
            scanf("%s", name);
            if(strcmp(name, "skip") != 0) {
                strcpy(appointments[i].name, name);
            }
            printf("Enter new reason (or enter 'skip' to keep existing reason): ");
            scanf("%s", reason);
            if(strcmp(reason, "skip") != 0) {
                strcpy(appointments[i].reason, reason);
            }
            printf("\nAppointment edited successfully!\n\n");
            return;
        }
    }
    
    printf("\nAppointment not found!\n\n");
}

// Function to cancel an appointment
void cancelAppointment(Appointment *appointments, int *count) {
    char date[11], time[6];
    printf("Enter date of appointment to cancel (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter time of appointment to cancel (HH:MM): ");
    scanf("%s", time);
    
    for(int i = 0; i < *count; i++) {
        if(strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            for(int j = i; j < *count - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            (*count)--;
            printf("\nAppointment canceled successfully!\n\n");
            return;
        }
    }
    
    printf("\nAppointment not found!\n\n");
}

// Function to view all appointments
void viewAppointments(Appointment *appointments, int count) {
    if(count == 0) {
        printf("\nNo appointments scheduled!\n\n");
        return;
    }
    
    printf("\nAll Appointments:\n\n");
    printf("Date\t\t| Time\t| Name\t\t| Reason\n");
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t| %s\t| %s\t| %s\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].reason);
    }
    printf("\n");
}

int main() {
    Appointment appointments[50]; // Maximum of 50 appointments
    int count = 0; // Current number of scheduled appointments
    
    int option;
    do {
        printMenu();
        scanf("%d", &option);
        
        switch(option) {
            case 1: scheduleAppointment(appointments, &count);
                    break;
            case 2: editAppointment(appointments, count);
                    break;
            case 3: cancelAppointment(appointments, &count);
                    break;
            case 4: viewAppointments(appointments, count);
                    break;
            case 5: printf("Exiting program...\n");
                    exit(0);
            default: printf("Invalid option! Please try again.\n");
        }
        
    } while(option != 5);
    
    return 0;
}