//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int light_intensity = 0; // global variable to store light intensity

// function to control the light
void* control_light(void* arg)
{
    while(1)
    {
        int choice;
        printf("1. Increase light intensity\n2. Decrease light intensity\n3. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(light_intensity < 10)
                    light_intensity++;
                printf("Light Intensity: %d\n",light_intensity);
                break;
            case 2:
                if(light_intensity > 0)
                    light_intensity--;
                printf("Light Intensity: %d\n",light_intensity);
                break;
            case 3:
                printf("Exiting Light Control...\n");
                pthread_exit(NULL);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        
    }
}

// function to update the light status
void* update_light_status(void* arg)
{
    while(1)
    {
        printf("Light is ");
        if(light_intensity == 0)
            printf("off\n");
        else if(light_intensity > 0 && light_intensity <= 3)
            printf("dim\n");
        else if(light_intensity > 3 && light_intensity <= 6)
            printf("medium\n");
        else
            printf("bright\n");
        sleep(3);
    }
}

int main()
{
    pthread_t thread1, thread2;
    int rc1, rc2;
    rc1 = pthread_create(&thread1, NULL, control_light, NULL);
    rc2 = pthread_create(&thread2, NULL, update_light_status, NULL);
    if (rc1) {
        printf("Error:unable to create thread1, %d \n", rc1);
        exit(-1);
    }
    if (rc2) {
        printf("Error:unable to create thread2, %d \n", rc2);
        exit(-1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}