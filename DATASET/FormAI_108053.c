//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() { 
    srand(time(NULL));
    int i = 0;
    while (i < 50) {
        printf("I am a traffic light controller, but instead of controlling traffic, I control the fate of the drivers. \n");
        
        int time_of_day = rand() % 24;
        
        if (time_of_day >= 6 && time_of_day < 9) {
            printf("The sun is rising, and with it, the hopes and dreams of these drivers. Green light! \n");
        }
        
        else if (time_of_day >= 9 && time_of_day < 12) {
            printf("Ah, mid-morning traffic. No hope for them. Red light! \n");
        }
        
        else if (time_of_day >= 12 && time_of_day < 15) {
            printf("Lunch time, drivers are happy and content. Yellow light! \n");
        }
        
        else if (time_of_day >= 15 && time_of_day < 18) {
            printf("Afternoon rush, drivers are angry and frustrated. Red light! \n");
        }
        
        else if (time_of_day >= 18 && time_of_day < 21) {
            printf("Evening commute, drivers just want to get to their families. Green light! \n");
        }
        
        else {
            printf("Late night driving, nobody is on the road. No lights needed! \n");
        }
        
        i++;
    }
    return 0;
}