//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to control the AC
void* control_AC(void* arg)
{
    int temp = *((int*) arg);
    if (temp > 28) {
        system("echo 'AC turned on'");
    } else {
        system("echo 'AC turned off'");
    }
    pthread_exit(NULL);
}

// Function to control the lights
void* control_Lights(void* arg)
{
    int light = *((int*) arg);
    if (light > 50) {
        system("echo 'Lights turned on'");
    } else {
        system("echo 'Lights turned off'");
    }
    pthread_exit(NULL);
}

int main()
{
    int temperature = 30;
    int light_level = 60;

    pthread_t ac_thread, light_thread;

    // Create 2 threads to control AC and Lights
    pthread_create(&ac_thread, NULL, control_AC, (void*) &temperature);
    pthread_create(&light_thread, NULL, control_Lights, (void*) &light_level);

    // Wait for both threads to finish executing
    pthread_join(ac_thread, NULL);
    pthread_join(light_thread, NULL);

    return 0;
}