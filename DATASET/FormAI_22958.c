//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#define MAX_BAGGAGE 20      // maximum number of baggage that can be processed
#define MAX_TIME 120        // maximum time for processing each baggage
#define IDLE_TIME 60        // time to wait before processing next baggage

int main() {
    int nBaggage, nTime;
    int baggage[MAX_BAGGAGE];
    int i, j;
    
    // get input from user
    printf("Enter the number of baggage: ");
    scanf("%d", &nBaggage);
    printf("Enter the time taken to process each baggage (in seconds): ");
    scanf("%d", &nTime);
    
    // initialize baggage array
    for (i = 0; i < nBaggage; i++) {
        baggage[i] = ((i+1) * nTime) % MAX_TIME;
    }
    
    // simulate baggage handling
    int totalTime = 0;
    int idleTime = 0;
    int maxWaitTime = 0;
    for (i = 0; i < nBaggage; i++) {
        // check if previous baggage is processed
        if (totalTime < baggage[i-1] + nTime) {
            idleTime += baggage[i-1] + nTime - totalTime;
            totalTime = baggage[i-1] + nTime;
        }
        else {
            totalTime += nTime;
        }
        
        // calculate wait time
        int waitTime = totalTime - baggage[i];
        if (waitTime > maxWaitTime) {
            maxWaitTime = waitTime;
        }
    }
    
    // print results
    printf("Total time taken to process all baggage: %d seconds\n", totalTime);
    printf("Total idle time: %d seconds\n", idleTime);
    printf("Maximum wait time: %d seconds\n", maxWaitTime);
    
    return 0;
}