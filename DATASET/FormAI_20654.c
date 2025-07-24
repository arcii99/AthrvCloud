//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdbool.h>

// Declare global variables
bool slots[7][24];
char appointments[7][24][50];

// Function to display the available slots for a given day
void displayAvailableSlots(int day) {
    printf("\nAvailable Slots for Day %d:\n", day);
    for(int i=0; i<24; i++) {
        if(slots[day][i]) {
            printf("%2d:00 - %2d:00\n", i, i+1);
        }
    }
}

// Function to book an appointment for a given day and time
void bookAppointment(int day, int time, char name[]) {
    slots[day][time] = false;
    strcpy(appointments[day][time], name);
    printf("\nAppointment Booked for: Day %d, %2d:00 - %2d:00, Name: %s\n", day, time, time+1, name);
}

int main() {
    // Initialize slots with all true values
    for(int i=0; i<7; i++) {
        for(int j=0; j<24; j++) {
            slots[i][j] = true;
        }
    }

    // Display available slots for each day
    for(int i=0; i<7; i++) {
        displayAvailableSlots(i);
    }

    // Book appointments
    bookAppointment(1, 10, "King Arthur");
    bookAppointment(3, 18, "Lady Guinevere");
    bookAppointment(6, 13, "Merlin the Wizard");

    // Display updated available slots for each day
    for(int i=0; i<7; i++) {
        displayAvailableSlots(i);
    }

    // Display booked appointments for a given day
    printf("\nAppointments for Day 3:\n");
    for(int i=0; i<24; i++) {
        if(!slots[3][i]) {
            printf("%2d:00 - %2d:00, Name: %s\n", i, i+1, appointments[3][i]);
        }
    }
    
    return 0;
}