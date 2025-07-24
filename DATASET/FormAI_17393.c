//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get the current time
    time_t t = time(NULL);

    // Convert current time to a struct tm object
    struct tm* currentTime = localtime(&t);

    // Print current date and time
    printf("Current date and time: %s", asctime(currentTime));

    // Set the time to 50 years ago
    currentTime->tm_year -= 50;

    // Convert modified time to a time_t object
    t = mktime(currentTime);

    // Convert modified time to a struct tm object
    struct tm* timeTravelTime = localtime(&t);

    // Print time travel date and time
    printf("Time travel date and time (50 years ago): %s", asctime(timeTravelTime));
  
    return 0;
}