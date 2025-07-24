//FormAI DATASET v1.0 Category: Date and time ; Style: thoughtful
#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", info);

    printf("Current date and time: %s\n", buffer);

    return 0;
}