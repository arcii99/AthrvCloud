//FormAI DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <time.h>

void logEvent(char* event)
{
    time_t t;
    time(&t);
    printf("[%s]: %s\n", ctime(&t), event);
}

int main()
{
    logEvent("System started.");

    int x = 5;
    logEvent("Variable x initialized.");

    float y = 3.14;
    logEvent("Variable y initialized.");

    if(x == 5 && y == 3.14){
        logEvent("Initialization successful.");
    }

    return 0;
}