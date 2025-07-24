//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multi-threaded
#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
void *trackSteps(void *arg); 
void *printStats(void *arg);

int total_steps = 0;
double total_distance = 0;
int total_calories = 0;
pthread_mutex_t lock; 

int main() 
{  
    pthread_t thread1,thread2; 

    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\nMutex initialization failed.\n"); 
        return 1; 
    } 
    
    pthread_create(&thread1, NULL, trackSteps, NULL);
    pthread_create(&thread2, NULL, printStats, NULL);

    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL);
  
    pthread_mutex_destroy(&lock); 
  
    return 0; 
} 

void *trackSteps(void *arg) 
{ 
    int max_steps = 10000;
    int i = 0;

    while (total_steps < max_steps) 
    { 
        pthread_mutex_lock(&lock); 

        int increment = rand() % 10 + 1;
        total_steps += increment;
        double distance = increment * 0.7;
        total_distance += distance;
        total_calories += increment * 0.5;

        pthread_mutex_unlock(&lock); 

        printf("Step %d - Number of Steps: %d, Distance: %.2f km, Calories: %d\n", 
               i+1, total_steps, total_distance, total_calories);
        i++;

        sleep(1);
    } 
    
    printf("You have reached your daily goal of %d steps!\n", max_steps);
    pthread_exit(NULL); 
} 

void *printStats(void *arg)
{
    while (total_steps < 10000) 
    { 
        pthread_mutex_lock(&lock); 

        printf("Current Stats: Number of Steps: %d, Distance: %.2f km, Calories: %d\n", 
               total_steps, total_distance, total_calories);

        pthread_mutex_unlock(&lock); 

        sleep(5);
    }
    
    printf("Total distance covered today: %.2f km.\n", total_distance);

    pthread_exit(NULL); 
}