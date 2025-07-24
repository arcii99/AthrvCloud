//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 3
#define SLOTS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_slot_available = PTHREAD_COND_INITIALIZER;

int slot_count = SLOTS;

void *patient(void *threadid) {
   int tid = (int)threadid;
   while (1) {
      pthread_mutex_lock(&mutex);
      while (slot_count == 0) {
         printf("Patient %d waiting for slots...\n", tid);
         pthread_cond_wait(&cond_slot_available, &mutex);
      }
      slot_count--;
      printf("Patient %d takes a slot! Slots remaining: %d\n", tid, slot_count);
      pthread_mutex_unlock(&mutex);
      
      // Simulating appointment time
      int appointment_time = rand() % 5 + 1; // Random number between 1-5 seconds
      printf("Patient %d is having an appointment for %d seconds...\n", tid, appointment_time);
      sleep(appointment_time);
      
      pthread_mutex_lock(&mutex);
      slot_count++;
      printf("Patient %d frees a slot. Slots remaining: %d\n", tid, slot_count);
      pthread_cond_signal(&cond_slot_available);
      pthread_mutex_unlock(&mutex);
   }
   pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   // Initialize random seed
   srand(time(NULL));
   
   // Create threads
   for(t=0; t<NUM_THREADS; t++){
      printf("Creating patient %ld...\n", t);
      rc = pthread_create(&threads[t], NULL, patient, (void *)t);
      if (rc) {
         printf("Error: unable to create thread %ld\n", t);
         exit(-1);
      }
   }
   
   // Main thread waits for other threads to complete
   pthread_exit(NULL);
}