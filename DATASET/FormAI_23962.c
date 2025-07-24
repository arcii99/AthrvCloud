//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int current_time, hour, minute;
    time_t t;
    srand((unsigned) time(&t));
    printf("Enter the current time in HH:MM format (24hr format): ");
    scanf("%d:%d", &hour, &minute);
    current_time = hour*60 + minute; // current time in minutes
    int rand_num = rand()%10 + 1; // random number generator
    int light_on = 0; // 0 means light is off, 1 means light is on
    
    if(current_time >= 720 && current_time <= 1020){ // check if it's day time (from 12 PM to 6 PM)
        printf("It's day time. Light is turned off.\n");
    }else{
        if(rand_num <= 5){ // randomly turn on the light with 50% probability
            light_on = 1;
        }
        if(light_on){
            printf("It's night time. Light is turned on.\n");
        }else{
            printf("It's night time. Light is turned off.\n");
        }
    }
    return 0;
}