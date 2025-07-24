//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main() {

    time_t current_time;
    struct tm* local_time;
    char buffer[80];
    
    // Get the current date and time
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the current date and time
    printf("\033[1m");
    printf("Current Date and Time: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 1 second
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 1 second
    printf("Date and Time after 1 second: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 2 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 2 seconds
    printf("Date and Time after 2 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 3 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 3 seconds
    printf("Date and Time after 3 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 4 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 4 seconds
    printf("Date and Time after 4 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 5 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 5 seconds
    printf("Date and Time after 5 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 6 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 6 seconds
    printf("Date and Time after 6 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 7 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 7 seconds
    printf("Date and Time after 7 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 8 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 8 seconds
    printf("Date and Time after 8 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 9 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 9 seconds
    printf("Date and Time after 9 seconds: %s\n", buffer);
    
    // Wait for 1 second
    sleep(1);
    
    // Get the date and time after 10 seconds
    time(&current_time);
    local_time = localtime(&current_time);
    
    // Custom date and time format
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y %I:%M:%S %p", local_time);
    
    // Print the date and time after 10 seconds
    printf("Date and Time after 10 seconds: %s\n", buffer);
    
    return 0;
}