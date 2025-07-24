//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SLOT 10
#define MAX_NAME 20

struct Appointment {
    int slotId;
    char name[MAX_NAME];
};

int findSlot(struct Appointment appointments[MAX_SLOT], int slotId) {
    for(int i = 0; i < MAX_SLOT; i++) {
        if(appointments[i].slotId == slotId) {
            return i;
        }
    }
    return -1;
}

void printAppointments(struct Appointment appointments[MAX_SLOT]) {
    printf("Current appointments:\n");
    for(int i = 0; i < MAX_SLOT; i++) {
        printf("Slot %d: %s\n", appointments[i].slotId, appointments[i].name);
    }
}

int main() {
    struct Appointment appointments[MAX_SLOT];
    int availableSlots[MAX_SLOT];
    int counter = 0;

    // For simplicity, initialize all slots as available at the beginning
    for(int i = 0; i < MAX_SLOT; i++) {
        availableSlots[i] = i+1;
    }

    printf("Welcome to the appointment scheduler!\n");

    while(1) {
        printf("\nEnter 'add' to schedule a new appointment \nEnter 'cancel' to cancel an appointment \nEnter 'exit' to exit\n");

        char command[MAX_NAME];
        scanf("%s", command);

        if(strcmp(command, "add") == 0) {
            if(counter == MAX_SLOT) {
                printf("No slots available.\n");
            } else {
                printf("\nEnter your name: ");
                char name[MAX_NAME];
                scanf("%s", name);

                printf("\nAvailable slots:");
                for(int i = 0; i < MAX_SLOT; i++) {
                    if(availableSlots[i] != 0) {
                        printf(" %d", availableSlots[i]);
                    }
                }

                printf("\nEnter the slot number: ");
                int slotId;
                scanf("%d", &slotId);

                if(findSlot(appointments, slotId) == -1) {
                    struct Appointment appt = {slotId, name};
                    appointments[counter++] = appt;

                    printf("\nAppointment scheduled successfully!\n");
                    availableSlots[slotId-1] = 0;

                    printAppointments(appointments);
                } else {
                    printf("\nSlot already taken, please choose another slot.\n");
                }
            }
        } else if(strcmp(command, "cancel") == 0) {
            printf("\nEnter the slot number you would like to cancel: ");
            int slotId;
            scanf("%d", &slotId);

            int index = findSlot(appointments, slotId);
            if(index != -1) {
                printf("\nAppointment for slot %d canceled successfully.\n", slotId);
                appointments[index] = appointments[counter-1];
                counter--;
                availableSlots[slotId-1] = slotId;
            } else {
                printf("\nNo appointment found for slot %d.\n", slotId);
            }

            printAppointments(appointments);
        } else if(strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}