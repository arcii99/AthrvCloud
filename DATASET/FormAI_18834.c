//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    char name[20];
    char date[11];
    char time[6];
};

typedef struct Appointment Appointment;

void displayMenu();
void addAppointment(Appointment appointments[], int* numAppointments);
void cancelAppointment(Appointment appointments[], int* numAppointments);
void viewAppointments(Appointment appointments[], int numAppointments);
bool isDateValid(char date[]);
bool isTimeValid(char time[]);
void clearInputBuffer();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;
    
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
                
            case 2:
                cancelAppointment(appointments, &numAppointments);
                break;
                
            case 3:
                viewAppointments(appointments, numAppointments);
                break;
                
            case 4:
                printf("Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View appointments\n");
    printf("4. Quit\n");
}

void addAppointment(Appointment appointments[], int* numAppointments) {
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("\nMaximum appointments reached. Cannot add more.\n");
        return;
    }
    
    printf("\nEnter appointment details\n");
    printf("------------------------\n");
    printf("Name: ");
    scanf("%19s", appointments[*numAppointments].name);
    printf("Date (MM/DD/YYYY): ");
    scanf("%10s", appointments[*numAppointments].date);
    printf("Time (HH:MM): ");
    scanf("%5s", appointments[*numAppointments].time);
    clearInputBuffer();
    
    if (!isDateValid(appointments[*numAppointments].date)) {
        printf("\nInvalid date! Try again.\n");
        return;
    }
    
    if (!isTimeValid(appointments[*numAppointments].time)) {
        printf("\nInvalid time! Try again.\n");
        return;
    }
    
    printf("\nAppointment added successfully!\n");
    (*numAppointments)++;
}

void cancelAppointment(Appointment appointments[], int* numAppointments) {
    if (*numAppointments == 0) {
        printf("\nNo appointments found. Cannot cancel.\n");
        return;
    }
    
    char name[20];
    printf("\nEnter name: ");
    scanf("%19s", name);
    clearInputBuffer();
    
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            printf("\nAppointment found:\n");
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\nAre you sure you want to cancel this appointment? (Y/N): ");
            char choice = getchar();
            clearInputBuffer();
            
            if (toupper(choice) == 'Y') {
                for (int j = i; j < *numAppointments - 1; j++) {
                    appointments[j] = appointments[j+1];
                }
                (*numAppointments)--;
                printf("\nAppointment cancelled successfully!\n");
                return;
            } else {
                printf("\nCancelled cancelling appointment.\n");
                return;
            }
        }
    }
    
    printf("\nAppointment not found. Cannot cancel.\n");
}

void viewAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nNo appointments found.\n");
        return;
    }
    
    printf("\nAppointments:\n");
    printf("-------------\n");
    
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }
}

bool isDateValid(char date[]) {
    int month, day, year;
    char delim[] = "/";
    
    char* token = strtok(date, delim);
    month = atoi(token);
    if (month < 1 || month > 12)
        return false;
    
    token = strtok(NULL, delim);
    day = atoi(token);
    if (day < 1 || day > 31)
        return false;
    
    token = strtok(NULL, delim);
    year = atoi(token);
    if (year < 2000 || year > 2050)
        return false;
    
    return true;
}

bool isTimeValid(char time[]) {
    int hour, min;
    char delim[] = ":";
    
    char* token = strtok(time, delim);
    hour = atoi(token);
    if (hour < 0 || hour > 23)
        return false;
    
    token = strtok(NULL, delim);
    min = atoi(token);
    if (min < 0 || min > 59)
        return false;
    
    return true;
}

void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}