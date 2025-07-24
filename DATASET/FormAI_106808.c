//FormAI DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event, char *location, char *status);
void print_log();

int main() {
    char *event_list[] = {"Battle", "Feast", "Jousting Tournament", "Royal Wedding"};
    char *location_list[] = {"Castle", "Village", "Forest", "River"};
    char *status_list[] = {"Successful", "Failed", "Postponed", "Cancelled"};
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int rand_event_index = rand() % 4;
        int rand_location_index = rand() % 4;
        int rand_status_index = rand() % 4;
        log_event(event_list[rand_event_index], location_list[rand_location_index], 
                  status_list[rand_status_index]);
    }
    print_log();
    return 0;
}

void log_event(char *event, char *location, char *status) {
    FILE *fp = fopen("log.txt", "a");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    time_t timestamp;
    time(&timestamp);
    fprintf(fp, "[%s] %s took place at %s and it was %s.\n", asctime(localtime(&timestamp)), 
            event, location, status);
    fclose(fp);
}

void print_log() {
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    fclose(fp);
}