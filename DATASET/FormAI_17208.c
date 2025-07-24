//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Appointment {
  char date[10];
  char time[6];
  char name[50];
  char email[50];
  char phone[15];
} appointment;

void print_menu();
int validate_date(char date[]);
int validate_time(char time[]);
void add_appointment(appointment** appointments_ptr, int* num_appointments);
void view_appointments(appointment* appointments, int num_appointments);
void delete_appointment(appointment** appointments_ptr, int* num_appointments);
void save_data(appointment* appointments, int num_appointments);

int main() {
  appointment* appointments = NULL;
  int num_appointments = 0;

  char input[10];
  int choice;

  do {
    print_menu();
    fgets(input, 10, stdin);
    choice = atoi(input);

    switch(choice) {
      case 1:
        add_appointment(&appointments, &num_appointments);
        break;
      case 2:
        view_appointments(appointments, num_appointments);
        break;
      case 3:
        delete_appointment(&appointments, &num_appointments);
        break;
      case 4:
        save_data(appointments, num_appointments);
        printf("Data saved successfully!\n");
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice! Please try again.\n");
    }
  } while(choice != 5);

  return 0;
}

void print_menu() {
  printf("\n--Appointment Scheduler--\n");
  printf("1. Schedule an appointment\n");
  printf("2. View all appointments\n");
  printf("3. Cancel an appointment\n");
  printf("4. Save data\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

int validate_date(char date[]) {
  if(strlen(date) != 10) {
    return 0;
  }

  int i;
  for(i=0; i<10; i++) {
    if(i == 2 || i == 5) {
      if(date[i] != '/') {
        return 0;
      }
    }
    else {
      if(date[i] < '0' || date[i] > '9') {
        return 0;
      }
    }
  }

  return 1;
}

int validate_time(char time[]) {
  if(strlen(time) != 5) {
    return 0;
  }

  int i;
  for(i=0; i<5; i++) {
    if(i == 2) {
      if(time[i] != ':') {
        return 0;
      }
    }
    else {
      if(time[i] < '0' || time[i] > '9') {
        return 0;
      }
    }
  }

  return 1;
}

void add_appointment(appointment** appointments_ptr, int* num_appointments) {
  char date[10], time[6], name[50], email[50], phone[15];

  printf("\nEnter appointment date (in DD/MM/YYYY format): ");
  fgets(date, 10, stdin);
  date[strcspn(date, "\n")] = 0;

  if(!validate_date(date)) {
    printf("Invalid date format!\n");
    return;
  }

  printf("Enter appointment time (in HH:MM format): ");
  fgets(time, 6, stdin);
  time[strcspn(time, "\n")] = 0;

  if(!validate_time(time)) {
    printf("Invalid time format!\n");
    return;
  }

  printf("Enter patient name: ");
  fgets(name, 50, stdin);
  name[strcspn(name, "\n")] = 0;

  printf("Enter patient email: ");
  fgets(email, 50, stdin);
  email[strcspn(email, "\n")] = 0;

  printf("Enter patient phone number: ");
  fgets(phone, 15, stdin);
  phone[strcspn(phone, "\n")] = 0;

  if(*appointments_ptr == NULL) {
    *appointments_ptr = (appointment*) malloc(sizeof(appointment));
  }
  else {
    *appointments_ptr = (appointment*) realloc(*appointments_ptr, (*num_appointments + 1) * sizeof(appointment));
  }

  strcpy((*appointments_ptr + *num_appointments)->date, date);
  strcpy((*appointments_ptr + *num_appointments)->time, time);
  strcpy((*appointments_ptr + *num_appointments)->name, name);
  strcpy((*appointments_ptr + *num_appointments)->email, email);
  strcpy((*appointments_ptr + *num_appointments)->phone, phone);

  *num_appointments += 1;

  printf("Appointment added successfully!\n");
}

void view_appointments(appointment* appointments, int num_appointments) {
  if(num_appointments == 0) {
    printf("No appointments scheduled yet!\n");
    return;
  }

  printf("\n--All Appointments--\n");
  int i;
  for(i=0; i<num_appointments; i++) {
    printf("\nDate: %s\n", (appointments+i)->date);
    printf("Time: %s\n", (appointments+i)->time);
    printf("Name: %s\n", (appointments+i)->name);
    printf("Email: %s\n", (appointments+i)->email);
    printf("Phone: %s\n", (appointments+i)->phone);
  }
}

void delete_appointment(appointment** appointments_ptr, int* num_appointments) {
  if(*num_appointments == 0) {
    printf("No appointments scheduled yet!\n");
    return;
  }

  char date[10], time[6];

  printf("\nEnter appointment date to cancel (in DD/MM/YYYY format): ");
  fgets(date, 10, stdin);
  date[strcspn(date, "\n")] = 0;

  printf("Enter appointment time to cancel (in HH:MM format): ");
  fgets(time, 6, stdin);
  time[strcspn(time, "\n")] = 0;

  int i, j;
  for(i=0; i<*num_appointments; i++) {
    if(strcmp(date, (*appointments_ptr + i)->date) == 0 && strcmp(time, (*appointments_ptr + i)->time) == 0) {
      for(j=i; j<*num_appointments-1; j++) {
        strcpy((*appointments_ptr + j)->date, (*appointments_ptr + j + 1)->date);
        strcpy((*appointments_ptr + j)->time, (*appointments_ptr + j + 1)->time);
        strcpy((*appointments_ptr + j)->name, (*appointments_ptr + j + 1)->name);
        strcpy((*appointments_ptr + j)->email, (*appointments_ptr + j + 1)->email);
        strcpy((*appointments_ptr + j)->phone, (*appointments_ptr + j + 1)->phone);
      }

      *num_appointments -= 1;

      if(*num_appointments == 0) {
        free(*appointments_ptr);
        *appointments_ptr = NULL;
      }
      else {
        *appointments_ptr = (appointment*) realloc(*appointments_ptr, (*num_appointments) * sizeof(appointment));
      }

      printf("Appointment cancelled successfully!\n");
      return;
    }
  }

  printf("Appointment not found!\n");
}

void save_data(appointment* appointments, int num_appointments) {
  FILE* fp;

  fp = fopen("appointments.dat", "wb");

  fwrite(&num_appointments, sizeof(int), 1, fp);
  fwrite(appointments, sizeof(appointment), num_appointments, fp);

  fclose(fp);
}