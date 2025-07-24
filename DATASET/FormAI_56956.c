//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <time.h>

void logEvent(const char *msg) {
    time_t t;
    time(&t);
    printf("%s - %s\n", asctime(localtime(&t)), msg);
}

int main() {
    logEvent("System boot up");
    logEvent("User logged in");
    logEvent("File accessed");

    return 0;
}