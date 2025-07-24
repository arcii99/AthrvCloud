//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numAppointments = 0;
    printf("How many appointments do you want to schedule? ");
    scanf("%d", &numAppointments);

    char appointments[numAppointments][20];
    int times[numAppointments];
    char input[20];
    int timeInput = 0;

    for (int i = 1; i <= numAppointments; i++) {
        printf("Enter name for appointment %d: ", i);
        scanf("%s", input);
        strcpy(appointments[i-1], input);

        printf("Enter time for appointment %d (in 24-hour format): ", i);
        scanf("%d", &timeInput);
        times[i-1] = timeInput;
    }

    // Bubble sort appointments based on time
    for (int i = 0; i < numAppointments; i++) {
        for (int j = 0; j < numAppointments-i-1; j++) {
            if (times[j] > times[j+1]) {
                int tempTime = times[j];
                times[j] = times[j+1];
                times[j+1] = tempTime;

                char tempName[20];
                strcpy(tempName, appointments[j]);
                strcpy(appointments[j], appointments[j+1]);
                strcpy(appointments[j+1], tempName);
            }
        }
    }

    // Print out appointments in order
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d: %s\n", times[i], appointments[i]);
    }

    return 0;
}