//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int availableTimeSlots[10] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18}; // available time slots from 9 AM to 6 PM
int selectedTimeSlot;

void selectTimeSlot() {
    printf("Please select a time slot from the following available options:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %d:00 - %d:59\n", i+1, availableTimeSlots[i], availableTimeSlots[i]+1);
    }
    scanf("%d", &selectedTimeSlot);
}

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentHour = tm.tm_hour; // get current hour

    if (currentHour < 9 || currentHour > 18) { // check if current hour is outside of working hours
        printf("Sorry, the scheduler is only available from 9 AM to 6 PM.\n");
        return 0;
    }

    selectTimeSlot(); // get user input for time slot

    if (selectedTimeSlot < 1 || selectedTimeSlot > 10) { // check if user input is valid
        printf("Invalid time slot. Please try again.\n");
        return 0;
    }

    int selectedHour = availableTimeSlots[selectedTimeSlot-1];
    printf("You have selected the following time slot: %d:00 - %d:59\n", selectedHour, selectedHour+1);
    printf("Thank you for scheduling an appointment with us!\n");

    return 0;
}