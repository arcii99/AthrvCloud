//FormAI DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <time.h>

#define EVENT_LOG "event.log" /* The path to the event log file. */

void log_event(const char* message) {
    time_t now = time(NULL);
    char time_string[20];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", localtime(&now));
  
    FILE* file = fopen(EVENT_LOG, "a");
    if(file) {
        fprintf(file, "[%s] %s\n", time_string, message);
        fclose(file);
    }
}

int main() {
    log_event("Program started."); /* Log the start of the program. */
  
    int x = 5;
    int y = 10;
    int z = x + y;
    printf("The sum of %d and %d is %d.\n", x, y, z);
    log_event("Calculation performed."); /* Log the calculation. */
  
    char* message = "Hello, world!";
    printf("%s\n", message);
    log_event("Greeting printed."); /* Log the greeting. */
  
    log_event("Program finished."); /* Log the end of the program. */
    return 0;
}