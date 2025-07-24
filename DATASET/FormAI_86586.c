//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct person {
  char name[50];
  int age;
};

struct appointment {
  struct person client;
  char date[20];
  char time[20];
  char reason[100];
};

void printMenu() {
  printf("Welcome to the Appointment Scheduler Program\n");
  printf("============================================\n");
  printf("1. Schedule an Appointment\n");
  printf("2. View Scheduled Appointments\n");
  printf("3. Cancel an Appointment\n");
  printf("4. Exit\n");
  printf("============================================\n");
}

void scheduleAppointment(struct appointment *appointments, int *numAppointments) {
  printf("Enter client name: ");
  scanf("%[^\n]%*c", appointments[*numAppointments].client.name);
  printf("Enter client age: ");
  scanf("%d%*c", &appointments[*numAppointments].client.age);
  printf("Enter date (DD/MM/YYYY): ");
  scanf("%[^\n]%*c", appointments[*numAppointments].date);
  printf("Enter time (HH:MM AM/PM): ");
  scanf("%[^\n]%*c", appointments[*numAppointments].time);
  printf("Enter reason for appointment: ");
  scanf("%[^\n]%*c", appointments[*numAppointments].reason);

  printf("Appointment succesfully scheduled!\n");
  (*numAppointments)++;
}

void viewAppointments(struct appointment *appointments, int numAppointments) {
  printf("Scheduled Appointments:\n");
  printf("=======================\n");

  for(int i = 0; i < numAppointments; i++) {
    printf("Client Name: %s\n", appointments[i].client.name);
    printf("Client Age: %d\n", appointments[i].client.age);
    printf("Date: %s\n", appointments[i].date);
    printf("Time: %s\n", appointments[i].time);
    printf("Reason: %s\n", appointments[i].reason);
    printf("=======================\n");
  }
}

void cancelAppointment(struct appointment *appointments, int *numAppointments) {
  char name[50];
  printf("Enter client name: ");
  scanf("%[^\n]%*c", name);

  for(int i = 0; i < *numAppointments; i++) {
    if(strcmp(name, appointments[i].client.name) == 0) {
      for(int j = i; j < *numAppointments - 1; j++) {
        appointments[j] = appointments[j+1];
      }
      (*numAppointments)--;
      printf("Appointment cancelled successfully!\n");
      return;
    }
  }

  printf("Sorry, appointment not found.\n");
}

int main() {
  struct appointment appointments[100];
  int numAppointments = 0;
  int choice;

  do {
    printMenu();
    printf("Enter choice: ");
    scanf("%d%*c", &choice);

    switch(choice) {
      case 1:
        scheduleAppointment(appointments, &numAppointments);
        break;
      case 2:
        if(numAppointments == 0) {
          printf("No Appointments Scheduled Yet.\n");
        } else {
          viewAppointments(appointments, numAppointments);
        }
        break;
      case 3:
        if(numAppointments == 0) {
          printf("No Appointments Scheduled Yet.\n");
        } else {
          cancelAppointment(appointments, &numAppointments);
        }
        break;
      case 4:
        printf("Thank you for using the Appointment Scheduler Program!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while(choice != 4);

  return 0;
}