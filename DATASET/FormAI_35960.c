//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#define MAX_APPTS 5 
#define MIN_HOUR 9 
#define MAX_HOUR 17 

typedef struct {
  int day;
  int time;
} appt;

appt calendar[MAX_APPTS];

int main() {
  int i;
  for (i=0; i<MAX_APPTS; i++) {
    printf("Enter appointment day (1-31): ");
    scanf("%d", &calendar[i].day);
    printf("Enter appointment time (9-17): ");
    scanf("%d", &calendar[i].time);
    if (calendar[i].day < 1 || calendar[i].day > 31 || 
        calendar[i].time < MIN_HOUR || calendar[i].time > MAX_HOUR) {
      printf("Invalid appointment time or day.\n");
      printf("Valid days are 1-31 and valid times are 9-17.\n");
      exit(1);
    }
    if (i > 0 && calendar[i].day == calendar[i-1].day && 
        calendar[i].time == calendar[i-1].time) {
      printf("Two appointments cannot be scheduled at the same time on the same day.\n");
      exit(1);
    }
  }
  printf("Appointments scheduled:\n");
  for (i=0; i<MAX_APPTS; i++) {
    printf("Day %d at %d\n", calendar[i].day, calendar[i].time);
  }
  return 0;
}