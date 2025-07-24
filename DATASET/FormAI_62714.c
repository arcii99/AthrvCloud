//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>

int main() {

    printf("Welcome to the Mind-Bending Greedy Algorithm program!\n");
    printf("Enter the number of elements in your input array:\n");

    int num_elements;
    scanf("%d", &num_elements);

    int array[num_elements];
    printf("Enter the elements of your array, separated by spaces:\n");

    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &array[i]);
    }

    printf("Your input array is: [");
    for (int i = 0; i < num_elements; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");

    int max_profit = 0;
    int current_min = array[0];

    for (int i = 1; i < num_elements; i++) {
        if (array[i] < current_min) {
            current_min = array[i];
        }
        else if (array[i] - current_min > max_profit) {
            max_profit = array[i] - current_min;
        }
    }

    printf("The maximum profit that can be obtained from buying and selling stocks in this array is: %d\n", max_profit);

    return 0;
}