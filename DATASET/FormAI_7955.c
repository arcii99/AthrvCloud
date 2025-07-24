//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE 0

float getTemperature(){
    float temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    return temperature;
}

int main(){
    float temperature = 0.0;
    int i = 0;
    int current_hour = 0;
    int current_minute = 0;
    int current_second = 0;

    while(1){
        time_t current_time;
        struct tm * time_info;
        char time_string[10];

        time(&current_time);

        time_info = localtime(&current_time);

        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

        current_hour = time_info->tm_hour;
        current_minute = time_info->tm_min;
        current_second = time_info->tm_sec;
        temperature = getTemperature();

        printf("Temperature on %s: %.2f degrees Celsius\n", time_string, temperature);

        for(i=0;i<100000000;i++){} // Hold program for some time before next measurement
    }

    return 0;
}