//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char location[50];
    char description[100];
} Appointment;

int main() {
    Appointment appt1 = {12, 4, 2022, 14, 30, "123 Main St", "Meeting with client"};
    printf("Appointment on %d/%d/%d at %02d:%02d - %s: %s\n", appt1.day, appt1.month, appt1.year,
           appt1.hour, appt1.minute, appt1.location, appt1.description);
    return 0;
}