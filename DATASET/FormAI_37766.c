//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#define RED_LIGHT    "\033[31m"
#define YELLOW_LIGHT "\033[33m"
#define GREEN_LIGHT  "\033[32m"
#define RESET        "\033[0m"

void *control_traffic(void *ptr);

pthread_cond_t  condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

bool is_running = true;

int main()
{
    pthread_t traffic_controller;
    
    printf("\nTraffic Light Controller\n");
    printf("------------------------\n\n");
    
    if(pthread_create(&traffic_controller, NULL, control_traffic, NULL))
    {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    
    printf("Press any key to stop the program\n");
    getchar();
    is_running = false;
    
    if(pthread_join(traffic_controller, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    
    printf("\nProgram stopped\n");
    
    return 0;
}

void *control_traffic(void *ptr)
{
    while(is_running)
    {
        pthread_mutex_lock(&mutex);
        
        printf("%s%s%s    \r", GREEN_LIGHT, "GREEN", RESET);
        sleep(2);
        
        printf("%s%s%s    \r", YELLOW_LIGHT, "YELLOW", RESET);
        sleep(1);
        
        printf("%s%s%s    \r", RED_LIGHT, "RED", RESET);
        sleep(2);
        
        pthread_mutex_unlock(&mutex);
        
        sleep(1);
    }
    
    pthread_exit(0);
}