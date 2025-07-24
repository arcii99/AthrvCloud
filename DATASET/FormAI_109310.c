//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_CAPACITY 10

typedef struct {
    int id;
    int weight;
} Baggage;

void generate_bags(Baggage bags[], int num_bags) {
    srand(time(NULL));
    for (int i = 0; i < num_bags; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % 50 + 1;
    }
}

void print_bags(Baggage bags[], int num_bags) {
    printf("\nBags:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("Bag %d: %d kg\n", bags[i].id, bags[i].weight);
    }
}

void load_luggage(Baggage bags[], int num_bags, int max_capacity) {
    int total_weight = 0;
    int weight_on_belt = 0;
    for (int i = 0; i < num_bags; i++) {
        total_weight += bags[i].weight;
        if (total_weight <= max_capacity) {
            weight_on_belt += bags[i].weight;
            printf("Bag %d (weight %d kg) loaded on the belt.\n", bags[i].id, bags[i].weight);
        }
        else {
            printf("Belt is full. Wait for bags to be loaded on the plane.\n");
            break;
        }
    }
    printf("Total weight on belt: %d kg\n", weight_on_belt);
}

int main() {
    Baggage bags[MAX_BAGS];
    int num_bags = 25;
    int max_capacity = 200;
    generate_bags(bags, num_bags);
    print_bags(bags, num_bags);
    load_luggage(bags, num_bags, max_capacity);
    return 0;
}