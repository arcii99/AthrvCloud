//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Function to convert natural language dates to Unix time
void* convert_date(void* arg) {
    char* input_date = (char*) arg;
    
    // Define the months and their corresponding number of days
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Use strtok to break up the input date into its components
    char* p = strtok(input_date, " ");
    char* month_str = p;
    p = strtok(NULL, " ");
    int day = atoi(p);
    p = strtok(NULL, " ");
    int year = atoi(p);
    
    // Convert the month string to an integer
    int month = -1;
    for (int i = 0; i < 12; i++) {
        if (strcmp(month_str, months[i]) == 0) {
            month = i;
            break;
        }
    }
    
    // Check if the given date is valid
    if (month == -1 || day < 1 || day > days_in_month[month] || year < 1970 || year > 3000) {
        printf("Invalid date: %s\n", input_date);
        return NULL;
    }
    
    // Convert the natural language date to Unix time
    struct tm time = {0};
    time.tm_year = year - 1900;
    time.tm_mon = month;
    time.tm_mday = day;
    time_t unix_time = mktime(&time);
    
    // Print the Unix time
    printf("%s Unix time: %ld\n", input_date, unix_time);
    
    return NULL;
}

int main() {
    pthread_t threads[3];
    char* input_dates[] = {"October 10, 2021", "December 31, 1999", "January 1, 2000"};

    // Create three threads to convert the input dates to Unix time
    for (int i = 0; i < 3; i++) { 
        pthread_create(&threads[i], NULL, convert_date, (void*) input_dates[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}