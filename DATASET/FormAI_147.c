//FormAI DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 1000000

typedef struct {
    int id;
    int value;
} item_t;

int main() {
    int i;
    item_t *items = malloc(NUM_ITEMS * sizeof(item_t));

    // Populate items array with random values
    srand(time(NULL));
    for (i = 0; i < NUM_ITEMS; i++) {
        items[i].id = i;
        items[i].value = rand() % 100;
    }

    // Find the item with the highest value
    item_t max_item = items[0];
    for (i = 1; i < NUM_ITEMS; i++) {
        if (items[i].value > max_item.value) {
            max_item = items[i];
        }
    }

    printf("Item with highest value: ID=%d, Value=%d\n", max_item.id, max_item.value);

    free(items);

    return 0;
}