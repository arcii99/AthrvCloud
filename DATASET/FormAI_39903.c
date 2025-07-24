//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: accurate
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <time.h>  
  
#define MAX_SIGNAL_STRENGTH 100  
#define MIN_SIGNAL_STRENGTH 0  
#define DEFAULT_INTERVAL 1  

int main(int argc, char *argv[])  
{  
    int current_signal_strength;  
    time_t current_time;  
    struct tm *local_time;  
    int interval = DEFAULT_INTERVAL;  
  
    if (argc < 2) {  
        printf("Usage: signal_strength_analyzer <interval>\n");  
        printf("Where <interval> is the number of seconds between measurements (default is %d)\n", DEFAULT_INTERVAL);  
        return 0;  
    }  
    else if (argc == 2) {  
        interval = atoi(argv[1]);  
    }  
  
    srand((unsigned int) time(NULL)); /* Seed the random number generator */  
  
    while(1) {  
        current_signal_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;  
        time(&current_time);  
        local_time = localtime(&current_time);  
  
        printf("%02d:%02d:%02d Signal strength: %d%%\n",  
               local_time->tm_hour, local_time->tm_min, local_time->tm_sec, current_signal_strength);  
  
        sleep(interval);  
    }  
  
    return 0;  
}