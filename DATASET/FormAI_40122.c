//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main() {

    time_t t;
    struct tm *local;
    char time_str[100];

    // Get the current time
    t = time(NULL);
    local = localtime(&t);

    // Format the time string
    strftime(time_str, sizeof(time_str), "%A, %B %d, %Y %I:%M:%S %p", local);

    // Print the time string in bold
    printf("\033[1m%s\n\033[0m", time_str);

    return 0;
}