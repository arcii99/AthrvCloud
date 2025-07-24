//FormAI DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Struct to hold the event information
typedef struct {
    char *message;
    time_t timestamp;
} Event;

// node structure for linked list
typedef struct ListNode {
    Event event;
    struct ListNode *next;
} ListNode;

// global variables
static bool is_running = false;
static ListNode *list_head = NULL;
static ListNode *list_tail = NULL;

// function to add an event to the linked list
void add_event(char *message) {
    Event event;
    event.message = message;
    event.timestamp = time(NULL);

    ListNode *new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->event = event;
    new_node->next = NULL;

    // if the list is currently empty, set the head and tail
    if (list_head == NULL) {
        list_head = new_node;
        list_tail = new_node;
    } else { // otherwise, add to the end of the list
        list_tail->next = new_node;
        list_tail = new_node;
    }
}

// function to print out all events in the linked list
void print_events() {
    ListNode *current_node = list_head;
    int count = 0;

    while (current_node != NULL) {
        printf("%d. [%ld] %s\n", count++, current_node->event.timestamp, current_node->event.message);

        current_node = current_node->next;
    }
}

// asynchronous event logger function
void* event_logger(void *args) {
    is_running = true;

    // keep logging events until program is stopped
    while (is_running) {
        char message[100];
        printf("\nEnter an event message (or 'exit' to stop the program): ");
        scanf("%99[^\n]", message);
        getchar(); // clear input buffer

        if (strcmp(message, "exit") == 0) {
            is_running = false;
            break;
        }

        add_event(message);
    }

    // print out all events before exiting
    print_events();

    pthread_exit(NULL);
}

// main function to run the program
int main(void) {
    pthread_t logger_thread;

    printf("Starting event logger program...\n");

    pthread_create(&logger_thread, NULL, event_logger, NULL);
    pthread_join(logger_thread, NULL);

    printf("Exiting event logger program.\n");

    return 0;
}