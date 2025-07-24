//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

struct appointment {
    int day;
    int month;
    int year;
    char name[100];
    char time[6];
};

void displayMenu() {
    printf("Appointment Scheduler:\n");
    printf("======================\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void scheduleAppointment(struct appointment *appointments[], int *numAppointments) {
    printf("\nEnter appointment details:\n");
    printf("Name: ");
    scanf(" %[^\n]s", appointments[*numAppointments]->name);
    printf("Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &appointments[*numAppointments]->day, &appointments[*numAppointments]->month, &appointments[*numAppointments]->year);
    printf("Time (HH:MM): ");
    scanf("%s", appointments[*numAppointments]->time);
    (*numAppointments)++;
    printf("\nAppointment scheduled successfully!\n\n");
}

void viewAppointments(struct appointment *appointments[], int numAppointments) {
    printf("\nUpcoming Appointments:\n");
    printf("======================\n");
    if(numAppointments == 0) {
        printf("No appointments scheduled.\n\n");
        return;
    }
    for(int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i]->name);
        printf("Date: %d/%d/%d\n", appointments[i]->day, appointments[i]->month, appointments[i]->year);
        printf("Time: %s\n\n", appointments[i]->time);
    }
}

int main() {
    int choice, numAppointments = 0;
    struct appointment *appointments[100];
    for(int i = 0; i < 100; i++) {
        appointments[i] = (struct appointment*) malloc(sizeof(struct appointment));
    }
    do {
        displayMenu();
        choice = getChoice();
        switch(choice) {
            case 1:
                scheduleAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 3);
    return 0;
}