//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WAIT_TIME 30

typedef struct {
    int id;
    int weight;
} Bag;

void receive_bags(Bag *bags, int *num_bags) {
    int i, num;
    srand(time(NULL));
    num = rand() % MAX_BAGS + 1;
    for (i = 0; i < num; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % 50 + 1;
    }
    *num_bags = num;
}

void print_bags(Bag *bags, int num_bags) {
    int i;
    printf("Received %d bags:\n", num_bags);
    for (i = 0; i < num_bags; i++)
        printf("Bag %d: Weight %d\n", bags[i].id, bags[i].weight);
}

void sort_bags(Bag *bags, int num_bags) {
    int i, j;
    Bag tmp;
    for (i = 0; i < num_bags-1; i++) {
        for (j = i+1; j < num_bags; j++) {
            if (bags[j].weight > bags[i].weight) {
                tmp = bags[i];
                bags[i] = bags[j];
                bags[j] = tmp;
            }
        }
    }
}

void load_bags(Bag *bags, int num_bags) {
    int i;
    printf("Loading %d bags:\n", num_bags);
    for (i = 0; i < num_bags; i++)
        printf("Bag %d loaded\n", bags[i].id);
}

int main() {
    Bag bags[MAX_BAGS];
    int num_bags = 0;
    receive_bags(bags, &num_bags);
    print_bags(bags, num_bags);
    sort_bags(bags, num_bags);
    load_bags(bags, num_bags);
    printf("Simulation complete.\n");
    return 0;
}