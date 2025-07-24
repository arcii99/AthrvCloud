//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>

int main() {

    int num_items, capacity;
    printf("Enter the number of items and capacity of the knapsack: ");
    scanf("%d %d", &num_items, &capacity);

    int weight[num_items], value[num_items];
    printf("Enter the weight and values of each item:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    float value_per_unit[num_items];
    for (int i = 0; i < num_items; i++) {
        value_per_unit[i] = (float) value[i] / (float) weight[i];
    }

    float max_value = 0;
    int current_weight = 0;
    while (current_weight < capacity) {
        int item_index;
        float max_value_per_unit = 0;
        for (int i = 0; i < num_items; i++) {
            if (value_per_unit[i] > max_value_per_unit && weight[i] <= capacity-current_weight) {
                max_value_per_unit = value_per_unit[i];
                item_index = i;
            }
        }

        if (max_value_per_unit == 0) {
            break;
        }

        float item_weight = weight[item_index];
        float item_value = value[item_index];
        current_weight += item_weight;
        max_value += item_value;
        value_per_unit[item_index] = 0;
    }

    printf("The maximum value that can be carried in the knapsack is: %.2f\n", max_value);

    return 0;
}