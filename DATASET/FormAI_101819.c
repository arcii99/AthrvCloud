//FormAI DATASET v1.0 Category: Browser Plugin ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define MAX_URL_LENGTH 1000
#define MAX_HISTORY_ENTRIES 100
#define MAX_BACKWARD_ENTRIES 10

typedef struct url_entry_ {
    char url[MAX_URL_LENGTH];
    time_t timestamp;
} url_entry;

typedef struct browser_history_ {
    url_entry history[MAX_HISTORY_ENTRIES];
    int history_count;
} browser_history;

typedef struct browser_back_ {
    url_entry backward[MAX_BACKWARD_ENTRIES];
    int backward_count;
} browser_back;

void add_to_history(browser_history* history, char* url) {
    // Move all history one index back
    for (int i = history->history_count - 1; i >= 0; --i) {
        strcpy(history->history[i+1].url, history->history[i].url);
        history->history[i+1].timestamp = history->history[i].timestamp;
    }

    // Add new URL to history
    strcpy(history->history[0].url, url);
    history->history[0].timestamp = time(NULL);
    history->history_count++;
}

bool go_back(browser_history* history, browser_back* back) {
    if (history->history_count == 0) {
        return false;
    }

    // Move last element of history to backward
    strcpy(back->backward[back->backward_count].url, history->history[0].url);
    back->backward[back->backward_count].timestamp = history->history[0].timestamp;
    back->backward_count++;

    // Move all history one index front
    for (int i = 0; i < history->history_count-1; ++i) {
        strcpy(history->history[i].url, history->history[i+1].url);
        history->history[i].timestamp = history->history[i+1].timestamp;
    }

    history->history_count--;
    return true;
}

void print_history(browser_history* history) {
    if (history->history_count == 0) {
        printf("History is empty.\n");
        return;
    }

    printf("Browsing History:\n");
    for (int i = 0; i < history->history_count; ++i) {
        printf("%s - %s", history->history[i].url, ctime(&history->history[i].timestamp));
    }
}

void print_backwards(browser_back* back) {
    if (back->backward_count == 0) {
        printf("No history to go back to.\n");
        return;
    }

    printf("Going backwards...\n");
    printf("%s - %s", back->backward[0].url, ctime(&back->backward[0].timestamp));

    // Move all backward one index front
    for (int i = 0; i < back->backward_count-1; ++i) {
        strcpy(back->backward[i].url, back->backward[i+1].url);
        back->backward[i].timestamp = back->backward[i+1].timestamp;
    }

    back->backward_count--;
}

int main() {
    browser_history history = {0};
    browser_back back = {0};

    // Simulating browsing
    char url1[] = "https://www.google.com";
    char url2[] = "https://github.com";
    char url3[] = "https://stackoverflow.com";
    char url4[] = "https://en.wikipedia.org";

    printf("Opening URL: %s\n", url1);
    add_to_history(&history, url1);
    sleep(1);

    printf("Opening URL: %s\n", url2);
    add_to_history(&history, url2);
    sleep(1);

    printf("Going back...\n");
    go_back(&history, &back);
    sleep(1);

    printf("Going back...\n");
    go_back(&history, &back);
    sleep(1);

    printf("Opening URL: %s\n", url3);
    add_to_history(&history, url3);
    sleep(1);

    printf("Going back...\n");
    go_back(&history, &back);
    sleep(1);

    printf("Opening URL: %s\n", url4);
    add_to_history(&history, url4);
    sleep(1);

    printf("Browsing completed.\n");
    print_history(&history);

    printf("\n");

    printf("Going back...\n");
    print_backwards(&back);
    printf("\n");

    printf("Going back...\n");
    print_backwards(&back);
    printf("\n");

    printf("Going back...\n");
    print_backwards(&back);
    printf("\n");

    return 0;
}