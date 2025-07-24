//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#define MAX_APPOINTMENTS 10

struct Appointment {
    int month;
    int day;
    int hour;
    char description[100];
};

struct Scheduler {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int n_appointments;
};

void add_appointment(struct Scheduler *scheduler, struct Appointment appointment) {
    if (scheduler->n_appointments >= MAX_APPOINTMENTS) {
        printf("Scheduler is full. Cannot add new appointment.\n");
        return;
    }
    scheduler->appointments[scheduler->n_appointments++] = appointment;
}

void list_appointments(struct Scheduler scheduler) {
    if (!scheduler.n_appointments) {
        printf("No appointments in the scheduler.\n");
        return;
    }
    printf("List of appointments:\n");
    for (int i = 0; i < scheduler.n_appointments; i++) {
        printf("%d/%d at %d:00 - %s\n",
            scheduler.appointments[i].month, scheduler.appointments[i].day,
            scheduler.appointments[i].hour, scheduler.appointments[i].description);
    }
}

int main() {
    struct Scheduler scheduler = {0};

    add_appointment(&scheduler, (struct Appointment) {10, 25, 15, "Lunch with John"});
    add_appointment(&scheduler, (struct Appointment) {10, 26, 9, "Client meeting"});
    add_appointment(&scheduler, (struct Appointment) {10, 26, 14, "Doctor's appointment"});

    list_appointments(scheduler);

    return 0;
}