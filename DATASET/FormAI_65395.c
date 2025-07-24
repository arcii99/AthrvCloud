//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void log_event(char *message) {
    FILE *fp;
    time_t current_time;

    char* c_time_string;

    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    // remove new line character from time string
    c_time_string[strlen(c_time_string) - 1] = '\0';

    fp = fopen("system.log", "a");

    if(fp == NULL) {
        printf("Error: Unable to open log file!\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "[%s] Event: %s\n", c_time_string, message);
    fclose(fp);
}

int main() {

    log_event("System started");

    // main program

    log_event("System shutdown");

    return 0;
}