//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int current_light = RED_LIGHT;

void* traffic_light_controller(void *arg)
{
    int *ptr = (int *)arg;

    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (*ptr == current_light)
        {
            switch (*ptr)
            {
                case RED_LIGHT:
                    printf("Red light is on.\n");
                    sleep(5);
                    current_light = GREEN_LIGHT;
                    break;
                case YELLOW_LIGHT:
                    printf("Yellow light is on.\n");
                    sleep(2);
                    current_light = RED_LIGHT;
                    break;
                case GREEN_LIGHT:
                    printf("Green light is on.\n");
                    sleep(10);
                    current_light = YELLOW_LIGHT;
                    break;
                default:
                    printf("Invalid traffic light color.\n");
            }
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread_id[3];

    int red = RED_LIGHT, yellow = YELLOW_LIGHT, green = GREEN_LIGHT;

    if (pthread_create(&thread_id[0], NULL, traffic_light_controller, &red) != 0)
    {
        printf("Thread creation failed.\n");
        exit(1);
    }

    if (pthread_create(&thread_id[1], NULL, traffic_light_controller, &yellow) != 0)
    {
        printf("Thread creation failed.\n");
        exit(1);
    }

    if (pthread_create(&thread_id[2], NULL, traffic_light_controller, &green) != 0)
    {
        printf("Thread creation failed.\n");
        exit(1);
    }

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    pthread_join(thread_id[2], NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}