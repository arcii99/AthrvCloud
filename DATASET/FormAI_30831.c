//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Struct for holding appointment data */
typedef struct appointment {
    char name[30];
    char date[20];
    char time[10];
} Appointment;

/* Function prototypes */
void addAppointment(Appointment appointments[], int *pNumAppointments);
void viewAppointments(Appointment appointments[], int numAppointments);
void deleteAppointment(Appointment appointments[], int *pNumAppointments);

int main() {
    Appointment appointments[50]; // Can store up to 50 appointments
    int numAppointments = 0; // Start with no appointments
    
    printf("Welcome to the Appointment Scheduler!\n\n");
    
    while (1) {
        // Display menu options
        printf("Menu\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        
        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

void addAppointment(Appointment appointments[], int *pNumAppointments) {
    if (*pNumAppointments == 50) {
        printf("\nMax appointments reached!\n");
        return;
    }
    
    printf("\nEnter name: ");
    scanf("%29s", appointments[*pNumAppointments].name);
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%19s", appointments[*pNumAppointments].date);
    printf("Enter time (hh:mm): ");
    scanf("%9s", appointments[*pNumAppointments].time);
    
    (*pNumAppointments)++;
    
    printf("\nAppointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
        return;
    }
    
    printf("\nAppointments:\n");
    printf("Name\tDate\t\tTime\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void deleteAppointment(Appointment appointments[], int *pNumAppointments) {
    if (*pNumAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
        return;
    }
    
    printf("\nEnter name of appointment to delete: ");
    char name[30];
    scanf("%29s", name);
    
    int appointmentIndex = -1;
    for (int i = 0; i < *pNumAppointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            appointmentIndex = i;
            break;
        }
    }
    
    if (appointmentIndex == -1) {
        printf("\nAppointment not found.\n");
        return;
    }
    
    // Shift all appointments after the deleted one back by 1 to fill the gap
    for (int i = appointmentIndex; i < *pNumAppointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    (*pNumAppointments)--;
    
    printf("\nAppointment deleted successfully!\n");
}