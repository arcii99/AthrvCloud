//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 10

// Define a structure to hold appointment details
struct Appointment {
    char name[50];
    int day;
    int hour;
};

// Define an array to hold scheduled appointments
struct Appointment appointments[MAX_APPOINTMENTS];

// Define a function to print all scheduled appointments
void printAppointments() {
    printf("\nScheduled Appointments:\n");
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        if(strcmp(appointments[i].name, "") != 0) {
            printf("%d: %s on day %d at %d:00\n", i+1, appointments[i].name, appointments[i].day, appointments[i].hour);
        }
    }
}

// Define a function to check if a given day and hour is already scheduled 
bool isAlreadyScheduled(int day, int hour) {
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        if(strcmp(appointments[i].name, "") != 0 && appointments[i].day == day && appointments[i].hour == hour) {
            return true;
        }
    }
    return false;
}

int main() {
    // Initialize all appointments as empty
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        strcpy(appointments[i].name, "");
        appointments[i].day = 0;
        appointments[i].hour = 0;
    }
    
    // Display menu and get user input
    int choice = 0;
    while(choice != 4) {
        printf("\nChoose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. View all scheduled appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Schedule a new appointment
                printf("\nEnter name: ");
                char name[50];
                scanf("%s", name);
                
                printf("Enter day (1-7): ");
                int day;
                scanf("%d", &day);
                
                printf("Enter hour (9-17): ");
                int hour;
                scanf("%d", &hour);
                
                if(day < 1 || day > 7 || hour < 9 || hour > 17) {
                    printf("Invalid day or hour!");
                } else if(isAlreadyScheduled(day, hour)) {
                    printf("Appointment already scheduled! Please choose a different time.");
                } else {
                    // Find an empty slot and schedule the appointment
                    int i;
                    for(i=0; i<MAX_APPOINTMENTS; i++) {
                        if(strcmp(appointments[i].name, "") == 0) {
                            strcpy(appointments[i].name, name);
                            appointments[i].day = day;
                            appointments[i].hour = hour;
                            printf("Appointment scheduled successfully on day %d at %d:00!", day, hour);
                            break;
                        }
                    }
                    if(i == MAX_APPOINTMENTS) {
                        printf("Maximum number of appointments reached!");
                    }
                }
                break;
                
            case 2:
                // Cancel an existing appointment
                printf("\nEnter appointment number to cancel: ");
                int num;
                scanf("%d", &num);
                
                if(num < 1 || num > MAX_APPOINTMENTS) {
                    printf("Invalid appointment number!");
                } else if(strcmp(appointments[num-1].name, "") == 0) {
                    printf("Appointment %d is already empty!", num);
                } else {
                    // Cancel the appointment
                    strcpy(appointments[num-1].name, "");
                    appointments[num-1].day = 0;
                    appointments[num-1].hour = 0;
                    printf("Appointment %d cancelled successfully!", num);
                }
                break;
                
            case 3:
                // View all scheduled appointments
                printAppointments();
                break;
                
            case 4:
                // Exit the program
                printf("\nExiting the appointment scheduler...");
                break;
                
            default:
                printf("\nInvalid choice! Please choose again.");
                break;
        }
    }
    
    return 0;
}