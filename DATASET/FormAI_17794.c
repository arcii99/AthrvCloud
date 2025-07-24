//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPTS 20 // maximum number of appointments the scheduler can handle
#define MAX_NAME_LENGTH 20 // maximum length of a patient's name

typedef struct{
    char name[MAX_NAME_LENGTH];
    int month;
    int day;
    int hour;
    int minute;
}Appointment;

void printMenu(){
    printf("---Appointment Scheduler---\n");
    printf("1. Schedule an appointment\n");
    printf("2. View all appointments\n");
    printf("3. View appointments for a specific date\n");
    printf("4. Cancel an appointment\n");
    printf("5. Exit the scheduler\n");
}

void printAppointment(Appointment apt){
    printf("%s, Date: %d/%d Time: %d:%02d\n", apt.name, apt.month, apt.day, apt.hour, apt.minute);
}

int findNextAvailableSlot(Appointment schedule[MAX_APPTS]){
    int i;
    for(i=0; i<MAX_APPTS; i++){
        if(strcmp(schedule[i].name, "") == 0){ // if name is empty, slot is empty
            return i;
        }
    }
    return -1; // no empty slot found
}

void scheduleAppointment(Appointment schedule[MAX_APPTS]){
    int slot = findNextAvailableSlot(schedule);
    if(slot == -1){ // no empty slot found
        printf("Sorry, the schedule is full. Cannot schedule new appointment.\n");
        return;
    }

    printf("Enter patient name (max %d characters): ", MAX_NAME_LENGTH-1);
    scanf("%s", schedule[slot].name);

    printf("Enter appointment date (MM DD): ");
    scanf("%d %d", &schedule[slot].month, &schedule[slot].day);

    printf("Enter appointment time (HH MM): ");
    scanf("%d %d", &schedule[slot].hour, &schedule[slot].minute);

    printf("Appointment scheduled successfully.\n");
}

void viewAllAppointments(Appointment schedule[MAX_APPTS]){
    int i;
    for(i=0; i<MAX_APPTS; i++){
        if(strcmp(schedule[i].name, "") != 0){ // if name is not empty, appointment is scheduled
            printAppointment(schedule[i]);
        }
    }
}

void viewAppointmentsForDate(Appointment schedule[MAX_APPTS]){
    int month, day;
    printf("Enter date to view appointments (MM DD): ");
    scanf("%d %d", &month, &day);

    int i;
    int count = 0;
    for(i=0; i<MAX_APPTS; i++){
        if(schedule[i].month == month && schedule[i].day == day){
            count++;
            printAppointment(schedule[i]);
        }
    }

    if(count == 0){
        printf("There are no appointments scheduled for %d/%d.\n", month, day);
    }
}

void cancelAppointment(Appointment schedule[MAX_APPTS]){
    int i;
    char name[MAX_NAME_LENGTH];
    printf("Enter patient name to cancel appointment: ");
    scanf("%s", name);

    for(i=0; i<MAX_APPTS; i++){
        if(strcmp(schedule[i].name, name) == 0){
            strcpy(schedule[i].name, ""); // clear name to indicate empty slot
            printf("Appointment cancelled successfully.\n");
            return;
        }
    }

    printf("No appointment found with that patient name.\n");
}

int main(){
    Appointment schedule[MAX_APPTS];
    int choice;

    // initialize schedule with empty slots
    int i;
    for(i=0; i<MAX_APPTS; i++){
        strcpy(schedule[i].name, "");
    }

    while(1){
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                scheduleAppointment(schedule);
                break;
            case 2:
                viewAllAppointments(schedule);
                break;
            case 3:
                viewAppointmentsForDate(schedule);
                break;
            case 4:
                cancelAppointment(schedule);
                break;
            case 5:
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        printf("\n");
    }

    return 0;
}