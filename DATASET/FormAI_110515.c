//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Bag {
    int id;
    char owner[20];
    char status[20];
};

void printBag(struct Bag b) {
    printf("BAG #%d\n", b.id);
    printf("Owner: %s\n", b.owner);
    printf("Status: %s\n\n", b.status);
}

int main() {
    srand(time(NULL));
    
    // Create 100 bags with random owners and statuses
    struct Bag bags[100];
    for (int i = 0; i < 100; i++) {
        bags[i].id = i+1;
        char owners[5][20] = {"John", "Jane", "Bob", "Alice", "Mike"};
        strcpy(bags[i].owner, owners[rand() % 5]);
        char statuses[5][20] = {"waiting", "on conveyor", "in truck", "delivered", "lost"};
        strcpy(bags[i].status, statuses[rand() % 5]);
    }
    
    // Print all bags
    for (int i = 0; i < 100; i++) {
        printBag(bags[i]);
    }
    
    // Simulate the baggage handling process
    printf("Starting baggage handling simulation...\n\n");
    
    // Load bags onto conveyor
    for (int i = 0; i < 100; i++) {
        if (strcmp(bags[i].status, "waiting") == 0) {
            strcpy(bags[i].status, "on conveyor");
            printBag(bags[i]);
        }
    }

    // Move bags through security
    for (int i = 0; i < 100; i++) {
        if (strcmp(bags[i].status, "on conveyor") == 0) {
            int security_check = rand() % 10;
            if (security_check < 8) {
                strcpy(bags[i].status, "in truck");
            } else {
                strcpy(bags[i].status, "lost");
            }
            printBag(bags[i]);
        }
    }
    
    // Deliver bags
    for (int i = 0; i < 100; i++) {
        if (strcmp(bags[i].status, "in truck") == 0) {
            int delivery_check = rand() % 10;
            if (delivery_check < 7) {
                strcpy(bags[i].status, "delivered");
            } else {
                strcpy(bags[i].status, "lost");
            }
            printBag(bags[i]);
        }
    }
    
    printf("Baggage handling simulation complete.\n");

    return 0;
}