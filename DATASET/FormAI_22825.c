//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

// Structure for storing appointment details 
struct Appointment { 
    char name[50]; 
    int day, month, year; 
    char time[10]; 
};

// Function to check if a given date is valid or not 
int dateIsValid(int day, int month, int year) { 
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0; 
    }

    if (month == 2) { 
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return (day <= 29); 
        } else {
            return (day <= 28); 
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { 
        return (day <= 30); 
    } else { 
        return 1; 
    } 
}

// Function to check if a given time is valid or not 
int timeIsValid(char* time) { 
    int hour, minute; 
    if(sscanf(time,"%d:%d",&hour,&minute) != 2) {
        return 0;
    }

    if(hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return 0;
    }

    return 1; 
} 

// Function to add an appointment to the scheduler 
void addAppointment(struct Appointment* appointments, int num_appointments) { 
    
    printf("\n\nEnter Details of Appointment: \n"); 
    
    // Get values for each field of the Appointment struct
    printf("Name: "); 
    scanf("%s", appointments[num_appointments].name);
    
    printf("Date (dd-mm-yyyy): "); 
    scanf("%d-%d-%d", &appointments[num_appointments].day,  &appointments[num_appointments].month,  &appointments[num_appointments].year); 
    
    printf("Time (hh:mm): "); 
    scanf("%s", appointments[num_appointments].time); 
    
    // Check if the date and time values are valid, and give an error message if not
    if(!dateIsValid(appointments[num_appointments].day, appointments[num_appointments].month, appointments[num_appointments].year)) {
        printf("Invalid Date!\n");
        return;
    }

    if(!timeIsValid(appointments[num_appointments].time)) {
        printf("Invalid Time!\n");
        return;
    }

    num_appointments++; // increment the number of appointments

    printf("\n\nAppointment Added Successfully!"); 
} 

// Function to print all appointments in the scheduler 
void displayAppointments(struct Appointment* appointments, int num_appointments) { 
    printf("\n\nAppointments: \n"); 
    printf("Name\t\tDate\t\tTime\n"); 
    for(int i = 0; i < num_appointments; i++) { 
        printf("%s\t\t%d-%d-%d\t%s\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time); 
    } 
} 

// Main function 
int main() { 
    struct Appointment appointments[100]; 
    
    int num_appointments = 0, choice = 0; 
    printf("---------Appointment Scheduler-------\n\n");
    while (choice != 3) { 
        printf("\n-- Menu --\n"); 
        printf("1. Add Appointment\n"); 
        printf("2. Display Appointments\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                addAppointment(appointments, num_appointments); 
                break; 
            case 2: 
                displayAppointments(appointments, num_appointments); 
                break; 
            case 3: 
                printf("\n\nThank you for using the Appointment Scheduler!"); 
                break; 
            default: 
                printf("Invalid choice!\n"); 
        } 
    }
    return 0; 
}