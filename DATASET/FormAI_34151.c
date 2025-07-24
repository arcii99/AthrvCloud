//FormAI DATASET v1.0 Category: System event logger ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(int level, char * message);

int main( int argc, char *argv[] ) {
    srand(time(NULL));
    int level = rand() % 4;
    char * message = argv[1];
    log_event(level, message);
    return 0;
}

void log_event(int level, char * message) {
    FILE * fp;
    fp = fopen ("event.log", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);

    switch(level) {
        case 0:
            fprintf(fp, "INFO [%s] %s\n", s, message);
            printf("Event logged: INFO\n");
            break;
        case 1:
            fprintf(fp, "DEBUG [%s] %s\n", s, message);
            printf("Event logged: DEBUG\n");
            break;
        case 2:
            fprintf(fp, "WARNING [%s] %s\n", s, message);
            printf("Event logged: WARNING\n");
            break;
        case 3:
            fprintf(fp, "ERROR [%s] %s\n", s, message);
            printf("Event logged: ERROR\n");
            break;
        default:
            fprintf(fp, "LOG [%s] %s\n", s, message);
            printf("Event logged\n");
            break;
    }

    fclose(fp);
}