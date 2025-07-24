//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Define a structure for appointments
typedef struct {
    char date[11];
    char time[6];
    char description[100];
} appointment;

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define a global array of appointments
appointment appointments[MAX_APPOINTMENTS];

// Keep track of the number of appointments
int numAppointments = 0;

// Function to add an appointment
void addAppointment() {
    // Check if maximum appointments reached
    if(numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, you have reached the maximum number of appointments.\n");
        return;
    }
    
    // Get user input for date and validate
    char date[11];
    printf("Enter date (mm/dd/yyyy): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0; // remove trailing newline
    if(strlen(date) != 10 || !isdigit(date[0]) || !isdigit(date[1]) || date[2] != '/' || !isdigit(date[3]) || !isdigit(date[4]) || date[5] != '/' || !isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9])) {
        printf("Invalid date. Please enter a date in the format mm/dd/yyyy.\n");
        return;
    }
    
    // Get user input for time and validate
    char time[6];
    printf("Enter time (hh:mm): ");
    fgets(time, sizeof(time), stdin);
    time[strcspn(time, "\n")] = 0; // remove trailing newline
    if(strlen(time) != 5 || !isdigit(time[0]) || !isdigit(time[1]) || time[2] != ':' || !isdigit(time[3]) || !isdigit(time[4])) {
        printf("Invalid time. Please enter a time in the format hh:mm.\n");
        return;
    }
    
    // Get user input for appointment description
    char description[100];
    printf("Enter appointment description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = 0; // remove trailing newline
    
    // Add appointment to the array and increment counter
    strcpy(appointments[numAppointments].date, date);
    strcpy(appointments[numAppointments].time, time);
    strcpy(appointments[numAppointments].description, description);
    
    numAppointments++;
    
    printf("Appointment successfully added.\n");
}

// Function to view all appointments
void viewAppointments() {
    // Check if appointments exist
    if(numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    printf("Date\t\t Time\t Description\n");
    printf("---------------------------------------\n");
    for(int i=0; i<numAppointments; i++) {
        printf("%s\t %s\t %s\n", appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

// Function to remove an appointment
void removeAppointment() {
    // Check if appointments exist
    if(numAppointments == 0) {
        printf("No appointments found.\n");
        return;
    }
    
    // Get user input for appointment index and validate
    int index;
    printf("Enter appointment index to remove: ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline
    if(!isdigit(input[0])) {
        printf("Invalid input. Please enter a number.\n");
        return;
    }
    index = atoi(input);
    if(index < 1 || index > numAppointments) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", numAppointments);
        return;
    }
    
    // Shift remaining appointments left and decrement counter
    for(int i=index-1; i<numAppointments-1; i++) {
        strcpy(appointments[i].date, appointments[i+1].date);
        strcpy(appointments[i].time, appointments[i+1].time);
        strcpy(appointments[i].description, appointments[i+1].description);
    }
    
    numAppointments--;
    
    printf("Appointment successfully removed.\n");
}

int main() {
    int choice;
    
    do {
        // Display menu options
        printf("\nAppointment Scheduler\n");
        printf("----------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Remove Appointment\n");
        printf("4. Exit\n");
        
        // Get user input for choice and validate
        char input[10];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline
        if(!isdigit(input[0])) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        choice = atoi(input);
        if(choice < 1 || choice > 4) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            continue;
        }
        
        // Perform action based on user choice
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                removeAppointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}