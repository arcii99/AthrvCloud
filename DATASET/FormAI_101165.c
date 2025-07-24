//FormAI DATASET v1.0 Category: Date and time ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get the current time using time() function
    time_t current_time = time(NULL);
    
    // Convert the current time to a local time struct using localtime() function
    struct tm *local_time = localtime(&current_time);
    
    // Get the current date using strftime() function
    char date[50];
    strftime(date, sizeof(date), "%A, %B %d, %Y", local_time);
    
    // Get the current time using strftime() function
    char time[50];
    strftime(time, sizeof(time), "%I:%M %p", local_time);
    
    // Print the current date and time
    printf("Today is %s\n", date);
    printf("The current time is %s\n", time);
    
    // Get the user's input for a future date and time
    printf("Enter a future date and time (YYYY-MM-DD HH:MM): ");
    char input[20];
    fgets(input, 20, stdin);
    
    // Convert the user's input to a time struct using strptime() function
    struct tm future_time;
    strptime(input, "%Y-%m-%d %H:%M", &future_time);
    
    // Convert the future time struct to a time_t using mktime() function
    time_t future_time_t = mktime(&future_time);
    
    // Calculate the difference between the future time and the current time
    double difference = difftime(future_time_t, current_time);
    
    // Convert the difference to days, hours, minutes and seconds
    int days = difference / (24 * 60 * 60);
    int hours = (difference - days * 24 * 60 * 60) / (60 * 60);
    int minutes = (difference - days * 24 * 60 * 60 - hours * 60 * 60) / 60;
    int seconds = difference - days * 24 * 60 * 60 - hours * 60 * 60 - minutes * 60;
    
    // Print the difference between the future time and the current time
    printf("%d days, %d hours, %d minutes and %d seconds until %s", days, hours, minutes, seconds, input);

    return 0;
}