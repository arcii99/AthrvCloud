//FormAI DATASET v1.0 Category: Date and time ; Style: inquisitive
#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%A, %d %B %Y %H:%M:%S %Z", timeinfo);
    printf("The current date and time is: %s\n", buffer);

    return 0;
}