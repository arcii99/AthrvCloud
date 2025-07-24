//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_APPOINTMENTS 5

// Appointment struct
typedef struct {
    char name[20];
    char time[10];
} Appointment;

// Global variables
Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Mutex and condition variables for synchronization
pthread_mutex_t mutex;
pthread_cond_t add_condition;
pthread_cond_t print_condition;

// Function to add an appointment
void add_appointment(char *name, char *time) {
    pthread_mutex_lock(&mutex);
    // Wait if the appointment list is full
    while (appointment_count == MAX_APPOINTMENTS) {
        pthread_cond_wait(&add_condition, &mutex);
    }
    // Add the new appointment and signal the printing thread
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    strcpy(new_appointment.time, time);
    appointments[appointment_count++] = new_appointment;
    pthread_cond_signal(&print_condition);
    pthread_mutex_unlock(&mutex);
}

// Function to print all the appointments
void print_appointments() {
    pthread_mutex_lock(&mutex);
    // Wait if there are no appointments
    while (appointment_count == 0) {
        pthread_cond_wait(&print_condition, &mutex);
    }
    // Print all the appointments and signal the adding thread
    printf("\nAppointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%s at %s\n", appointments[i].name, appointments[i].time);
    }
    printf("\n");
    appointment_count = 0;
    pthread_cond_signal(&add_condition);
    pthread_mutex_unlock(&mutex);
}

void *adding_thread(void *param);
void *printing_thread(void *param);

int main() {
    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&add_condition, NULL);
    pthread_cond_init(&print_condition, NULL);

    // Create two threads, one for adding appointments and the other for printing them
    pthread_t thread1, thread2;
    int status1, status2;

    status1 = pthread_create(&thread1, NULL, adding_thread, NULL);
    if (status1 != 0) {
        printf("Error creating thread1\n");
        exit(1);
    }

    status2 = pthread_create(&thread2, NULL, printing_thread, NULL);
    if (status2 != 0) {
        printf("Error creating thread2\n");
        exit(1);
    }

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&add_condition);
    pthread_cond_destroy(&print_condition);

    return 0;
}

void *adding_thread(void *param) {
    add_appointment("John Smith", "10:00");
    add_appointment("Jane Doe", "11:30");
    add_appointment("Bob Johnson", "14:00");
    add_appointment("Lisa Brown", "15:30");
    add_appointment("Mike Davis", "16:45");
    pthread_exit(NULL);
}

void *printing_thread(void *param) {
    print_appointments();
    print_appointments();
    print_appointments();
    pthread_exit(NULL);
}