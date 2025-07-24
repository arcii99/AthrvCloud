//FormAI DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <time.h>

// function to log an event
void logEvent(char* eventName) {
    time_t now;
    time(&now);
    printf("%s event logged at %s", eventName, ctime(&now));
}

int main() {

    // log some events
    logEvent("Program started");
    logEvent("User input received");
    logEvent("Calculation started");
    logEvent("Calculation complete");
    logEvent("Results displayed");
    logEvent("Program exited");

    return 0;
}