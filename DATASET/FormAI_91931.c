//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 10
#define DEFAULT_WEIGHT 100

typedef struct {
    int size;
    int weight;
} Item;

int main(int argc, char **argv) {
    srand(time(NULL));
    int size, weight, i, total_weight = 0, total_size = 0;
    if (argc > 1) {
        size = atoi(argv[1]);
        weight = atoi(argv[2]);
    } else {
        size = DEFAULT_SIZE;
        weight = DEFAULT_WEIGHT;
    }
    Item *items = malloc(sizeof(Item) * size);
    for (i = 0; i < size; i++) {
        items[i].size = rand() % size + 1;
        items[i].weight = rand() % weight + 1;
        total_size += items[i].size;
        total_weight += items[i].weight;
    }
    printf("Total size: %d, Total weight: %d\n", total_size, total_weight);
    free(items);
    return 0;
}