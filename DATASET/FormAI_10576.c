//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <time.h>

#define MAX_BAGGAGE 50
#define MAX_SCANNERS 5

typedef struct {
    int id;
    int scanned;
} Baggage;

typedef struct {
    int id;
    int available;
} Scanner;

void scan_baggage(Baggage *baggage) {
    int random = rand() % 100;
    if (random < 10) {
        printf("Scanner malfunction detected! Baggage #%d needs to be inspected manually.\n", baggage->id);
        baggage->scanned = 0;
    } else {
        printf("Baggage #%d successfully scanned.\n", baggage->id);
        baggage->scanned = 1;
    }
}

int main() {
    int num_bags = 0;
    Baggage baggage_list[MAX_BAGGAGE];
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        baggage_list[i].id = i + 1;
        baggage_list[i].scanned = 0;
    }

    Scanner scanner_list[MAX_SCANNERS];
    for (int i = 0; i < MAX_SCANNERS; i++) {
        scanner_list[i].id = i + 1;
        scanner_list[i].available = 1;
    }

    srand(time(NULL));

    // Introduce some chaos
    int random = rand() % 10;
    if (random == 0) {
        printf("Warning: Security threat detected! Baggage handling systems may be compromised.\n");
    }

    // Scan baggage
    printf("Scanning %d bags...\n", MAX_BAGGAGE);
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        for (int j = 0; j < MAX_SCANNERS; j++) {
            if (baggage_list[i].scanned == 0 && scanner_list[j].available == 1) {
                scanner_list[j].available = 0;
                printf("Baggage #%d is being scanned by Scanner #%d...\n", baggage_list[i].id, scanner_list[j].id);
                scan_baggage(&baggage_list[i]);
                scanner_list[j].available = 1;
            }
        }
    }

    // Check for missed baggage
    int missed = 0;
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        if (baggage_list[i].scanned == 0) {
            missed++;
        }
    }

    // Introduce some more chaos
    random = rand() % 10;
    if (random == 0) {
        printf("Warning: Compromised baggage detected on conveyor belt!\n");
    }

    // Display results
    printf("Scan complete. %d bags successfully scanned. %d bags missed.\n", MAX_BAGGAGE - missed, missed);

    return 0;
}