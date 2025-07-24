//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm past;
    double difference_in_seconds;
    
    // set the current time
    time(&now);
    
    // set the past time to 60 seconds ago
    past = *localtime(&now - 60);
    
    // calculate the difference in seconds between now and the past
    difference_in_seconds = difftime(now, mktime(&past));
    
    // print the current time and the past time
    printf("Current time: %s", ctime(&now));
    printf("Past time: %s", asctime(&past));
    
    // print the difference in seconds
    printf("Difference in seconds: %f\n", difference_in_seconds);
    
    return 0;
}