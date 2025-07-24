//FormAI DATASET v1.0 Category: Date and time ; Style: recursive
#include <stdio.h>
#include <time.h>

void print_time(int hour, int minute, int second) {
    // Base case: when all time values reach their maximum limit
    if(hour == 23 && minute == 59 && second == 59) {
        printf("Time's up! You have reached the end of the day.");
    } else {
        // Print the current time
        printf("%02d:%02d:%02d\n", hour, minute, second);
        
        // Recursive call to increment time values
        if(minute == 59 && second == 59) {
            print_time(hour+1, 0, 0);
        } else if(second == 59) {
            print_time(hour, minute+1, 0);
        } else {
            print_time(hour, minute, second+1);
        }
    }
}

int main() {
    // Get the current time using the time function
    time_t t = time(NULL);
    struct tm *tm_time = localtime(&t);
    
    int hour = tm_time->tm_hour;
    int minute = tm_time->tm_min;
    int second = tm_time->tm_sec;
    
    printf("Starting time: %02d:%02d:%02d\n", hour, minute, second);
    
    // Call the recursive function to print time
    print_time(hour, minute, second);
    
    return 0;
}