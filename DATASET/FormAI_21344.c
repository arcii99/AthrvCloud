//FormAI DATASET v1.0 Category: Browser Plugin ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// define constants
#define MAX_URL_LENGTH 100
#define MAX_HISTORY_ENTRIES 100

// define struct to store url history
struct history_entry {
    char url[MAX_URL_LENGTH];
    bool visited;
};

// global variables
int num_history_entries = 0;
struct history_entry history[MAX_HISTORY_ENTRIES];

// function prototypes
void add_history_entry(char url[]);
void print_history();
bool is_visited(char url[]);
void browse(char url[]);

// add a new entry to the history list
void add_history_entry(char url[]) {
    if (num_history_entries < MAX_HISTORY_ENTRIES) {
        strcpy(history[num_history_entries].url, url);
        history[num_history_entries].visited = true;
        num_history_entries++;
    } else {
        printf("Maximum history entries reached!\n");
    }
}

// print the history list
void print_history() {
    printf("Browsing history:\n");
    for (int i = 0; i < num_history_entries; i++) {
        printf("%s\n", history[i].url);
    }
}

// check if a given url has been visited before
bool is_visited(char url[]) {
    for (int i = 0; i < num_history_entries; i++) {
        if (strcmp(url, history[i].url) == 0) {
            return history[i].visited;
        }
    }
    return false;
}

// simulate browsing to a new url
void browse(char url[]) {
    // check if the url has been visited before
    if (is_visited(url)) {
        printf("Page already visited!\n");
    } else {
        // add the url to the history
        add_history_entry(url);
        printf("Browsing %s...\n", url);
    }
}

// main function
int main() {
    char input[MAX_URL_LENGTH];

    printf("Welcome to MyBrowser!\n");

    // loop until user quits
    while (true) {
        printf("\nEnter a URL (q to quit, h for history): ");
        fgets(input, MAX_URL_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline

        if (strcmp(input, "q") == 0) {
            break;
        } else if (strcmp(input, "h") == 0) {
            print_history();
        } else {
            browse(input);
        }
    }

    printf("\nGoodbye!\n");

    return 0;
}