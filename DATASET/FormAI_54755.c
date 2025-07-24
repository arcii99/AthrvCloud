//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 20
#define MAX_SIGNAL_STRENGTH 100

typedef struct access_point {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
    struct access_point* next;
} AccessPoint;

AccessPoint* head = NULL;
AccessPoint* tail = NULL;

int num_access_points = 0;

void add_access_point(char* ssid, int signal_strength) {
    AccessPoint* new_ap = malloc(sizeof(AccessPoint));
    if (new_ap == NULL) {
        printf("Error: Unable to allocate memory\n");
        return;
    }
    strncpy(new_ap->ssid, ssid, MAX_SSID_LENGTH);
    new_ap->signal_strength = signal_strength;
    new_ap->next = NULL;
    if (head == NULL) {
        head = new_ap;
        tail = new_ap;
    } else {
        tail->next = new_ap;
        tail = new_ap;
    }
    num_access_points++;
}

void print_access_points() {
    AccessPoint* current = head;
    while (current != NULL) {
        printf("SSID: %s, Signal Strength: %d\n", current->ssid, current->signal_strength);
        current = current->next;
    }
}

void clear_access_points() {
    AccessPoint* current = head;
    while (current != NULL) {
        AccessPoint* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    tail = NULL;
    num_access_points = 0;
}

int main() {
    while (1) {
        clear_access_points();
        printf("Scanning for Wi-Fi networks...\n");
        // Code for scanning Wi-Fi networks goes here
        // For the purpose of this example, we'll generate and add 3 random access points
        add_access_point("ExampleNetwork1", rand() % MAX_SIGNAL_STRENGTH + 1);
        add_access_point("ExampleNetwork2", rand() % MAX_SIGNAL_STRENGTH + 1);
        add_access_point("ExampleNetwork3", rand() % MAX_SIGNAL_STRENGTH + 1);
        printf("%d Wi-Fi networks found:\n", num_access_points);
        print_access_points();
        sleep(5); // Sleep for 5 seconds before scanning again
    }
    return 0;
}