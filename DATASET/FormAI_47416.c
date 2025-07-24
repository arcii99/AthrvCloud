//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 20

// Struct to represent an appointment
typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int hour;
} Appointment;

// Function to print the menu options
void print_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n\n");
    printf("1. Schedule appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View appointments\n");
    printf("4. Exit\n\n");
}

// Function to check if an appointment already exists on a given day and hour
bool appointment_exists(Appointment appointments[], int day, int hour) {
    for(int i = 0; i < MAX_APPOINTMENTS; i++) {
        if(strcmp(appointments[i].name, "") != 0) {
            if(appointments[i].day == day && appointments[i].hour == hour) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_NAME_LENGTH];
    int option;
    int day;
    int hour;
    int num_appointments = 0;
    
    // Initialize all appointments to empty
    for(int i = 0; i < MAX_APPOINTMENTS; i++) {
        strcpy(appointments[i].name, "");
        appointments[i].day = -1;
        appointments[i].hour = -1;
    }
    
    // Print the menu options and loop until user chooses to exit
    do {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: // Schedule appointment
                printf("Enter name: ");
                scanf("%s", input);
                printf("Enter day: ");
                scanf("%d", &day);
                printf("Enter hour: ");
                scanf("%d", &hour);
                
                // Check if appointment already exists
                if(appointment_exists(appointments, day, hour)) {
                    printf("Appointment already exists at that time.\n");
                } else {
                    // Find the first empty appointment and fill it in
                    for(int i = 0; i < MAX_APPOINTMENTS; i++) {
                        if(strcmp(appointments[i].name, "") == 0) {
                            strcpy(appointments[i].name, input);
                            appointments[i].day = day;
                            appointments[i].hour = hour;
                            num_appointments++;
                            break;
                        }
                    }
                    printf("Appointment scheduled for %s on day %d at hour %d.\n", 
                           input, day, hour);
                }
                break;
            case 2: // Cancel appointment
                printf("Enter name: ");
                scanf("%s", input);
                printf("Enter day: ");
                scanf("%d", &day);
                printf("Enter hour: ");
                scanf("%d", &hour);
                
                // Check if appointment exists and cancel it if it does
                for(int i = 0; i < MAX_APPOINTMENTS; i++) {
                    if(strcmp(appointments[i].name, input) == 0 && 
                       appointments[i].day == day && appointments[i].hour == hour) {
                        strcpy(appointments[i].name, "");
                        appointments[i].day = -1;
                        appointments[i].hour = -1;
                        num_appointments--;
                        printf("Appointment cancelled for %s on day %d at hour %d.\n", 
                               input, day, hour);
                        break;
                    }
                }
                break;
            case 3: // View appointments
                printf("Name\t\tDay\tHour\n");
                printf("------------------------------------\n");
                for(int i = 0; i < MAX_APPOINTMENTS; i++) {
                    if(strcmp(appointments[i].name, "") != 0) {
                        printf("%s\t\t%d\t%d\n", appointments[i].name, 
                               appointments[i].day, appointments[i].hour);
                    }
                }
                if(num_appointments == 0) {
                    printf("No appointments currently scheduled.\n");
                }
                break;
            case 4: // Exit
                printf("Exiting program.\n");
                break;
            default: // Invalid option
                printf("Invalid option, please try again.\n");
                break;
        }
        
        printf("\n");
    } while(option != 4);
    
    return 0;
}