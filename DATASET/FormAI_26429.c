//FormAI DATASET v1.0 Category: System boot optimizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60

int main(void) {
    int boot_time, optimized_time, current_time, elapsed_time;
    srand(time(NULL));
    
    // Generating random boot time between 30 to 90 seconds
    boot_time = rand() % 61 + 30;
    
    printf("System booting up...\n");
    printf("Please wait for %d seconds.\n", boot_time);
    sleep(boot_time);
    
    // Getting current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_time = tm.tm_hour * MINUTES_PER_HOUR * SECONDS_PER_MINUTE + tm.tm_min * SECONDS_PER_MINUTE + tm.tm_sec;
    
    printf("System booted up at the following time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    // Optimizing boot time
    optimized_time = rand() % 6 + 3; // Adding 3 to avoid optimization of boot time less than 3 seconds
    printf("Optimizing system boot time...\n");
    printf("Please wait for %d seconds.\n", optimized_time);
    sleep(optimized_time);
    
    // Getting current time again
    t = time(NULL);
    tm = *localtime(&t);
    elapsed_time = (tm.tm_hour - (current_time / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE))) * HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE + (tm.tm_min - ((current_time / SECONDS_PER_MINUTE) % MINUTES_PER_HOUR)) * SECONDS_PER_MINUTE + (tm.tm_sec - (current_time % SECONDS_PER_MINUTE));
    
    printf("System boot optimized! Boot time reduced by %d seconds.\n", optimized_time);
    printf("System booted up at the following time: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Total elapsed time: %d seconds.\n", elapsed_time);
    
    return EXIT_SUCCESS;
}