//FormAI DATASET v1.0 Category: Date and time ; Style: shocked
#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char buffer [80];
    strftime (buffer,80,"%d-%m-%Y %I:%M:%S%p",timeinfo);
    printf("Current date and time is %s.\n", buffer);
    return 0;
}