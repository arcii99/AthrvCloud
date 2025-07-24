//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <time.h>

void task_1() {
    printf("Task 1 has started.\n");
    printf("Executing Task 1...\n");
    // Simulate task execution time
    for(int i = 0; i < 1000000000; i++);
    printf("Task 1 has finished.\n");
}

void task_2() {
    printf("Task 2 has started.\n");
    printf("Executing Task 2...\n");
    // Simulate task execution time
    for(int i = 0; i < 500000000; i++);
    printf("Task 2 has finished.\n");
}

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[9];
    
    printf("Program started.\n\n");
    
    while (1) {
        // Get current time
        current_time = time(NULL);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
        printf("Current time: %s\n", time_string);
        
        // Check if it is time to run task 1
        if (time_info->tm_hour == 10 && time_info->tm_min == 30 && time_info->tm_sec == 0) {
            task_1();
        }
        
        // Check if it is time to run task 2
        if (time_info->tm_hour == 15 && time_info->tm_min == 0 && time_info->tm_sec == 0) {
            task_2();
        }
        
        // Sleep for one second
        sleep(1);
    }
    
    return 0;
}