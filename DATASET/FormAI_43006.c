//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%d-%02d-%02d %02d:%02d:%02d - %s\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec, event);
}

int main() {
    printf("Welcome to the event logger!\n");
    printf("To log an event, please enter its description.\n");
    printf("To exit the program, type 'quit'.\n");

    char input[100];

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            break;
        }

        logEvent(input);
    }

    return 0;
}