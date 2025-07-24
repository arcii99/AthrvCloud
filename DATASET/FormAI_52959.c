//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h> // For threading
#include <unistd.h> // For sleep function

// Function declarations
void *livingRoomLight(void *);
void *bedroomLight(void *);
void *garageDoor(void *);

bool livingRoomLightStatus = false;
bool bedroomLightStatus = false;
bool garageDoorStatus = false;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t thread1, thread2, thread3;

    // Create three threads, one for each device
    pthread_create(&thread1, NULL, livingRoomLight, NULL);
    pthread_create(&thread2, NULL, bedroomLight, NULL);
    pthread_create(&thread3, NULL, garageDoor, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}

void *livingRoomLight(void *arg)
{
    while (true)
    {
        pthread_mutex_lock(&mutex1);
        if(!livingRoomLightStatus)
        {
            printf("Living room light is OFF. Turning it ON.\n");
            livingRoomLightStatus = true;
        }
        else
        {
            printf("Living room light is ON. Turning it OFF.\n");
            livingRoomLightStatus = false;
        }
        pthread_mutex_unlock(&mutex1);
        sleep(10);
    }
}

void *bedroomLight(void *arg)
{
    while (true)
    {
        pthread_mutex_lock(&mutex1);
        if(!bedroomLightStatus)
        {
            printf("Bedroom light is OFF. Turning it ON.\n");
            bedroomLightStatus = true;
        }
        else
        {
            printf("Bedroom light is ON. Turning it OFF.\n");
            bedroomLightStatus = false;
        }
        pthread_mutex_unlock(&mutex1);
        sleep(15);
    }
}

void *garageDoor(void *arg)
{
    while (true)
    {
        pthread_mutex_lock(&mutex1);
        if(!garageDoorStatus)
        {
            printf("Garage door is CLOSED. Opening it.\n");
            garageDoorStatus = true;
        }
        else
        {
            printf("Garage door is OPEN. Closing it.\n");
            garageDoorStatus = false;
        }
        pthread_mutex_unlock(&mutex1);
        sleep(20);
    }
}