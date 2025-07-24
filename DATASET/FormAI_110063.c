//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAX_URL_LENGTH 100
#define MAX_HISTORY_SIZE 10

typedef struct {
    char url[MAX_URL_LENGTH];
    bool is_up;
    time_t last_checked;
} Site;

void check_site(Site *site) {
    // simulate website check
    int random_num = rand() % 2;
    site->is_up = random_num == 0 ? false : true;
    site->last_checked = time(NULL);
}

void print_status(Site *site) {
    char status[10];
    if (site->is_up) {
        strcpy(status, "UP");
    } else {
        strcpy(status, "DOWN");
    }
    printf("%s: %s | Last Checked: %s", site->url, status, ctime(&(site->last_checked)));
}

void add_to_history(Site *site, Site history[], int *history_size) {
    // remove oldest site from history
    if (*history_size == MAX_HISTORY_SIZE) {
        for (int i = 1; i < MAX_HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        (*history_size)--;
    }

    // add site to history
    history[*history_size] = *site;
    (*history_size)++;
}

void print_history(Site history[], int history_size) {
    printf("\n\n-------HISTORY-------\n");
    for (int i = 0; i < history_size; i++) {
        printf("%d) %s | ", i+1, history[i].url);
        print_status(&history[i]);
    }
}

int main() {
    Site sites[3] = {
        {"https://www.google.com", true, time(NULL)},
        {"https://www.yahoo.com", true, time(NULL)},
        {"https://www.amazon.com", true, time(NULL)}
    };
    Site history[MAX_HISTORY_SIZE];
    int history_size = 0;

    while (true) {
        for (int i = 0; i < 3; i++) {
            check_site(&sites[i]);
            print_status(&sites[i]);
            add_to_history(&sites[i], history, &history_size);
        }

        print_history(history, history_size);

        // pause for 5 seconds before checking again
        printf("\n\n------------------------\n\n");
        sleep(5);
    }
    return 0;
}