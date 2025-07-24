//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10
#define MAX_LOADERS 5

int baggage_count = 0;

typedef struct Baggage {
    int id;
    int weight;
    char flight[5];
} Baggage;

typedef struct Loader {
    int id;
    bool available;
} Loader;

Loader loaders[MAX_LOADERS];

void initialize_loaders() {
    for (int i = 0; i < MAX_LOADERS; i++) {
        loaders[i].id = i + 1;
        loaders[i].available = true;
    }
}

void print_baggage(Baggage *baggage) {
    printf("Baggage ID: %d, Weight: %d, Flight: %s\n",
           baggage->id, baggage->weight, baggage->flight);
}

void load_baggage(Baggage *baggage) {
    for (int i = 0; i < MAX_LOADERS; i++) {
        if (loaders[i].available) {
            printf("Loader %d is loading baggage...\n", loaders[i].id);
            print_baggage(baggage);
            loaders[i].available = false;
            printf("Loader %d has finished loading baggage.\n", loaders[i].id);
            break;
        }
    }
}

bool is_baggage_allowed(char *flight) {
    // Only allow baggage on flights with numbers between 100 and 999
    int flight_number = atoi(flight);
    return (flight_number >= 100 && flight_number <= 999);
}

void generate_baggage() {
    int weight, flight_num;
    char flight[5];
    Baggage *baggage;

    printf("Enter baggage weight: ");
    scanf("%d", &weight);

    printf("Enter flight number: ");
    scanf("%s", &flight);

    if (is_baggage_allowed(flight)) {
        baggage = malloc(sizeof(Baggage));
        baggage->id = ++baggage_count;
        baggage->weight = weight;
        strcpy(baggage->flight, flight);
        load_baggage(baggage);
    } else {
        printf("Baggage not allowed on flight %s.\n", flight);
    }
}

int main() {
    initialize_loaders();

    srand(time(NULL));
    int flights[MAX_FLIGHTS];

    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = rand() % 900 + 100;
    }

    while (true) {
        printf("\n");
        printf("*** Main Menu ***\n");
        printf("1. Generate Baggage\n");
        printf("2. Quit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_baggage();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}