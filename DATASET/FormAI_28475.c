//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 100   // maximum number of baggage
#define MAX_TROLLEYS 10   // maximum number of trolleys

// structure for baggage
struct Baggage {
    int id;
    int weight;  
};

// structure for trolley
struct Trolley {
    int id;
    int capacity;
    int count;
    int current_weight;
    struct Baggage *contents[MAX_BAGGAGE];
};

// function to generate random baggage
void generate_baggage(struct Baggage *baggage) {
    baggage->id = rand() % 1000;
    baggage->weight = (rand() % 20) + 5;  // weight between 5 and 25 kg
}

int main() {
    // initialize trolleys
    struct Trolley trolleys[MAX_TROLLEYS];
    for (int i = 0; i < MAX_TROLLEYS; i++) {
        trolleys[i].id = i;
        trolleys[i].capacity = (rand() % 5) + 10;  // capacity between 10 and 14 bags
        trolleys[i].count = 0;
        trolleys[i].current_weight = 0;
    }

    // generate baggage and assign to trolleys
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        struct Baggage baggage;
        generate_baggage(&baggage);
        int trolley_index = 0;
        for (int j = 1; j < MAX_TROLLEYS; j++) {
            if (trolleys[j].count < trolleys[trolley_index].count) {
                trolley_index = j;
            }
        }
        if (trolleys[trolley_index].current_weight + baggage.weight <= trolleys[trolley_index].capacity) {
            trolleys[trolley_index].contents[trolleys[trolley_index].count] = &baggage;
            trolleys[trolley_index].count++;
            trolleys[trolley_index].current_weight += baggage.weight;
        }
    }

    // print out trolley contents
    for (int i = 0; i < MAX_TROLLEYS; i++) {
        printf("Trolley %d:\n", trolleys[i].id);
        for (int j = 0; j < trolleys[i].count; j++) {
            printf("  Baggage %d (Weight: %d kg)\n", trolleys[i].contents[j]->id, trolleys[i].contents[j]->weight);
        }
        printf("  Total Bags: %d, Total Weight: %d kg\n", trolleys[i].count, trolleys[i].current_weight);
    }

    return 0;
}