//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP 0

int currentTemp = 25; // initializing temperature to 25C

pthread_mutex_t lock;

void *monitorTemp(void *arg){
    while(1){
        pthread_mutex_lock(&lock);
        int random = rand() % 10; // generating random number between 0 to 9
        if(random%2==0){
            // increasing temperature by +1 degree Celsius
            if(currentTemp < MAX_TEMP) currentTemp++;
            printf("The temperature has increased to %dC\n", currentTemp);
        }
        else{
            // decreasing temperature by -1 degree Celsius
            if(currentTemp > MIN_TEMP) currentTemp--; 
            printf("The temperature has dropped to %dC\n",currentTemp);
        }
        pthread_mutex_unlock(&lock);
        sleep(5); // waiting for 5 seconds to update temperature
    }
    return NULL;
}

int main(){
    srand(time(NULL)); // seeding random number generator
    pthread_mutex_init(&lock, NULL); // initializing mutex lock

    pthread_t monitorThread;

    // creating thread to monitor temperature
    if(pthread_create(&monitorThread, NULL, monitorTemp, NULL)) {
      fprintf(stderr, "Error creating monitorThread thread\n");
      exit(1);
    }

    while(1){
        pthread_mutex_lock(&lock);
        printf("Current Temperature is : %dC\n", currentTemp);
        pthread_mutex_unlock(&lock);
        sleep(2); // waiting for 2 seconds to display current temperature
    }

    pthread_mutex_destroy(&lock); // destroying mutex lock
    pthread_exit(NULL); // exiting thread
    return 0;
}