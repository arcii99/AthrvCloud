//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGGAGE 50
#define MAX_BELTS 4

typedef struct {
    int id;
    int weight;
    int destination_belt;
} Baggage;

typedef struct {
    Baggage* bags[MAX_BAGGAGE];
    int num_bags;
} Belt;

typedef struct {
    int id;
    Belt belts[MAX_BELTS];
} Terminal;

void initialize_terminal(Terminal* terminal) {
    terminal->id = rand() % 1000 + 1000;

    for (int i = 0; i < MAX_BELTS; i++) {
        terminal->belts[i].num_bags = 0;
    }
}

void generate_baggage(Baggage* baggage) {
    baggage->id = rand() % 100 + 1;
    baggage->weight = rand() % 50 + 1;
    baggage->destination_belt = rand() % MAX_BELTS;
}

void print_baggage(Baggage* baggage) {
    printf("Baggage ID: %d | Weight: %d | Destination Belt: %d\n", baggage->id, baggage->weight, baggage->destination_belt);
}

void add_baggage_to_belt(Baggage* baggage, Belt* belt) {
    if (belt->num_bags < MAX_BAGGAGE) {
        belt->bags[belt->num_bags] = baggage;
        belt->num_bags++;
    }
}

Baggage* remove_baggage_from_belt(Belt* belt) {
    if (belt->num_bags > 0) {
        Baggage* removed_baggage = belt->bags[0];
        for (int i = 0; i < belt->num_bags - 1; i++) {
            belt->bags[i] = belt->bags[i + 1];
        }
        belt->num_bags--;
        return removed_baggage;
    }
    else {
        return NULL;
    }
}

void print_belt(Belt* belt) {
    printf("Belt Contents:\n");
    for (int i = 0; i < belt->num_bags; i++) {
        print_baggage(belt->bags[i]);
    }
}

void simulate(Terminal* terminal) {
    int num_iterations = rand() % 10 + 1;

    for (int i = 0; i < num_iterations; i++) {
        printf("Iteration %d\n", i + 1);

        Belt* source_belt = &terminal->belts[rand() % MAX_BELTS];
        Belt* destination_belt = &terminal->belts[rand() % MAX_BELTS];

        while (source_belt == destination_belt) {
            destination_belt = &terminal->belts[rand() % MAX_BELTS];
        }

        Baggage baggage;
        generate_baggage(&baggage);

        printf("Generated New Baggage:\n");
        print_baggage(&baggage);

        add_baggage_to_belt(&baggage, source_belt);

        printf("Source Belt (%d) Contents:\n", source_belt - terminal->belts);
        print_belt(source_belt);

        printf("Destination Belt (%d) Contents:\n", destination_belt - terminal->belts);
        print_belt(destination_belt);

        Baggage* removed_baggage = remove_baggage_from_belt(source_belt);

        if (removed_baggage != NULL) {
            removed_baggage->destination_belt = destination_belt - terminal->belts;
            add_baggage_to_belt(removed_baggage, destination_belt);
        }

        printf("Source Belt (%d) Contents After Removal:\n", source_belt - terminal->belts);
        print_belt(source_belt);

        printf("Destination Belt (%d) Contents After Addition:\n", destination_belt - terminal->belts);
        print_belt(destination_belt);
    }
}

int main() {
    Terminal terminal;
    initialize_terminal(&terminal);

    printf("Airport Terminal Simulation\n");
    printf("Terminal ID: %d\n", terminal.id);

    for (int i = 0; i < MAX_BELTS; i++) {
        printf("Initializing Belt %d\n", i);
    }

    simulate(&terminal);

    return 0;
}